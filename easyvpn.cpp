#include "easyvpn.h"
#include "ui_easyvpn.h"

#include <QtWidgets>
#include "loginpage.h"

EasyVPN::EasyVPN(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EasyVPN)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground);

    QTimer::singleShot(3000, [=](){
        LoginPage* loginPage = new LoginPage(this);
        loginPage->resize(size());
        loginPage->show();
    });

    setFixedSize(400, 700);
}

EasyVPN::~EasyVPN()
{
    delete ui;
}

