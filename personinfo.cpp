#include "personinfo.h"
#include "ui_personinfo.h"

PersonInfo::PersonInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonInfo)
{
    ui->setupUi(this);
}

PersonInfo::~PersonInfo()
{
    delete ui;
}
