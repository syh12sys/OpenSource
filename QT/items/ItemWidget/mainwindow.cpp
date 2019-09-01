#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InitWidgets();
}

 void MainWindow::InitWidgets()
 {
    ui->mainToolBar->addAction(ui->actListInit);
    ui->mainToolBar->addAction(ui->actListClear);
    ui->mainToolBar->addAction(ui->actListInsert);
    ui->mainToolBar->addAction(ui->actListAppend);
    ui->mainToolBar->addAction(ui->actListDelete);

    ui->tBtnListInit->setDefaultAction(ui->actListInit);
    ui->tBtnListClear->setDefaultAction(ui->actListClear);
    ui->tBtnListInsert->setDefaultAction(ui->actListInsert);
    ui->tBtnListAppend->setDefaultAction(ui->actListAppend);
    ui->tBtnListDelete->setDefaultAction(ui->actListDelete);

    connect(ui->actListInit, &QAction::triggered, this, &MainWindow::onActListInitTrigger);
 }

 void MainWindow::onActListInitTrigger()
 {
    qDebug() << "onActListInitTrigger \n";
    ui->listWidget->clear();
    for (int i= 0; i < 10; i++) {
        QListWidgetItem *aItem = new QListWidgetItem;
        aItem->setText(QString::asprintf (" %d item", i));
        aItem->setCheckState(Qt::Checked);
        if (ui->checkBox->isChecked())
        {
            aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable |Qt::ItemIsUserCheckable |Qt::ItemIsEnabled);
        }
        else
        {
            aItem->setFlags(Qt::ItemIsSelectable |Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        }
        ui->listWidget->addItem(aItem);
    }
 }

MainWindow::~MainWindow()
{
    delete ui;
}
