#include "homepage.h"
#include "ui_homepage.h"

#include <QtWidgets>
#include "networkstatuspage.h"

HomePage::HomePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground);

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(this);
    effect->setOffset(0, 0);
    effect->setBlurRadius(20);
    ui->widget->setGraphicsEffect(effect);

    connect(ui->settings_tool_button, &QToolButton::clicked, [=](){
        NetworkStatusPage* networkStatusPage = new NetworkStatusPage(this);
        networkStatusPage->resize(size());
        networkStatusPage->show();
    });
}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::setTime(const QString &time)
{
    ui->time_value_label->setText(time);
}

void HomePage::setDuration(const QString &duration)
{
    ui->duration_value_label->setText(duration);
}

void HomePage::setDayTraffic(quint64 dayTraffic)
{
    QString text = QString("%1 Byte").arg(dayTraffic);
    ui->day_traffic_value_label->setText(text);
}

void HomePage::setMonthTraffic(quint64 monthTraffic)
{
    QString text = QString("%1 Byte").arg(monthTraffic);
    ui->month_traffic_value_label->setText(text);
}

void HomePage::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.save();

    QRect templateRect = rect();

    QRect topRect = templateRect;
    topRect.setBottom(height() * 0.4);

    QRect bottomRect = templateRect;
    bottomRect.setTop(height() * 0.4);

    QPixmap pixmap(":/assets/kataer20104_con08_bg05.jpg");
    painter.drawPixmap(topRect, pixmap, pixmap.rect());
    painter.fillRect(bottomRect, QBrush(QColor(Qt::white)));

    painter.restore();

    return QWidget::paintEvent(event);
}

void HomePage::on_disconnect_push_button_clicked()
{
    close();
}
