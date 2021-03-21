#include "taskmanager.h"
#include "ui_taskmanager.h"

#include "tasksystemmodel.h"

TaskManager::TaskManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskManager)
{
    ui->setupUi(this);
}

TaskManager::~TaskManager()
{
    delete ui;
}

void TaskManager::setTaskSystemModel(TaskSystemModel *model)
{
    ui->taskSystemView->setModel(model);
    auto index = model->index(model->rootPath());
    ui->taskSystemView->setRootIndex(index);
}
