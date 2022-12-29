#include <QApplication>
#include <QtWidgets>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

	QTranslator translator;
	bool ok = translator.load(QString(":/res/zh_CN.qm"));
	if (!ok) {
        qDebug() << "load translator file error!";
	}
	app.installTranslator(&translator);

	QFile file(":/res/skin/black.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	app.setStyleSheet(styleSheet);
	file.close();

    MainWindow* mainWin = new MainWindow;
	mainWin->show();

    return app.exec();
}
