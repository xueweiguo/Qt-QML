#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


bool MainWindow::close()
{
    return QMainWindow::close();
}

bool MainWindow::inputTextChanged()
{
    ui->logTable->appendLog("textChanged", ui->InputEditBox->toPlainText());
    return true;
}
