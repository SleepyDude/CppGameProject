#include "main_window.hpp"

typedef void (QWidget::*QWidgetVoidSlot)();

MainWindow::MainWindow()
{
  setWindowTitle("Space Invaders");
  setFocusPolicy(Qt::StrongFocus);
  MainWindow::createMenu();
}

void MainWindow::createMenu()
{
  QWidget * menuWidget = new QWidget(this);
  setCentralWidget(menuWidget);
  QPushButton * button1 = new QPushButton("New game");

  QPushButton * settingsButton = new QPushButton("Settings", this);
  connect(settingsButton, SIGNAL(clicked()), this, SLOT( createSettings() ));

  QPushButton * exitButton = new QPushButton("Exit");
  connect(exitButton, SIGNAL(clicked()), QApplication::instance(), SLOT( quit() ));

  QVBoxLayout * verticalGroupBox = new QVBoxLayout(menuWidget);
  verticalGroupBox->addWidget(button1);
  verticalGroupBox->addWidget(settingsButton);
  verticalGroupBox->addWidget(exitButton);
}

void MainWindow::createSettings()
{
  QWidget * settingsWidget = new QWidget(this);
  setCentralWidget(settingsWidget);
  QTabWidget * tab = new QTabWidget(this);
  QVBoxLayout * newLayout = new QVBoxLayout(settingsWidget);
  newLayout->addWidget(tab);
  QPushButton * toMenuButton = new QPushButton("Menu");
  newLayout->addWidget(toMenuButton);
  connect(toMenuButton, SIGNAL(clicked()), this, SLOT( createMenu() ));

  QWidget * alienWidget = new QWidget(this);

  QSpinBox * alienHP = new QSpinBox(this);
  QSpinBox * alienVelocity = new QSpinBox(this);
  QLabel * alienHPLable = new QLabel("HP", this);
  QLabel * alienVelocityLable = new QLabel("Velocity", this);

  QGridLayout * alienLayout = new QGridLayout(alienWidget);
  alienLayout->addWidget(alienHPLable, 0, 0);
  alienLayout->addWidget(alienHP, 0, 1);
  alienLayout->addWidget(alienVelocityLable, 1, 0);
  alienLayout->addWidget(alienVelocity, 1, 1);

  tab->addTab(alienWidget,"Alien");

  QWidget * gunWidget = new QWidget(this);

  QSpinBox * gunHP = new QSpinBox(this);
  QSpinBox * gunRate = new QSpinBox(this);
  QLabel * gunHPLable = new QLabel("HP", this);
  QLabel * gunRateLable = new QLabel("Rate", this);

  QGridLayout * gunLayout = new QGridLayout(gunWidget);
  gunLayout->addWidget(gunHPLable, 0, 0);
  gunLayout->addWidget(gunHP, 0, 1);
  gunLayout->addWidget(gunRateLable, 1, 0);
  gunLayout->addWidget(gunRate, 1, 1);

  tab->addTab(gunWidget, "Gun");
}
