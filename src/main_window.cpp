#include "main_window.hpp"

typedef void (QWidget::*QWidgetVoidSlot)();

MainWindow::MainWindow()
{
  setWindowTitle("Space Invaders");
  //setFocusPolicy(Qt::StrongFocus);
  createMenu();
}

void MainWindow::createMenu()
{
  delete m_alienHP;
  delete m_alienVelocity;
  delete m_gunHP;
  delete m_gunRate;
  QWidget * menuWidget = new QWidget(this);
  setCentralWidget(menuWidget);
  QPushButton * startButton = new QPushButton("New game");
  connect(startButton, SIGNAL(clicked()), this, SLOT( createGame() ));

  QPushButton * settingsButton = new QPushButton("Settings", this);
  connect(settingsButton, SIGNAL(clicked()), this, SLOT( createSettings() ));

  QPushButton * exitButton = new QPushButton("Exit");
  connect(exitButton, SIGNAL(clicked()), QApplication::instance(), SLOT( quit() ));

  QVBoxLayout * verticalGroupBox = new QVBoxLayout(menuWidget);
  verticalGroupBox->addWidget(startButton);
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
  QPushButton * saveButton = new QPushButton("Save");
  newLayout->addWidget(saveButton);
  connect(saveButton, SIGNAL(clicked()), this, SLOT( WriteSettings() ));
  QPushButton * toMenuButton = new QPushButton("Menu");
  newLayout->addWidget(toMenuButton);
  connect(toMenuButton, SIGNAL(clicked()), this, SLOT( createMenu() ));

  QWidget * alienWidget = new QWidget(this);

  m_alienHP = new QSpinBox(this);
  m_alienVelocity = new QSpinBox(this);
  QLabel * alienHPLable = new QLabel("HP", this);
  QLabel * alienVelocityLable = new QLabel("Velocity", this);

  QGridLayout * alienLayout = new QGridLayout(alienWidget);
  alienLayout->addWidget(alienHPLable, 0, 0);
  alienLayout->addWidget(m_alienHP, 0, 1);
  alienLayout->addWidget(alienVelocityLable, 1, 0);
  alienLayout->addWidget(m_alienVelocity, 1, 1);

  tab->addTab(alienWidget,"Alien");

  QWidget * gunWidget = new QWidget(this);

  m_gunHP = new QSpinBox(this);
  m_gunRate = new QSpinBox(this);
  QLabel * gunHPLable = new QLabel("HP", this);
  QLabel * gunRateLable = new QLabel("Rate", this);

  QGridLayout * gunLayout = new QGridLayout(gunWidget);
  gunLayout->addWidget(gunHPLable, 0, 0);
  gunLayout->addWidget(m_gunHP, 0, 1);
  gunLayout->addWidget(gunRateLable, 1, 0);
  gunLayout->addWidget(m_gunRate, 1, 1);

  tab->addTab(gunWidget, "Gun");
}

void MainWindow::createGame()
{
  m_glWidget = new GLWidget(this, qRgb(20, 20, 50));
  QTimer * timer = new QTimer(this);
  timer->setInterval(10);
  setCentralWidget(m_glWidget);
  resize(800,600);
  this->move(QApplication::desktop()->availableGeometry().center() - this->rect().center());
  connect(timer, &QTimer::timeout, m_glWidget, static_cast<QWidgetVoidSlot>(&QWidget::update));
  timer->start();
  m_glWidget->setFocus();
}

void MainWindow::WriteSettings()
{
  Json::Value settings;
  Json::Value resolutions(Json::arrayValue);
  resolutions.append(Json::Value("800x600"));
  resolutions.append(Json::Value("1024x768"));
  resolutions.append(Json::Value("1280x1024"));
  auto & root = settings["settings"];
  root["resolution"] = resolutions;
  root["aliensCount"] = 100;
  root["bulletsCount"] = 200;
  root["entities"]["gun"]["health"] = m_gunHP->value();
  root["entities"]["alien"]["health"] = m_alienHP->value();
  root["entities"]["obstacle"]["health"] = 15;
  root["entities"]["gun"]["rate"] = m_gunHP->value();
  root["entities"]["alien"]["velocity"] = m_alienVelocity->value();
  std::ofstream settingsFile;
  settingsFile.open("settings.json");
  if (settingsFile.is_open())
  {
    Json::StyledWriter styledWriter;
    settingsFile << styledWriter.write(settings);
    settingsFile.close();
  }
}

