#ifndef CRATE_COMMITTEE_H
#define CRATE_COMMITTEE_H

#include <QDialog>

namespace Ui {
class Crate_Committee;
}

class Crate_Committee : public QDialog
{
    Q_OBJECT

public:
    explicit Crate_Committee(QWidget *parent = nullptr);
    ~Crate_Committee();

private:
    Ui::Crate_Committee *ui;
};

#endif // CRATE_COMMITTEE_H
