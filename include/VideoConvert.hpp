#ifndef VIDEO_CONVERT_H
#define VIDEO_CONVERT_H

#include <string>
#include <vector>
using namespace std;
namespace Convert {

extern const vector<string> video_extensions;
bool convertVideo(const string &video_path, const string &new_extension);

} // namespace Convert

#endif // !VIDEO_CONVERT_H
