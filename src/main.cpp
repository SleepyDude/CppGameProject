#include "main_window.hpp"
#include <qdesktopwidget.h>

int main(int argc, char ** argv)
{
  QApplication a(argc, argv);
  MainWindow mw;
  mw.resize(200,200);
  // move to screen center
  mw.move(QApplication::desktop()->screen()->rect().center() - mw.rect().center());
  mw.show();
  return a.exec();
}
