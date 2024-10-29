#ifndef IMAGE_CONVERT_H
#define IMAGE_CONVERT_H

#include <string>
#include <vector>
using namespace std;

namespace Convert {
extern const vector<string> image_extensions;

bool convertImage(const string &image_path_string, const string &new_extension);

} // namespace Convert

#endif // !IMAGE_CONVERT_H
