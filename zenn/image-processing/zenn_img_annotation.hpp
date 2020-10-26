#include <string>

#include <opencv2/core.hpp>

namespace zenn {

void PrintImgInfo(const cv::Mat& img);

void DrawCenterCircleOnImg(const std::string& img_path);

void DrawCenterCircleOnVid(const std::string& vid_path);

void DrawCenterCircleOnFrame(cv::Mat& frame);

}