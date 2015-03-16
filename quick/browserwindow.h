#include  <QTimer>
#include "openglwindow.h"
#include "quickmozview.h"

class BrowserWindow : public OpenGLWindow
{
    Q_OBJECT
public:
    BrowserWindow();

    void initialize() Q_DECL_OVERRIDE;
    void render() Q_DECL_OVERRIDE;

private Q_SLOTS:
    void onViewInitialized();
    void onContextInitialized();

private:
    QuickMozView m_mozView;
    QTimer m_timer;
};
