#include "ZedConfig.hpp"

Zed::Zed() {
  initialize();
}

Zed::~Zed() {
  end();
}

bool Zed::initialize() {

  init_params.camera_resolution = RESOLUTION_HD720;
  init_params.camera_fps = 60;
  init_params.coordinate_units = UNIT_MILLIMETER;
  init_params.depth_mode = DEPTH_MODE_ULTRA;
  init_params.depth_minimum_distance = 0.05;

  Error_CODE err =zed.open(init_params);
  if(err != SUCCESS) {
    std::cout<<"Error: unable to open camera"<<std::endl;
    exit(-1);
  }

  runtime_parameters.sensing_mode = SENSING_MODE_STANDARD;

}

bool Zed::updateFrame() {
  if(zed.grab(runtime_parameters) == SUCCESS) {
    zed.retrieveMeasure(point_cloud, MEASURE_XYSRGBA);
    return true
  }

  return false;
}

float Zed::getDistance() {
  for(int i = 0; i<point_cloud.getWidth(); ++i)
  {
    point_cloud.getValue(i, point_cloud.getHeight()/2, &point3D);
    float sumDistance += sqrt(point3D.x*point3D.x + point3D.y*point3D.y + point3D.z*point3D.z);
  }

  float  distance = sumDistance/i;
  return distance;
}

void Zed::run() {
  int y = point_cloud.getHeight();
  int x = 0;

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
