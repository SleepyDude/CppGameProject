#pragma once

#include <QApplication>
#include <QMainWindow>
#include <QObject>
#include <QVBoxLayout>
#include <QtWidgets>
#include <QTabWidget>
#include <QSpinBox>
#include <QGridLayout>

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow();

private slots:
  void createSettings();
  void createMenu();

private:
  void changer();
  QPushButton * m_toMenuButton;
  QPushButton * m_settimgsButton;
  QPushButton * m_ExitButton;

  QWidget * m_settingsWidget;
  QWidget * m_menuWidget;
};
