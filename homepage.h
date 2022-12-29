#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>

namespace Ui {
class HomePage;
}

class HomePage : public QWidget
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);

    ~HomePage();

    void setTime(const QString& time);

    void setDuration(const QString& duration);

    void setDayTraffic(quint64 dayTraffic);

    void setMonthTraffic(quint64 monthTraffic);

protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void on_disconnect_push_button_clicked();

private:
    Ui::HomePage *ui;

};

#endif // HOMEPAGE_H
