#include "loginpage.h"
#include "ui_loginpage.h"

#include <QtWidgets>
#include "homepage.h"

LoginPage::LoginPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground);

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(this);
    effect->setOffset(0, 0);
    effect->setBlurRadius(20);
    ui->login_widget->setGraphicsEffect(effect);

    ui->username_line_edit->addAction(QIcon(":/assets/user.png"), QLineEdit::LeadingPosition);
    ui->password_line_edit->addAction(QIcon(":/assets/password.png"), QLineEdit::LeadingPosition);
    QAction* action = new QAction(this);
    action->setCheckable(true);
    ui->password_line_edit->addAction(action, QLineEdit::TrailingPosition);
    connect(action, &QAction::triggered, [=](bool checked){
        if(checked)
        {
            action->setIcon(QIcon(":/assets/eye_open.png"));
            ui->password_line_edit->setEchoMode(QLineEdit::Normal);
        }
        else
        {
            action->setIcon(QIcon(":/assets/eye_close.png"));
            ui->password_line_edit->setEchoMode(QLineEdit::Password);
        }
    });
    emit action->triggered(false);
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::setUsername(const QString &username)
{
    ui->username_line_edit->setText(username);
}

void LoginPage::setPassword(const QString &password)
{
    ui->password_line_edit->setText(password);
}

void LoginPage::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.save();

    QRect templateRect = rect();

    QRect topRect = templateRect;
    topRect.setBottom(height() * 0.4);

    QRect bottomRect = templateRect;
    bottomRect.setTop(height() * 0.4);

    painter.fillRect(topRect, QBrush(QColor(44, 166, 203)));
    painter.fillRect(bottomRect, QBrush(QColor(Qt::white)));

    QPixmap pixmap(":/assets/kataer20104_con08_bg05.jpg");
    painter.drawPixmap(topRect, pixmap, pixmap.rect());

    painter.restore();

    return QWidget::paintEvent(event);
}

void LoginPage::on_connect_push_button_clicked()
{
    HomePage* homePage = new HomePage(this);
    homePage->resize(size());
    homePage->show();
}
