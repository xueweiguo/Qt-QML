#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtAlgorithms>
#include <QKeyEvent>

#include "functionmanager.h"
#include "helpdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->questionEdit->setHelper(this);

    engine.registerRecordFunction();

    FunctionManager* manager = FunctionManager::getInstance();
    QList<QString> functions = manager->functions();

    foreach(QString funName, functions)
    {
      ui->listFunction->addItem(funName);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
    qDeleteAll(mTokenList);
    FunctionManager::clearInstance();
}

void MainWindow::selectNext()
{
    QModelIndex modelIndex = ui->listFunction->currentIndex();
    int row = modelIndex.row();
    if(row < ui->listFunction->count() - 1)
    {
        QModelIndex nextIndex = modelIndex.sibling(modelIndex.row() + 1, 0);
        ui->listFunction->setCurrentIndex(nextIndex);
    }
}

void MainWindow::selectPrev()
{
    QModelIndex modelIndex = ui->listFunction->currentIndex();
    int row = modelIndex.row();
    if(row > 0)
    {
        QModelIndex nextIndex = modelIndex.sibling(modelIndex.row() - 1, 0);
        ui->listFunction->setCurrentIndex(nextIndex);
    }
}

void MainWindow::applyCurrent()
{
    int curTokenIndex = findCurrentToken();
    QListWidgetItem* item = ui->listFunction->currentItem();
    if(curTokenIndex != -1 && item != NULL)

    {
        Token* currentToken = mTokenList.at(curTokenIndex);

        currentToken->setContent(item->text() + "()");
        ui->questionEdit->setText(buildQuestionFromToken());

        int beginIndex = 0;
        int tokenIndex = 0;
        foreach(Token* token, mTokenList)
        {
            QString content = token->getContent();
            int endIndex = beginIndex + content.length();
            if(tokenIndex == curTokenIndex + 1)
            {
                ui->questionEdit->setCursorPosition(endIndex);
                ui->questionEdit->setFocus();
                break;
            }
            beginIndex = endIndex;
            ++tokenIndex;
        }
    }
}

void MainWindow::on_questionEdit_returnPressed()
{
    QLineEdit* edit = ui->questionEdit;
    QString question = edit->text();
    if(question.length() > 0)
    {
        QString answer = engine.calculate(ui->questionEdit->text());
        ui->answerEdit->setText(answer);
        QString dummy;
        on_listFunction_currentTextChanged(dummy);
        ui->questionEdit->selectAll();
    }
}

int MainWindow::findCurrentToken()
{
    QLineEdit* edit = ui->questionEdit;

    int curIndex = edit->cursorPosition();
    if(curIndex == -1) return -1;

    if(mTokenList.count() > 0)
    {
        int tokenIndex = 0;
        int beginIndex = 0;
        foreach(Token* token, mTokenList)
        {
            QString content = token->getContent();
            int endIndex = beginIndex + content.length();
            if((token->getType() == Token::FunctionName || token->getType() == Token::NoType)
                &&(curIndex >= beginIndex && curIndex < endIndex + 1))
            {
                return tokenIndex;
            }
            beginIndex = endIndex;
            ++tokenIndex;
        }
    }
    return -1;
}

QString MainWindow::buildQuestionFromToken()
{
    QString question;
    foreach(Token* token, mTokenList)
    {
        question += token->getContent();
    }
    return question;
}

void MainWindow::on_questionEdit_textChanged(const QString &arg1)
{
    QString question = ui->questionEdit->text();
    if(question.indexOf(" ") != -1)
    {
        question.remove(" ");
        ui->questionEdit->setText(question);
    }
    question.remove(" ");
    qDeleteAll(mTokenList);
    mTokenList = engine.analyzeToken(arg1);
    int curTokenIndex = findCurrentToken();
    if(curTokenIndex != -1)
    {
        Token* currentToken = mTokenList.at(curTokenIndex);
        QListWidget* list = ui->listFunction;
        QList<QListWidgetItem *> items = list->findItems(currentToken->getContent(), Qt::MatchStartsWith);
        if(items.count() > 0)
        {
            list->setCurrentItem(items.first());
        }
    }
}

void MainWindow::on_listFunction_currentTextChanged(const QString &/*currentText*/)
{
    QListWidgetItem* item = ui->listFunction->currentItem();
    if(item != NULL)
    {
        FunctionManager* manager = FunctionManager::getInstance();
        CalculateFunction* fun = manager->getFunction(item->text());
        ui->textInstruction->setText(fun->getInstruction());
    }
    else
    {
        ui->textInstruction->setText("");
    }
}


void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionAbout_triggered()
{
    HelpDialog dlg(this);
    dlg.exec();
}
