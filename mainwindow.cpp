#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    flightList = new FlightList();

    flightList->load();

    personList->add(new Person("1000000", "Nafn 1", 25));
    personList->add(new Person("1001000", "Nafn 2", 26));
    personList->add(new Person("1002000", "Nafn 3", 215));
    personList->add(new Person("1003000", "Nafn 4", 6));

    ui->setupUi(this);
    this->setWindowTitle("Flight booking");
    this->reloadTable();
}

MainWindow::~MainWindow()
{
    flightList->save();
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

void MainWindow::reloadTable()
{   
    ui->flightsTable->setRowCount(0);
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

void MainWindow::on_removeFlightButton_clicked()
{
    if (ui->flightsTable->selectedItems().count() == 0) return;

    int flightID = ui->flightsTable->item(ui->flightsTable->selectedItems().first()->row(), 0)->text().toInt();
    flightList->remove(flightID);

    reloadTable();
}

void MainWindow::on_addFlightButton_clicked()
{
    AddFlightDialog *dialog = new AddFlightDialog();
    dialog->exec();
    if (dialog->shouldAdd && !flightList->exists(dialog->selectedID)) {
        FlightBooking *flight = new FlightBooking(dialog->selectedID, 0, dialog->selectedCapacity);
        flightList->add(flight);
        reloadTable();
    }
}
