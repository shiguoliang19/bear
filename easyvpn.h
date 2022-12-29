#ifndef EASYVPN_H
#define EASYVPN_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class EasyVPN; }
QT_END_NAMESPACE

class EasyVPN : public QWidget
{
    Q_OBJECT

public:
    EasyVPN(QWidget *parent = nullptr);
    ~EasyVPN();

private:
    Ui::EasyVPN *ui;
};
#endif // EASYVPN_H
