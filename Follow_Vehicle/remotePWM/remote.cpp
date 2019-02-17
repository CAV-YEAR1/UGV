#include "remote.hpp"

remote::remote(QWidget * parent) : prevState(S)
{
  auto layout = new QVBoxLayout;
  setLayout(layout);
  p = new PWM("../PWM-config.txt");
  if(!p -> setup()) {
    std::cout<<"Error: PWM setup failed"<<std::endl;
    error = true;
  }
}

void remote::updateSteering(int value) {
  std::cout<<value<<std::endl;
}

void remote::updateSpeed(int value) {
  std::cout<<value<<std::endl;
}

void remote::keyPressEvent(QKeyEvent *event) {

  if(event -> isAutoRepeat()) return;

  switch (event -> key()) {
    case Qt::Key_Up:
      updateSpeed(FORWARD);
      break;
    case Qt::Key_Down:
      updateSpeed(REVERSE);
      break;
    case Qt::Key_Left:
      updateSteering(LEFT);
      break;
    case Qt::Key_Right:
      updateSteering(RIGHT);
      break;
    case Qt::Key_Q:
      exit(1);
      break;
  }
}

void remote::keyReleaseEvent(QKeyEvent *event) {
  if(event -> isAutoRepeat()) return;

  switch (event -> key()) {
    case Qt::Key_Up:
      updateSpeed(STOP);
      break;
    case Qt::Key_Down:
      updateSpeed(STOP);
      break;
    case Qt::Key_Left:
      updateSteering(STRAIGHT);
      break;
    case Qt::Key_Right:
      updateSteering(STRAIGHT);
      break;
  }
}
