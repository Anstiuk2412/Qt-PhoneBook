#include <QApplication>
#include "listdialog.h"
#include "ui_listdialog.h"
#include "editdialog.h"

listdialog::listdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::listdialog)
{
    ui->setupUi(this);

    connect( ui->addButton, SIGNAL( clicked() ), this, SLOT( addItem() ) );
    connect( ui->editButton, SIGNAL( clicked() ), this, SLOT( editItem() ) );
    connect( ui->deleteButton, SIGNAL( clicked() ), this, SLOT( deleteItem() ) );
}

listdialog::~listdialog()
{
    delete ui;
}





void listdialog::addItem()
{
   editdialog dlg( this );
   if( dlg.exec() == QDialog::Accepted )
       ui->list->addItem( dlg.name() + " -- " + dlg.number() );
}

void listdialog::editItem()
{
  if( !ui->list->currentItem() )
      return;
  QStringList parts = ui->list->currentItem()->text().split( "--" );

  editdialog dlg( this );
  dlg.setName( parts[0].trimmed() );
  dlg.setNumber( parts[1].trimmed() );

  if( dlg.exec() == QDialog::Accepted )
      ui->list->currentItem()->setText( dlg.name() + " -- " + dlg.number() );
}

void listdialog::deleteItem()
{
   delete ui->list->currentItem();
}
