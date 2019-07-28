#ifndef CODEEDIT_H
#define CODEEDIT_H

#include <QWidget>
#include <QString>
#include <Qsci/qsciscintilla.h>
#include <Qsci/qsciapis.h>
#include <Qsci/qscilexer.h>
#include <QString>

namespace  Ui {
class CodeEdit;
}

class CodeEdit : public QWidget
{
    Q_OBJECT

public:
    explicit CodeEdit(QWidget *parent = 0);
    void setReadOnly(bool canRead);
    void setText(const QString &text);
    void append(const QString &text);
    QString getSource();
    QString text() const;
    void clear();
    ~CodeEdit();

private:
    QsciScintilla *editor = nullptr;
    QsciLexer *lexer = nullptr;
};


#endif // CODEEDIT_H
