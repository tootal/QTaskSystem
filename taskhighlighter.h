#ifndef TASKHIGHLIGHTER_H
#define TASKHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QRegularExpression>

class TaskHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    TaskHighlighter(QTextDocument *parent = 0);

protected:
    void highlightBlock(const QString &text) override;

 private:
    struct HighlightingRule
    {
        QRegularExpression pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> rules;
    
    QRegularExpression commentStartExpression;
    QRegularExpression commentEndExpression;
    
    QTextCharFormat keywordFormat;
    QTextCharFormat classFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat functionFormat;
};

#endif // TASKHIGHLIGHTER_H
