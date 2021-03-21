#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardPaths>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
private slots:
    void on_actionOpenUserTaskFolder_triggered();
    
    void on_actionOpenDefaultTaskFolder_triggered();
    
private:
    void openTaskFolder(QStandardPaths::StandardLocation location);
    
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
