#ifndef CLOGTABLE_H
#define CLOGTABLE_H

#include <QTableWidget>

class LogTable : public QTableWidget
{
    Q_OBJECT
public:
    explicit LogTable(QWidget *parent = nullptr);
    void appendLog(QString type, QString text);
signals:
private:
    int totalRows = 0;
};

#endif // CLOGTABLE_H
