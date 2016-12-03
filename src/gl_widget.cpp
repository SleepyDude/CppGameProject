#include "gl_widget.h"

#include <QPainter>
#include <QPaintEngine>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QCoreApplication>
#include <QtGui/QMouseEvent>
#include <QtGui/QGuiApplication>
#include <cmath>

#include <iostream>

#include "main_window.hpp"

namespace
{

int constexpr kLeftDirection = 0;
int constexpr kRightDirection = 1;
int constexpr kUpDirection = 2;
int constexpr kDownDirection = 3;

bool IsLeftButton(Qt::MouseButtons buttons)
{
  return buttons & Qt::LeftButton;
}
bool IsLeftButton(QMouseEvent const * const e)
{
  return IsLeftButton(e->button()) || IsLeftButton(e->buttons());
}

bool IsRightButton(Qt::MouseButtons buttons)
{
  return buttons & Qt::RightButton;
}
bool IsRightButton(QMouseEvent const * const e)
{
  return IsRightButton(e->button()) || IsRightButton(e->buttons());
}

} // namespace

GLWidget::GLWidget(MainWindow * mw, QColor const & background)
  : m_mainWindow(mw)
  , m_background(background)
{
  setFocusPolicy(Qt::StrongFocus);
}

GLWidget::~GLWidget()
{
  makeCurrent();
  delete m_texture;
  delete m_texturedRect;
  doneCurrent();
}

void GLWidget::initializeGL()
{
  initializeOpenGLFunctions();

  m_texturedRect = new TexturedRect();
  m_texturedRect->Initialize(this);
  m_texture = new QOpenGLTexture(QImage("data/gun.png"));

  for (int i = 0; i < 100; i++)
  {
    m_stars.push_back(new Star());
  }
  m_time.start();
  m_timeStar.start();
}

void GLWidget::paintGL()
{
  int const elapsed = m_time.elapsed();

  static std::chrono::time_point<std::chrono::steady_clock> lastCallTimestamp = std::chrono::steady_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - lastCallTimestamp);
  Update(duration.count() / 1000.0f);
  lastCallTimestamp = std::chrono::steady_clock::now();

  QPainter painter;
  painter.begin(this);
  painter.beginNativePainting();

  glClearColor(m_background.redF(), m_background.greenF(), m_background.blueF(), 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glFrontFace(GL_CW);
  glCullFace(GL_BACK);
  glEnable(GL_CULL_FACE);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  Render();

  glDisable(GL_CULL_FACE);
  glDisable(GL_BLEND);

  painter.endNativePainting();

  if (elapsed != 0)
  {
    QString framesPerSecond;
    framesPerSecond.setNum(m_frames / (elapsed / 1000.0), 'f', 2);
    painter.setPen(Qt::white);
    painter.drawText(20, 40, framesPerSecond + " fps");
  }
  painter.end();

  if (!(m_frames % 100))
  {
    m_time.start();
    m_frames = 0;
  }
  ++m_frames;
  update();
}

void GLWidget::resizeGL(int w, int h)
{
  m_screenSize.setWidth(w);
  m_screenSize.setHeight(h);
  m_space.SetDimension(w, h);
}

void GLWidget::Update(float elapsedSeconds)
{
  float const kSpeed = m_space.xDim() * 0.3f; // pixels per second.
  /*
  if (m_directions[kUpDirection])
    m_space.SpaceGun().position().y() = (m_position.y() + kSpeed * elapsedSeconds);
  if (m_directions[kDownDirection])
    m_space.SpaceGun().position().y() = (m_position.y() - kSpeed * elapsedSeconds);
  */
  if (m_directions[kLeftDirection] && m_space.SpaceGun().position().x() >= 0)
  {
    m_space.SpaceGun().Move(- kSpeed * elapsedSeconds);
    for(auto it = m_stars.begin(); it != m_stars.end(); ++it)
      (*it)->Move(0.001f, 0);
  }
  if (m_directions[kRightDirection] && m_space.SpaceGun().position().x() + m_space.SpaceGun().xDim() < m_screenSize.width())
  {
    m_space.SpaceGun().Move(kSpeed * elapsedSeconds);
    for(auto it = m_stars.begin(); it != m_stars.end(); ++it)
      (*it)->Move(-0.001f, 0);
  }
}

void GLWidget::Render()
{
  for(auto it = m_stars.begin(); it != m_stars.end(); ++it)
  {
    (*it)->Move(0, -0.005f);
    int size = (*it)->getSize() * sin( ((*it)->getTimeStart() - m_timeStar.elapsed()) / (*it)->getTimePeriod());
    m_texturedRect->Render((*it)->getTexture(), QVector2D((*it)->getXScale() * m_screenSize.width(),\
                           (*it)->getYScale() * m_screenSize.height()), QSize(size, size), m_screenSize);
  }
  m_texturedRect->Render(m_texture, QVector2D(m_space.SpaceGun().position().x() + m_space.SpaceGun().xDim() / 2,\
                                              m_space.SpaceGun().position().y() + m_space.SpaceGun().yDim() / 2),\
                         QSize(m_space.SpaceGun().xDim(), m_space.SpaceGun().yDim()), m_screenSize);
}

void GLWidget::mousePressEvent(QMouseEvent * e)
{
  QOpenGLWidget::mousePressEvent(e);

  int const px = L2D(e->x());
  int const py = L2D(e->y());
  if (IsLeftButton(e))
  {
    // ...
  }
}

void GLWidget::mouseDoubleClickEvent(QMouseEvent * e)
{
  QOpenGLWidget::mouseDoubleClickEvent(e);

  int const px = L2D(e->x());
  int const py = L2D(e->y());
  if (IsRightButton(e))
  {
    // ...
  }
}

void GLWidget::mouseMoveEvent(QMouseEvent * e)
{
  QOpenGLWidget::mouseMoveEvent(e);

  int const px = L2D(e->x());
  int const py = L2D(e->y());
  if (IsLeftButton(e))
  {
    // ...
  }
}

void GLWidget::mouseReleaseEvent(QMouseEvent * e)
{
  QOpenGLWidget::mouseReleaseEvent(e);

  int const px = L2D(e->x());
  int const py = L2D(e->y());
  if (IsLeftButton(e))
  {
    // ...
  }
}

void GLWidget::wheelEvent(QWheelEvent * e)
{
  QOpenGLWidget::wheelEvent(e);

  int const delta = e->delta();
  int const px = L2D(e->x());
  int const py = L2D(e->y());
  // ...
}

void GLWidget::keyPressEvent(QKeyEvent * e)
{
  if (e->key() == Qt::Key_Up)
    m_directions[kUpDirection] = true;
  else if (e->key() == Qt::Key_Down)
    m_directions[kDownDirection] = true;
  else if (e->key() == Qt::Key_Left)
    m_directions[kLeftDirection] = true;
  else if (e->key() == Qt::Key_Right)
    m_directions[kRightDirection] = true;
}

void GLWidget::keyReleaseEvent(QKeyEvent * e)
{
  if (e->key() == Qt::Key_Up)
    m_directions[kUpDirection] = false;
  else if (e->key() == Qt::Key_Down)
    m_directions[kDownDirection] = false;
  else if (e->key() == Qt::Key_Left)
    m_directions[kLeftDirection] = false;
  else if (e->key() == Qt::Key_Right)
    m_directions[kRightDirection] = false;
}
