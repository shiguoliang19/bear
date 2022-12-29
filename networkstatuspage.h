#ifndef NETWORKSTATUSPAGE_H
#define NETWORKSTATUSPAGE_H

#include <QWidget>

namespace Ui {
class NetworkStatusPage;
}

class NetworkStatusPage : public QWidget
{
    Q_OBJECT

public:
    explicit NetworkStatusPage(QWidget *parent = nullptr);

    ~NetworkStatusPage();

    void setLatency(double latency);

    void setLossRate(double lossRate);

    void setBandwidth(double rxBandwidth, double txBandwidth);

    void setTraffic(double rxTraffic, double txTraffic);

private slots:
    void on_return_button_clicked();

private:
    Ui::NetworkStatusPage *ui;
};

#endif // NETWORKSTATUSPAGE_H
