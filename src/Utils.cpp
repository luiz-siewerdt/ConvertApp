#include "Utils.hpp"
#include "exceptions/InvalidExtensionException.hpp"
#include "exceptions/InvalidFileException.hpp"
#include "exceptions/InvalidPathException.hpp"
#include <algorithm>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
namespace Convert {

const filesystem::path default_file_folder{
    filesystem::current_path().parent_path() / "tmp"};

void replace_filename(string &filename, const string &new_filename) {
  // cout << filename << " - " << new_filename << '\n';
  size_t extension_start_position = filename.find_last_of('.') + 1;
  filename.replace(filename.begin() + extension_start_position,
                   new_filename.end() - new_filename.length() - 1,
                   new_filename);
  cout << filename << '\n';
}

void get_paths_historic() {
  ifstream input_file("historic.txt");
  stringstream buffer;
  if (!input_file) {
    input_file.close();

    ofstream output_file("historic.txt");
    if (!output_file) {
      cerr << "Failed to create the file" << '\n';
      output_file.close();
      return;
    }
    cout << "Is empty" << '\n';
    return;
  }
  buffer << input_file.rdbuf();

  string line;
  cout << "Historic: " << '\n';
  while (getline(buffer, line)) {
    cout << line << '\n';
  }

  input_file.close();
}

void update_paths_historic(const string &path_file, const string &extension) {
  ofstream output_file("historic.txt");
  if (!output_file) {
    cerr << "Failed to create the file" << '\n';
    return;
  }
  time_t timestamp = time(NULL);
  struct tm datetime = *localtime(&timestamp);
  char output[50];

  strftime(output, 50, "%d-%m-%G %X", &datetime);

  output_file << output << " - " << path_file << " -> " << extension << '\n';

  output_file.close();
}

PathAttrs valid_path(const filesystem::path &path,
                     const vector<string> &extensions) {
  string path_string{path.string()};

  if (!path.has_filename() || !path.has_extension()) {
    throw InvalidFileException(path_string);
  }
  if (!filesystem::exists(path)) {
    throw InvalidPathException(path_string);
  }

  string extension{path.extension().string().substr(1)};
  string filename = path.filename();

  auto it{find_if(extensions.begin(), extensions.end(),
                  [extension](const string &ex) { return ex == extension; })};

  if (it == extensions.end()) {
    throw InvalidExtensionException(extension);
  }

  PathAttrs path_attr{extension, filename};
  return path_attr;
}
} // namespace Convert
