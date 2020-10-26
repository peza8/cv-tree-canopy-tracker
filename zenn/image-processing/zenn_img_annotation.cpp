#include <zenn_img_annotation.hpp>

#include <stdexcept>

#include <spdlog.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

// Look at this: https://github.com/opencv/opencv/blob/master/samples/cpp/example_cmake/CMakeLists.txt

namespace zenn {

void PrintImgInfo(const cv::Mat& img) {
  spdlog::info("Image width = {} height = {}", img.cols, img.rows);
}

void DrawCenterCircleOnImg(const std::string& img_path) {
  cv::Mat aerial_img = cv::imread(img_path, cv::IMREAD_COLOR);
  if (aerial_img.empty()) {
    const std::string err_msg = "Could not find image: " + img_path; 
    throw std::runtime_error(err_msg);
  }
  PrintImgInfo(aerial_img);

  const int row_mid = aerial_img.rows/2;
  const int col_mid = aerial_img.cols/2;
  cv::Point circle_center(col_mid, row_mid);
  cv::Scalar circle_colour(0,0,255);
  const int radius = 200;
  const int line_weigth = 2;
  cv::circle(aerial_img, circle_center, radius, circle_colour, line_weigth);

  cv::imshow("Display window", aerial_img);
  cv::waitKey(0); 
}



}