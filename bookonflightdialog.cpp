#include "bookonflightdialog.h"
#include "ui_bookonflightdialog.h"

BookOnFlightDialog::BookOnFlightDialog(QWidget *parent, FlightBooking *flight) :
    QDialog(parent),
    ui(new Ui::BookOnFlightDialog)
{
    ui->setupUi(this);
    this->flight = flight;
    this->prepareTable();
    this->setWindowTitle("Persons");
}

BookOnFlightDialog::~BookOnFlightDialog()
{
    delete ui;
}

void BookOnFlightDialog::addRow(string ssn, string name, int age)
{
    int rowPos = ui->personTable->rowCount();
    ui->personTable->insertRow(rowPos);
    ui->personTable->setItem(rowPos, 0, new QTableWidgetItem(QString::fromStdString(ssn)));
    ui->personTable->setItem(rowPos, 1, new QTableWidgetItem(QString::fromStdString(name)));
    ui->personTable->setItem(rowPos, 2, new QTableWidgetItem(QString::number(age)));
}

void BookOnFlightDialog::prepareTable()
{
    personList->loop([this] (Person *person) {
        this->addRow(person->getSsn(), person->getName(), person->getAge());
    });
}

void BookOnFlightDialog::on_bookButton_clicked()
{
    if (ui->personTable->selectedItems().count() == 0) return;
    selectedPersonSSN = ui->personTable->item(ui->personTable->selectedItems().first()->row(), 0)->text().toStdString();
    if (this->flight->getPassangerSSNs().contains(selectedPersonSSN)) selectedPersonSSN = "";
    this->close();
}

void BookOnFlightDialog::on_cancelButton_clicked()
{
    this->close();
}
