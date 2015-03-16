#include "browserwindow.h"
#include "qmozcontext.h"

BrowserWindow::BrowserWindow()
    : OpenGLWindow(NULL)
{
    connect(QMozContext::GetInstance(), SIGNAL(onInitialized()), this, SLOT(onContextInitialized()));
    connect(&m_mozView, SIGNAL(viewInitialized()), this, SLOT(onViewInitialized()));
    m_timer.setInterval(41);
    m_timer.setSingleShot(false);
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(renderNow()));
}

void BrowserWindow::initialize()
{
    qDebug() << "*";
    m_mozView.m_window = this;
    m_mozView.init();
    m_mozView.geometryChanged(geometry(), geometry());
}

void BrowserWindow::render()
{
    const qreal retinaScale = devicePixelRatio();
    glViewport(0, 0, width() * retinaScale, height() * retinaScale);

    glClear(GL_COLOR_BUFFER_BIT);
    if (m_timer.isActive()) {
        qDebug() << "* rendering";
        m_mozView.RenderToCurrentContext();
    }
}

void BrowserWindow::onContextInitialized()
{
    qDebug() << "*";
    m_mozView.onRenderThreadReady();
}

void BrowserWindow::onViewInitialized()
{
    qDebug() << "*";
    if (QMozContext::GetInstance()->initialized()) {
        m_mozView.loadFrameScript("chrome://embedlite/content/embedhelper.js");
        m_mozView.load("http://iltasanomat.fi");
        m_timer.start();
    }
}
