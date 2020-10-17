#include "questionedit.h"

#include <QKeyEvent>

QuestionEdit::QuestionEdit(QWidget *parent) :
    QLineEdit(parent)
{
}

void QuestionEdit::setHelper(QuestionEditHelper* _helper)
{
    helper = _helper;
}

void QuestionEdit::keyPressEvent(QKeyEvent * event)
{
    switch(event->key())
    {
        case Qt::Key_Up:
            helper->selectPrev();
        break;
        case Qt::Key_Down:
            helper->selectNext();
        break;
        case Qt::Key_Space:
            helper->applyCurrent();
        break;
        default:
            QLineEdit::keyPressEvent(event);
        break;
    }
}
