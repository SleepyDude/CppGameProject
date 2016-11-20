#pragma once

#include <QApplication>
#include <QMainWindow>
#include <QObject>
#include <QVBoxLayout>
#include <QtWidgets>
#include <QTabWidget>
#include <QSpinBox>
#include <QGridLayout>
#include <QTimer>
#include <QOpenGLWidget>
#include "gl_widget.h"

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow();

private slots:
  void createGame();
  void createSettings();
  void createMenu();
private:
  QOpenGLWidget * m_glWidget = nullptr;
};
