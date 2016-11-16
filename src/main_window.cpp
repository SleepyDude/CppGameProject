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
  m_menuWidget = new QWidget(this);
  setCentralWidget(m_menuWidget);
  QPushButton * button1 = new QPushButton("New game");

  m_settimgsButton = new QPushButton("Settings", this);
  connect(m_settimgsButton, SIGNAL(clicked()), this, SLOT( createSettings() ));

  m_ExitButton = new QPushButton("Exit");
  connect(m_ExitButton, SIGNAL(clicked()), QApplication::instance(), SLOT( quit() ));

  QVBoxLayout * verticalGroupBox = new QVBoxLayout(m_menuWidget);
  verticalGroupBox->addWidget(button1);
  verticalGroupBox->addWidget(m_settimgsButton);
  verticalGroupBox->addWidget(m_ExitButton);
}

void MainWindow::createSettings()
{
  m_settingsWidget = new QWidget(this);
  setCentralWidget(m_settingsWidget);
  QTabWidget * tab = new QTabWidget(this);
  QVBoxLayout * newLayout = new QVBoxLayout(m_settingsWidget);
  newLayout->addWidget(tab);
  m_toMenuButton = new QPushButton("Menu");
  newLayout->addWidget(m_toMenuButton);
  connect(m_toMenuButton, SIGNAL(clicked()), this, SLOT( createMenu() ));

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
