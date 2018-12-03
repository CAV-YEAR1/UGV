#ifndef _ZEDCONFIG_HPP_
#define _ZEDCONFIG_HPP_

#include<sl/Camera.hpp>

class Zed {

private:
  sl::Camera zed;
  sl::Mat point_cloud;
  float4 point3D;
  InitParameters init_params;
  RuntimeParameters runtime_parameters;

public:
  Zed();
  ~Zed();
  bool initialize();
  bool updateFrame();
  float getDistance(int i, int j);
  void run();
  void end();

};

#endif
