#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>

#include "questionedit.h"
#include "token.h"
#include "calculateengine.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
                    ,public QuestionEdit::QuestionEditHelper
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    virtual void selectNext();
    virtual void selectPrev();
    virtual void applyCurrent();
private slots:
    void on_questionEdit_returnPressed();

    void on_questionEdit_textChanged(const QString &arg1);

    void on_listFunction_currentTextChanged(const QString &currentText);

    void on_actionExit_triggered();

    void on_actionAbout_triggered();

private:
    int findCurrentToken();
    QString buildQuestionFromToken();
    Ui::MainWindow *ui;
    QList<Token*> mTokenList;
    CalculateEngine engine;
};

#endif // MAINWINDOW_H
