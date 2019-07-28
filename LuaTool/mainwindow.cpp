#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "codeedit.h"
#include <QString>
#include <QDir>
#include <QFileDialog>
#include <fstream>
#include <sstream>
#include <QDebug>
#include <QProcess>

using namespace std;

static QProcess *proc = new QProcess();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    CodeEdit *codeEdit1 = new CodeEdit;
    QTextEdit *cmpInfo = new QTextEdit;

    cmpInfo->setReadOnly(true);

    ui->layout1->addWidget(codeEdit1);
    ui->layout1->addWidget(cmpInfo);
    ui->layout1->setStretch(0, 1);
    ui->layout1->setStretch(1, 1);

    codeEdit1->setObjectName(QString("codeEdit1"));
    cmpInfo->setObjectName(QString("cmpInfo"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


QString getFileContent(const QString &filepath)
{
    ifstream in;
    stringstream buffer;
    in.open(filepath.toStdString());

    if(in.is_open())
    {
        buffer << in.rdbuf();
    }

    return QString::fromStdString(buffer.str());
}

void writeFileContent(const QString &filepath, const QString &content)
{
    ofstream out;
    out.open(filepath.toStdString());

    if(out.is_open())
    {
        out << content.toStdString();
    }
}

void MainWindow::on_toolButton_clicked()
{
    CodeEdit *codeEdit = this->findChild<CodeEdit *>("codeEdit1");

    QString filename = QFileDialog::getOpenFileName(this, QObject::tr("文件选择"), "/home/bairuo/LuaTool/examples/");

    ui->src1->setText(filename);
    ui->infoDisplay->append(filename);

    codeEdit->clear();
    codeEdit->append(getFileContent(filename));
}

void MainWindow::on_clearButton_clicked()
{
    ui->infoDisplay->clear();

    QTextEdit *cmpInfo = this->findChild<QTextEdit *>("cmpInfo");
    cmpInfo->clear();
}

QString getCmdRes(QString command)
{
    QStringList pars;

    pars << "-c" << command;

    proc->start("/bin/bash", pars);
    while(proc->waitForFinished());

    return proc->readAll();
}

void MainWindow::on_runButton_clicked()
{
    CodeEdit *codeEdit = this->findChild<CodeEdit *>("codeEdit1");
    QTextEdit *cmpInfo = this->findChild<QTextEdit *>("cmpInfo");

    writeFileContent("/home/bairuo/luavm/tool/edit", codeEdit->text());

    getCmdRes("/home/bairuo/luavm/bin/luago /home/bairuo/luavm/tool/edit > /home/bairuo/luavm/tool/output");

    cmpInfo->setText("抽象语法树:");
    cmpInfo->append(getFileContent("/home/bairuo/luavm/tool/ast"));

    cmpInfo->append("\n符号表:");
    cmpInfo->append(getFileContent("/home/bairuo/luavm/tool/varinfo"));

    ui->infoDisplay->append(getFileContent("/home/bairuo/luavm/tool/info"));

    ui->infoDisplay->append(getFileContent("/home/bairuo/luavm/tool/output"));
}
