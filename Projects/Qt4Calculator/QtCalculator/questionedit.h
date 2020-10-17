#ifndef QUESTIONEDIT_H
#define QUESTIONEDIT_H

#include <QLineEdit>

class QuestionEdit : public QLineEdit
{
    Q_OBJECT
public:
    class QuestionEditHelper
    {
    public:
        virtual void selectNext() = 0;
        virtual void selectPrev() = 0;
        virtual void applyCurrent() = 0;
    };

    explicit QuestionEdit(QWidget *parent = 0);
    virtual void keyPressEvent ( QKeyEvent * event );

    void setHelper(QuestionEditHelper* _helper);
signals:

public slots:

private:
    QuestionEditHelper* helper;
};

#endif // QUESTIONEDIT_H
