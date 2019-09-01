#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qdebug.h>
#include <qfiledialog.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    openAction(nullptr)
{
    ui->setupUi(this);

    // QStringLiteral 可解决中文乱码问题
     setWindowTitle(QStringLiteral("Action使用方法探究"));

     // 创建action
     openAction = new QAction(QIcon(), QStringLiteral("打开..."), this);//new 了之后要释放内存（delete）,不然会造成内存泄漏
     openAction->setShortcuts(QKeySequence::Open);//说明这个QAction的快捷键Ctrl+O，也可以自定义
     openAction->setStatusTip(tr("Open an existing file"));//etStatusTip()实现了当用户鼠标滑过这个 action 时，会在主窗口下方的状态栏显示相应的提示
     connect(openAction, &QAction::triggered, this, &MainWindow::Open);

     QMenu *file = menuBar()->addMenu(QStringLiteral("文件"));
     file->addAction(openAction);

     ui->toolButton->setDefaultAction(openAction);
}

void MainWindow::Open()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    QStringLiteral("文件对话框！"),
                                                     "F:",
                                                       QStringLiteral("图片文件(*png *jpg);;" "文本文件(*txt)"));
}

MainWindow::~MainWindow()
{
    delete ui;

    if (openAction)
    {
        delete openAction;
        openAction = nullptr;
    }
}
