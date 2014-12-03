#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setFocusPolicy(Qt::StrongFocus);
    ui->textEdit->setFocusPolicy(Qt::NoFocus);
    ui->textEdit->setReadOnly(true);
    ui->listWidget->setFocusPolicy(Qt::NoFocus);
    _port = 7777;
    socket.bind(QHostAddress::Any, _port);
    connect(&socket, SIGNAL(readyRead()), SLOT(read()));
    connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(returnPressed()));
    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)),
                   this, SLOT(itemPressed(QListWidgetItem *)));
    bool bOk;
    nickname = QInputDialog::getText( 0,
                                         "Please, log in!",
                                         "Nick:",
                                         QLineEdit::Normal,
                                         "NickName",
                                         &bOk
                                        );
    if (!bOk || nickname.isEmpty())
        nickname = QHostInfo::localHostName();

    tableFormat.setBorder(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::itemPressed(QListWidgetItem *item)
{
    ui->lineEdit->setText(item->text()+", ");
}

void MainWindow::appendMessage(const QString &from, const QString &message)
{
    if (from.isEmpty() || message.isEmpty())
        return;

    QTextCursor cursor(ui->textEdit->textCursor());
    cursor.movePosition(QTextCursor::End);
    QTextTable *table = cursor.insertTable(1, 2, tableFormat);
    ui->textEdit->setTextColor(Qt::gray);
    table->cellAt(0, 0).firstCursorPosition().insertText(from + ": ");
    ui->textEdit->setTextColor(Qt::red);
    table->cellAt(0, 1).firstCursorPosition().insertText(message);
    QScrollBar *bar = ui->textEdit->verticalScrollBar();
    bar->setValue(bar->maximum());
}

void MainWindow::returnPressed()
{
    QString text = ui->lineEdit->text();
    if (text.isEmpty())
        return;

    send(nickname, text);
    ui->lineEdit->clear();
}

void MainWindow::send(QString nick, QString str) {
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out << nick << str;
    socket.writeDatagram(data, QHostAddress::Broadcast, _port);
}

void MainWindow::read() {
    QByteArray datagram;
    datagram.resize(socket.pendingDatagramSize());
    QHostAddress *address = new QHostAddress();
    socket.readDatagram(datagram.data(), datagram.size(), address);

    QDataStream in(&datagram, QIODevice::ReadOnly);

    QString str, nick;
    in >> nick >> str;
    appendMessage(nick, str);

    QList<QListWidgetItem *> items = ui->listWidget->findItems(nick,
                                                               Qt::MatchExactly);
    if (items.isEmpty()) {
        ui->listWidget->addItem(nick);
    }
}
