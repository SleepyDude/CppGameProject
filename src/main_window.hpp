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

#include <json/json.h>
#include <fstream>

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow();

private slots:
  void createGame();
  void createMenu();
  void WriteSettings();
  void createSettings();

private:
  QOpenGLWidget * m_glWidget = nullptr;
  QSpinBox * m_alienHP = nullptr;
  QSpinBox * m_alienVelocity = nullptr;
  QSpinBox * m_gunHP = nullptr;
  QSpinBox * m_gunRate = nullptr;
};
