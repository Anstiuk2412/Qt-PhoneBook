#ifndef LISTDIALOG_H
#define LISTDIALOG_H

#include <QDialog>

namespace Ui {
class listdialog;
}

class listdialog : public QDialog
{
    Q_OBJECT

public:
    explicit listdialog(QWidget *parent = 0);
    ~listdialog();

private slots:
    void addItem();
    void editItem();
    void deleteItem();



private:
    Ui::listdialog *ui;


};

#endif // LISTDIALOG_H
