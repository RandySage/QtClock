#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Setup the timer
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTime);
    timer->start(4); // Update every 4 ms, which is ~half the period for 120Hz

    updateTime(); // Initial time update
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTime()
{
    QTime time = QTime::currentTime();
    QString timeText = time.toString("hh:mm:ss.zzz");
    ui->timeLabel->setText(timeText);
}
