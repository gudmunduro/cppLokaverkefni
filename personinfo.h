#ifndef PERSONINFO_H
#define PERSONINFO_H

#include <QDialog>

namespace Ui {
class PersonInfo;
}

class PersonInfo : public QDialog
{
    Q_OBJECT

public:
    explicit PersonInfo(QWidget *parent = nullptr);
    ~PersonInfo();

private:
    Ui::PersonInfo *ui;
};

#endif // PERSONINFO_H
