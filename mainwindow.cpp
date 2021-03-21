#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDesktopServices>
#include <QStandardPaths>
#include <QDebug>
#include <QDir>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpenUserTaskFolder_triggered()
{
    openTaskFolder(QStandardPaths::AppConfigLocation);
}

void MainWindow::on_actionOpenDefaultTaskFolder_triggered()
{
    openTaskFolder(QStandardPaths::AppDataLocation);
}

void MainWindow::openTaskFolder(QStandardPaths::StandardLocation location)
{
    auto path = QStandardPaths::writableLocation(location);
    path = path + "/tasks";
    QDir().mkpath(path);
    QDesktopServices::openUrl(QUrl::fromLocalFile(path));
}
