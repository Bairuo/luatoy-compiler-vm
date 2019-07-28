#include "codeedit.h"
#include <Qsci/qscilexerlua.h>
#include <Qsci/qscilexercpp.h>
#include <QVBoxLayout>
#include <QMenu>
#include <QDebug>

CodeEdit::CodeEdit(QWidget *parent) :
    QWidget(parent)
{   
    editor = new QsciScintilla;

//    // Font
//    QFont font;
//    font.setFamily(QString::fromLocal8Bit("Ubuntu"));
//    font.setPointSize(20);
//    font.setBold(false);
//    font.setItalic(false);
//    font.setUnderline(false);
//    editor->setFont(font);

    // Margin
    editor->setMarginType(0, QsciScintilla::NumberMargin);
    editor->setMarginLineNumbers(0, true);
    editor->setMarginWidth(0, 35);

    editor->SendScintilla(QsciScintilla::SCI_SETCODEPAGE,QsciScintilla::SC_CP_UTF8);

    lexer = new QsciLexerLua();
    editor->setLexer(lexer);

    // 自动补全
    QsciAPIs *apis = new QsciAPIs(lexer);
    apis->add(QString("local"));
    apis->add(QString("function"));
    apis->add(QString("return"));
    apis->add(QString("print"));
    apis->add(QString("for"));
    apis->add(QString("while"));
    apis->add(QString("break"));
    apis->add(QString("if"));
    apis->add(QString("end"));
    apis->add(QString("then"));
    apis->add(QString("elseif"));
    apis->add(QString("else"));
    apis->add(QString("pairs"));
    apis->add(QString("ipairs"));
    apis->add(QString("true"));
    apis->add(QString("false"));
    apis->add(QString("nil"));
    apis->prepare();
    editor->setAutoCompletionSource(QsciScintilla::AcsAll);
    editor->setAutoCompletionCaseSensitivity(true);
    editor->setAutoCompletionThreshold(1);

    //开启自动缩进
    editor->setAutoIndent(true);
    //设置缩进的显示方式
    editor->setIndentationGuides(QsciScintilla::SC_IV_LOOKBOTH);
    //显示选中的行号
    editor->setCaretLineVisible(true);
    //显示选中行号的背景色
    editor->setCaretLineBackgroundColor(Qt::lightGray);
    //左侧行号显示的背景色
    editor->setMarginsBackgroundColor(Qt::gray);
    //设置括号匹配
    editor->setBraceMatching(QsciScintilla::SloppyBraceMatch);

    QVBoxLayout *pLayout = new QVBoxLayout(this);
    pLayout->addWidget(editor);
    pLayout->setContentsMargins(0, 0, 0, 0);
}


CodeEdit::~CodeEdit()
{

}

void CodeEdit::setReadOnly(bool canRead)
{
    if(editor != nullptr)
    {
        editor->setReadOnly(canRead);
    }
}

void CodeEdit::setText(const QString &text)
{
    if(editor != nullptr)
    {
        editor->setText(text);
    }
}

void CodeEdit::append(const QString &text)
{
    if(editor != nullptr && text != "")
    {
        editor->append(text);
        editor->append("\n");
    }
}

QString CodeEdit::text() const
{
    if(editor != nullptr)
    {
        return editor->text();
    }

    return "";
}

void CodeEdit::clear()
{
    if(editor != nullptr)
    {
        editor->clear();

        //isToken = false;
        //action->setText("token");
    }
}

