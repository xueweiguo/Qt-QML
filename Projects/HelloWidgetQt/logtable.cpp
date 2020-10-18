#include <QDateTime>
#include <QTableWidgetItem>
#include <QTableWidgetSelectionRange>
#include "logtable.h"

LogTable::LogTable(QWidget *parent) : QTableWidget(parent)
{

}

void LogTable::appendLog(QString type,QString text)
{
    setRowCount(totalRows + 1);
    QDateTime datetime=QDateTime(QDateTime::currentDateTime());
    QString date_str = datetime.toString("hh:mm:ss.zzz");
    QTableWidgetItem* date_item =new QTableWidgetItem(date_str);
    setItem(totalRows , 0, date_item);
    setItem(totalRows , 1, new QTableWidgetItem(type));
    setItem(totalRows , 2, new QTableWidgetItem(text));
    setCurrentCell(totalRows, 0, QItemSelectionModel::Current
                   | QItemSelectionModel::Columns);
    totalRows++;
}
