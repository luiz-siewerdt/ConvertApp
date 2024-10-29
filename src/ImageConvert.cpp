#include "ImageConvert.hpp"
#include "Utils.hpp"
#include <exception>
#include <filesystem>
#include <iostream>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include <string>

using namespace std;
using namespace cv;
using namespace Convert;

namespace fs = std::filesystem;

namespace Convert {
const vector<string> image_extensions{"jpg", "jpeg", "png", "webp"};

bool convertImage(const string &image_path_string,
                  const string &new_extension) {
  try {
    fs::path file_path{default_file_folder / "images"};
    fs::path image_path{fs::absolute(image_path_string)};

    PathAttrs path_attrs = valid_path(image_path, image_extensions);

    Mat image{imread(image_path.string())};

    if (image.empty()) {
      cerr << "Failed to read the image" << '\n';
      return false;
    }

    replace_filename(path_attrs.filename, new_extension);

    imwrite(file_path.string().append("/" + path_attrs.filename), image);

    cout << "Image converted successfully!" << '\n';

    return true;
  } catch (exception &e) {
    cout << e.what() << '\n';
  }
  return false;
}
} // namespace Convert
