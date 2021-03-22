#ifndef TASK_H
#define TASK_H

#include <QList>
#include <QMap>

class Task;

typedef QList<Task*> TaskList;

class Task
{
public:
    class Locale {
    public:
        QString en_US;
        QString zh_CN;
        Locale(const QString &s = QString()) {
            en_US = s;
        }
        operator QString() {
            return en_US;
        }
    };
    
    class Options {
    public:
        QString cwd;
        QMap<QString, Locale> env;
    };
    
    class Input {
    public:
        QString id;
        QString type;
        Locale description;
        QStringList options;
    };
    
    class Button {
    public:
        Locale text;
    };
    
    class Message {
    public:
        QString id;
        QString type;
        Locale title;
        Locale text;
        Locale detailedText;
        QList<Button> buttons;
    };

    static const QString JSON_NAME;
    
    static const QString ICON_NAME;
    
    static const QString DIR_NAME;
    
    static bool tryDelete(Task *&task);
    
    enum Kind {
        Node,
        Windows,
        Linux,
        Osx
    };
    Task(Task *parent = nullptr, Kind kind = Node);
    
    ~Task();
    
    QString path;
    
    Task *parent;
    
    TaskList children;
    
    Kind kind;
    
    // ------------------- //
    
    QString version;
    
    Locale label;
    
    QString shortcut;
    
    QString command;
    
    QList<Locale> args;
    
    Options options;
    
    QList<Input> inputs;
    
    QList<Message> messages;
    
    Task *windows;
    
    Task *osx;
    
    Task *linux;
};

#endif // TASK_H
