#include "VideoConvert.hpp"
#include "Utils.hpp"
#include <exception>
#include <filesystem>
#include <iostream>
#include <opencv2/core/types.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <vector>

using namespace std;
using namespace cv;
using namespace Convert;
namespace fs = std::filesystem;

namespace Convert {
const vector<string> video_extensions{"mp4", "avi", "webm", "mkv", "wmv"};

bool convertVideo(const string &video_path_string,
                  const string &new_extension) {
  try {
    fs::path videos_path_folder{default_file_folder / "videos"};
    fs::path video_path{fs::absolute(video_path_string)};

    PathAttrs path_attrs{valid_path(video_path, video_extensions)};

    string file_extension = video_path.extension().string().replace(0, 1, "");

    int codec = file_extension == "webm"
                    ? VideoWriter::fourcc('V', 'P', '8', '0')
                    : VideoWriter::fourcc('H', '2', '6', '4');

    VideoCapture inputVideo(video_path.string());
    if (!inputVideo.isOpened()) {
      cerr << "Error: could not open input video file" << '\n';
      return false;
    }

    int frameWidth{static_cast<int>(inputVideo.get(CAP_PROP_FRAME_WIDTH))};
    int frameHeight{static_cast<int>(inputVideo.get(CAP_PROP_FRAME_HEIGHT))};
    double fps{inputVideo.get(CAP_PROP_FPS)};

    replace_filename(path_attrs.filename, new_extension);

    VideoWriter outputVideo(
        videos_path_folder.string().append("/" + path_attrs.filename), codec,
        fps, Size(frameWidth, frameHeight));

    if (!outputVideo.isOpened()) {
      cerr << "Error: could not open video file for writing" << '\n';
      return false;
    }

    Mat frame;

    while (true) {
      inputVideo >> frame;
      if (frame.empty()) {
        break;
      }
      outputVideo.write(frame);
    }

    inputVideo.release();
    outputVideo.release();

    cout << "Video conversion completed successfully" << '\n';
    return true;
  } catch (std::exception &e) {
    cout << e.what() << '\n';
  }
  return false;
}
} // namespace Convert
