#include "ZedConfig.hpp"

Zed::Zed() {
  initialize();
}

Zed::~Zed() {
  end();
}

bool Zed::initialize() {

  init_params.camera_resolution = sl::RESOLUTION_HD720;
  init_params.camera_fps = 60;
  init_params.coordinate_units = sl::UNIT_MILLIMETER;
  init_params.depth_mode = sl::DEPTH_MODE_ULTRA;
  init_params.depth_minimum_distance = 0.15;

  sl::ERROR_CODE err = zed.open(init_params);
  if(err != sl::SUCCESS) {
    std::cout<<"Error: unable to open camera"<<std::endl;
    exit(-1);
  }

  runtime_parameters.sensing_mode = sl::SENSING_MODE_STANDARD;

}

bool Zed::updateFrame() {
  if(zed.grab(runtime_parameters) == sl::SUCCESS) {
    zed.retrieveMeasure(point_cloud, sl::MEASURE_XYZRGBA);
    return true;
  }

  return false;
}

float Zed::getDistance() {
  float sumDistance;
  for(int i = 0; i<point_cloud.getWidth(); ++i)
  {
    point_cloud.getValue(i, point_cloud.getHeight()/2, &point3D);
    sumDistance += point3D.z;
    std::cout<<"Sum: "<<sumDistance<<std::endl;
  }

  float distance = sumDistance/point_cloud.getWidth();
  return distance;
}

void Zed::run() {
  for(;;) {
    if(!updateFrame()) {
      std::cout<<"Error: unable to grab frame"<<std::endl;
      return;
    }
    std::cout<<getDistance()<<std::endl;
  }
}

void Zed::end() {
  zed.close();
}
