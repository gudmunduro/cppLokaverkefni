#include "addflightdialog.h"
#include "ui_addflightdialog.h"

AddFlightDialog::AddFlightDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddFlightDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Add flight");
}

AddFlightDialog::~AddFlightDialog()
{
    delete ui;
}

void AddFlightDialog::on_addFlight_clicked()
{
    if (ui->idLineEdit->text().isEmpty() || ui->capacityLineEdit->text().isEmpty()) return;
    shouldAdd = true;
    selectedID = ui->idLineEdit->text().toInt();
    selectedCapacity = ui->capacityLineEdit->text().toInt();
    this->close();
}

void AddFlightDialog::on_cancelButton_clicked()
{
    shouldAdd = false;
    this->close();
}
