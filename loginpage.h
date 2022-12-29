#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>

namespace Ui {
class LoginPage;
}

class LoginPage : public QWidget
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = nullptr);

    ~LoginPage();

    void setUsername(const QString& username);

    void setPassword(const QString& password);

    void paintEvent(QPaintEvent *event);

private slots:
    void on_connect_push_button_clicked();

private:
    Ui::LoginPage *ui;
};

#endif // LOGINPAGE_H
