#include "helpdialog.h"
#include "ui_helpdialog.h"

//#include <QtWebKit/QWebView>

HelpDialog::HelpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpDialog)
{
    ui->setupUi(this);
}

HelpDialog::~HelpDialog()
{
    delete ui;
}
