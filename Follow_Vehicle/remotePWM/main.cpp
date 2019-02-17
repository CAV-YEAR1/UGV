#include "remote.hpp"
#include <QApplication>

int main(int argc, char * argv[])
{
  /*PWM p("../PWM-config.txt");
  if(!p.setup()) {
    std::cout<<"Error: PWM setup failed"<<std::endl;
    return 0;
  }
  */

  QApplication app(argc, argv);

  remote r;
  if(r.error) return 0;
  //QObject::connect(&r, SIGNAL(keyPressEvent(QKeyEvent)))
  r.show();
  return app.exec();
}
