#ifndef _ZEDCONFIG_HPP_
#define _ZEDCONFIG_HPP_

#include<sl/Camera.hpp>

using namespace sl;

class Zed {

private:
  sl::Camera zed;
  sl::Mat point_cloud;
  sl::float4 point3D;
  sl::InitParameters init_params;
  sl::RuntimeParameters runtime_parameters;

public:
  Zed();
  ~Zed();
  bool initialize();
  bool updateFrame();
  float getDistance();
  void run();
  void end();

};

#endif
