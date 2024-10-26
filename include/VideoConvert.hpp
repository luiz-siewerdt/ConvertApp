#ifndef VIDEO_CONVERT_H
#define VIDEO_CONVERT_H

#include <string>
#include <unordered_map>
using namespace std;
namespace Convert {

extern const std::unordered_map<size_t, std::string> video_extensions;
bool convertVideo(const string &video_path, const string &new_extension);

} // namespace Convert

#endif // !VIDEO_CONVERT_H
