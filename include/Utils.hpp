#ifndef CONVERT_UTILS_H
#define CONVERT_UTILS_H

#include <filesystem>
#include <string>
#include <vector>

using namespace std;

namespace Convert {

struct PathAttrs {
  string extension;
  string filename;
};

extern const filesystem::path default_file_folder;

void replace_filename(string &filename, const string &new_filename);

void get_paths_historic();

void update_paths_historic(const string &path_file, const string &extension);

PathAttrs valid_path(const filesystem::path &path,
                     const vector<string> &extension_map);

} // namespace Convert

#endif // CONVERT_UTILS_H
