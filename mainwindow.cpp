#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDesktopServices>
#include <QStandardPaths>
#include <QDebug>
#include <QDir>
#include <QUrl>
#include <QTreeView>
#include <QFileDialog>

#include "taskparser.h"
#include "tasksystemmodel.h"
#include "taskfilemodel.h"
#include "taskmanager.h"
#include "task.h"

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
    
    setupText();
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
    path = path + "/" + Task::DIR_NAME;
    QDir().mkpath(path);
    return path;
}

void MainWindow::openTaskFolder()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(getTaskFolder()));
}

void MainWindow::openTaskManager()
{
    Task *task = TaskParser::parse(getTaskFolder());
    auto model = new TaskSystemModel(this);
    model->setRootTask(task);
    
    auto manager = new TaskManager(this);
    manager->setWindowFlag(Qt::Window);
    manager->setTaskSystemModel(model);
    manager->show();
}

void MainWindow::setupText()
{
    ui->textEdit->setReadOnly(true);
    QFile file(":/README.md");
    if (!file.open(QIODevice::ReadOnly)) {
        return ;
    }
    ui->textEdit->setText(file.readAll());
    ui->textEdit->setFont(QFont("Consolas", 18));
}
