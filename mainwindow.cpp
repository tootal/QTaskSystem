#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDesktopServices>
#include <QStandardPaths>
#include <QDebug>
#include <QDir>
#include <QUrl>
#include <QTreeView>
#include <QFileDialog>

#include "tasksystemmodel.h"
#include "taskfilemodel.h"
#include "taskmanager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    connect(ui->actionOpenTaskFile, &QAction::triggered,
            this, &MainWindow::openTaskFile);
    connect(ui->actionOpenTaskFolder, &QAction::triggered,
            this, &MainWindow::openTaskFolder);
    connect(ui->actionTaskManager, &QAction::triggered,
            this, &MainWindow::openTaskManager);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openTaskFile()
{
    auto fileName = QFileDialog::getOpenFileName(this,
                                 tr("Open Task Config File"),
                                 getTaskFolder(),
                                 "*.json");
    if (fileName.isEmpty()) return ;
    auto model = new TaskFileModel(this);
    model->setFileName(fileName);
    auto view = new QTreeView(this);
    view->setWindowFlag(Qt::Window);
    view->setMinimumWidth(600);
    view->setMinimumHeight(200);
    view->setModel(model);
    view->show();
}

QString MainWindow::getTaskFolder()
{
    auto path = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
    path = path + "/tasks";
    QDir().mkpath(path);
    return path;
}

void MainWindow::openTaskFolder()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(getTaskFolder()));
}

void MainWindow::openTaskManager()
{
    auto model = new TaskSystemModel(this);
    auto path = getTaskFolder();
    model->setRootPath(path);
    
    auto manager = new TaskManager(this);
    manager->setWindowFlag(Qt::Window);
    manager->setTaskSystemModel(model);
    manager->show();
}
