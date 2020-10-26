#include <iostream>
#include <spdlog.h>

#include <zenn_img_annotation.hpp>

int main() {
  spdlog::info("Script running");
  zenn::DrawCenterCircleOnImg("./data-source/aerial-img-01.png");

  return 0;
}