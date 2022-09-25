#include "crate_committee.h"
#include "ui_crate_committee.h"

Crate_Committee::Crate_Committee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Crate_Committee)
{
    ui->setupUi(this);
}

Crate_Committee::~Crate_Committee()
{
    delete ui;
}
