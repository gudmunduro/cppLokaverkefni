#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Flight booking");
    this->prepareTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addRow(int id, int reserved, int capacity)
{
    int rowPos = ui->flightsTable->rowCount();
    ui->flightsTable->insertRow(rowPos);
    ui->flightsTable->setItem(rowPos, 0, new QTableWidgetItem(QString::number(id)));
    ui->flightsTable->setItem(rowPos, 1, new QTableWidgetItem(QString::number(reserved)));
    ui->flightsTable->setItem(rowPos, 2, new QTableWidgetItem(QString::number(capacity)));
}

void MainWindow::prepareTable()
{
     flightList = new FlightList();

     flightList->add(new FlightBooking(10, 100, 500));
     flightList->add(new FlightBooking(15, 10, 50));

     personList->add(new Person("1000000", "Nafn 1", 25));
     personList->add(new Person("1001000", "Nafn 2", 26));
     personList->add(new Person("1002000", "Nafn 3", 215));
     personList->add(new Person("1003000", "Nafn 4", 6));

     flightList->loop([this] (FlightBooking *flight) {
         this->addRow(flight->getId(), flight->getReserved(), flight->getCapacity());
     });
}

void MainWindow::on_flightsTable_cellDoubleClicked(int row, int column)
{
    int flightID = ui->flightsTable->item(row, 0)->text().toInt();

    FlightInfo *flightInfoWindow = new FlightInfo(nullptr, flightList->get(flightID)->flight);
    flightInfoWindow->show();
}
