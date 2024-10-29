#include "ImageConvert.hpp"
#include "Utils.hpp"
#include "VideoConvert.hpp"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  string file_path;
  size_t extension_id = 100;
  size_t extension_type;
  string new_extension;
  const vector<string> *extension_map;

  if (argc < 2) {
    cerr << "Pass the path arg" << '\n';
    return 1;
  }

  file_path = argv[1];

  stringstream sbuilder;

  while (extension_type != 1 && extension_type != 2) {
    cout << "Qual tipo de arquivo você vai querer converter?" << '\n'
         << "1.Imagem" << '\n'
         << "2.Video" << '\n'
         << "3.Historic" << '\n';
    cin >> extension_type;

    if (extension_type == 3) {
      cout << '\n';
      Convert::get_paths_historic();
      cout << '\n';
    }
  }

  extension_map = extension_type == 1 ? &Convert::image_extensions
                                      : &Convert::video_extensions;

  sbuilder << "Para qual tipo de extensão irá converter?" << '\n';
  for (size_t i{0}; i <= extension_map->size() - 1; ++i) {
    sbuilder << i + 1 << "." << extension_map->at(i) << '\n';
  }

  while (extension_id <= 0 || extension_id > extension_map->size()) {
    cout << sbuilder.str() << '\n';
    cin >> extension_id;
    cout << extension_id << '\n';
  }

  extension_id = extension_id - 1;

  new_extension = extension_map->at(extension_id);

  bool allRight = extension_type == 1
                      ? Convert::convertImage(file_path, new_extension)
                      : Convert::convertVideo(file_path, new_extension);

  if (allRight) {
    Convert::update_paths_historic(file_path, new_extension);
    return 0;
  }

  return 1;
}
