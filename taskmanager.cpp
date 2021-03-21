#include "taskmanager.h"
#include "ui_taskmanager.h"

#include <QFile>

#include "tasksystemmodel.h"
#include "task.h"

TaskManager::TaskManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskManager)
{
    ui->setupUi(this);
    connect(ui->taskSystemView, &QAbstractItemView::clicked,
            this, &TaskManager::setupTask);
}

TaskManager::~TaskManager()
{
    delete ui;
}

void TaskManager::setTaskSystemModel(TaskSystemModel *model)
{
    ui->taskSystemView->setModel(model);
}

void TaskManager::setupTask(const QModelIndex &index)
{
    Task *task = static_cast<Task*>(index.internalPointer());
    QFile file(task->path + "/" + Task::JSON_NAME);
    if (!file.open(QFile::ReadOnly)) {
        return ;
    }
    ui->taskEdit->setText(file.readAll());
    ui->taskEdit->setFont(QFont("Consolas", 12));
    file.close();
}
