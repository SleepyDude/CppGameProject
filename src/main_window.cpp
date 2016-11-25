#include "main_window.hpp"

typedef void (QWidget::*QWidgetVoidSlot)();

MainWindow::MainWindow()
{
  setWindowTitle("Space Invaders");
  setFocusPolicy(Qt::StrongFocus);
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
  connect(timer, &QTimer::timeout, m_glWidget, static_cast<QWidgetVoidSlot>(&QWidget::update));
  timer->start();
}

void MainWindow::WriteSettings()
{
  QVariantMap settings;
  QJsonObject alien;
  QJsonObject gun;
  alien["alienHP"] = m_alienHP->value();
  alien["alienVelocity"] = m_alienVelocity->value();

  gun["gunHP"] = m_gunHP->value();
  gun["gunRate"] = m_gunRate->value();;
  settings["alien"] = alien;
  settings["gun"] = gun;
  QJsonDocument saveDoc(QJsonObject::fromVariantMap(settings));
  QString fileName("settings.json");
  if (!fileName.isEmpty())
  {
    QFile json(fileName);
    if(json.open(QIODevice::WriteOnly))
    {
       json.write(saveDoc.toJson());
    }
  }
}
