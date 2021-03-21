#include "taskhighlighter.h"

TaskHighlighter::TaskHighlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;
    
    //numbers
    rule.pattern = QRegularExpression("([-0-9.]+)(?!([^\"]*\"[\\s]*\\:))");
    rule.format.setForeground(Qt::darkRed);
    rules.append(rule);

    
    //middle
    rule.pattern = QRegularExpression("(?:[ ]*\\,[ ]*)(\"[^\"]*\")");
    rule.format.setForeground(Qt::darkGreen);
    rules.append(rule);

    //last
    rule.pattern = QRegularExpression("(\"[^\"]*\")(?:\\s*\\])");
    rule.format.setForeground(Qt::darkGreen);
    rules.append(rule);


    //string:
    rule.pattern = QRegularExpression("(\"[^\"]*\")\\s*\\:");
    rule.format.setForeground(Qt::darkBlue);
    rules.append(rule);

    rule.pattern = QRegularExpression(":+(?:[: []*)(\"[^\"]*\")");
    rule.format.setForeground(Qt::darkGreen);
    rules.append(rule);
}

void TaskHighlighter::highlightBlock(const QString &text)
{
    //object
    for (const auto &rule : qAsConst(rules)) {
        auto i = rule.pattern.globalMatch(text);
        while (i.hasNext()) {
            auto match = i.next();
            setFormat(match.capturedStart(1), match.capturedLength(1), rule.format);
        }
    }
}
