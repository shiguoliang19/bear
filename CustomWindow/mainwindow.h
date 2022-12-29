
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>

#include <QtWidgets>

#ifdef Q_OS_WIN
#include <windows.h>
#include <windowsx.h>
#include <QMouseEvent>
#include "dwmapi.h" // Dwmapi.lib
#endif

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();

    void onFullscreen();
    void exitFullscreen();
    void onMin();
    void onMaxOrNormal();
    void onClose();

protected:
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);
    void changeEvent(QEvent* e);
    void keyPressEvent(QKeyEvent *event);

private:
    int m_contentTop = 0;
    float m_dpiScale = 1.0f;

    QLabel *m_testLabel;

    QPushButton *m_iconButton;
    QLabel *m_titleLabel;

    QPushButton *m_fullButton;
    QPushButton *m_minButton;
    QPushButton *m_maxButton;
    QPushButton *m_closeButton;

    QWidget *m_content;

    QHBoxLayout *m_titleLayout;
    QVBoxLayout *m_mainLayout;

    void initUI();
    void updateText();
    void onLogicalDotsPerInchChanged(qreal dpi);
    void setWidgetBorderless();
};

#endif // MAINWINDOW_H
