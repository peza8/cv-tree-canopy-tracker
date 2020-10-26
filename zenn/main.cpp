#include <iostream>
#include <spdlog.h>

#include <zenn_img_annotation.hpp>

int main() {
  spdlog::info("Script running");
  // zenn::DrawCenterCircleOnImg("./data-source/aerial-img-01.png");

  zenn::DrawCenterCircleOnVid("./data-source/descent-image-feed-01.MP4");

  return 0;
}