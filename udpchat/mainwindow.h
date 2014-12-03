#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QtWidgets>
#include <QtNetwork>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void send(QString nick, QString str);
    void appendMessage(const QString &from, const QString &message);

private slots:
    void read();
    void returnPressed();
    void itemPressed(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    QString nickname;
    int _port;
    QUdpSocket socket;
    QTextTableFormat tableFormat;
};

#endif // MAINWINDOW_H
