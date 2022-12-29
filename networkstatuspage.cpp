#include "networkstatuspage.h"
#include "ui_networkstatuspage.h"

NetworkStatusPage::NetworkStatusPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NetworkStatusPage)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground);
}

NetworkStatusPage::~NetworkStatusPage()
{
    delete ui;
}

void NetworkStatusPage::setLatency(double latency)
{
    QString text = QString("%1 ms").arg(latency, 0, 'f', 2);
    ui->latency_value_label->setText(text);
}

void NetworkStatusPage::setLossRate(double lossRate)
{
    QString text = QString("%1 %").arg(lossRate, 0, 'f', 2);
    ui->loss_rate_value_label->setText(text);
}

void NetworkStatusPage::setBandwidth(double rxBandwidth, double txBandwidth)
{
    QString text = QString("↓ %1 bps ↑ %2 bps").arg(rxBandwidth, 0, 'f', 2).arg(txBandwidth, 0, 'f', 2);
    ui->bandwidth_value_label->setText(text);
}

void NetworkStatusPage::setTraffic(double rxTraffic, double txTraffic)
{
    QString text = QString("↓ %1 B/s ↑ %2 B/s").arg(rxTraffic, 0, 'f', 2).arg(txTraffic, 0, 'f', 2);
    ui->traffic_value_label->setText(text);
}

void NetworkStatusPage::on_return_button_clicked()
{
    close();
}
