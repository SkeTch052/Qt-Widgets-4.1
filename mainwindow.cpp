#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Тренажер медитации");

    ui->groupBox->setTitle("Выберите позицию:");

    ui->rb_sitting->setText("Сидя");
    ui->rb_lyingDown->setText("Лежа");

    QStringList texts;
    texts << "Дыхательная" << "Визуализация" << "Мантра" << "Телесная" << "Звуковая";

    ui->cb_dropList->addItems(texts);

    ui->pb_accept->setText("Начать");
    ui->pb_accept->setCheckable(true);

    ui->progbar_progress->setMinimum(0);
    ui->progbar_progress->setMaximum(10);
    ui->progbar_progress->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_accept_clicked()
{
    int val = ui->progbar_progress->value();

    int newVal = val + 1;

    if (newVal > ui->progbar_progress->maximum()) {
        newVal = 0;
    }

    ui->progbar_progress->setValue(newVal);
}
