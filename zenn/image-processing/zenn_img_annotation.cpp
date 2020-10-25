#include <zenn_img_annotation.hpp>

#include <stdexcept>

#include <spdlog.h>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

// Look at this: https://github.com/opencv/opencv/blob/master/samples/cpp/example_cmake/CMakeLists.txt

namespace zenn {

void DrawCenterCircleOnImg(const std::string& img_path) {
  cv::Mat aerial_img = cv::imread(img_path, cv::IMREAD_COLOR);
  if (aerial_img.empty()) {
    const std::string err_msg = "Could not find image: " + img_path; 
    throw std::runtime_error(err_msg);
  }
  // cv::imshow(aerial_img);
}

}