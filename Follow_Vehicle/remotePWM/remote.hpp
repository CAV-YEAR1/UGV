#ifndef _REMOTE_HPP_
#define _REMOTE_HPP_

#include "../PWMCode/Jetson/PWM.hpp"
#include <QKeyEvent>
#include <QLayout>
#include <QWidget>

#define LEFT 150
#define STRAIGHT 90
#define RIGHT 30

#define FORWARD 105
#define STOP 90
#define REVERSE 80

typedef enum {F, S, R} throttleState;

class remote : public QWidget {
  Q_OBJECT

public:
  remote(QWidget *parent = nullptr);
  bool error = false;

public slots:
  void updateSteering(int value);
  void updateSpeed(int value);

protected:
  void keyPressEvent(QKeyEvent *);
  void keyReleaseEvent(QKeyEvent *);

private:
  throttleState prevState;
  PWM * p;
};

#endif
