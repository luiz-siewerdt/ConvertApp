#ifndef CONVERT_UTILS_H
#define CONVERT_UTILS_H

#include <filesystem>
#include <string>
#include <unordered_map>

using namespace std;

namespace Convert {

struct PathAttrs {
  string &extension;
  string &filename;
};

extern const filesystem::path default_file_folder;

void replace_filename(string &filename, const string &new_filename);

void get_paths_historic();

void update_paths_historic(const string &historic);

PathAttrs valid_path(const filesystem::path &path,
                     const unordered_map<size_t, string> &extension_map);

} // namespace Convert

#endif // CONVERT_UTILS_H
