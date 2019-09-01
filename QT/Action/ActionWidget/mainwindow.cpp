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

    // QStringLiteral �ɽ��������������
     setWindowTitle(QStringLiteral("Actionʹ�÷���̽��"));

     // ����action
     openAction = new QAction(QIcon(), QStringLiteral("��..."), this);//new ��֮��Ҫ�ͷ��ڴ棨delete��,��Ȼ������ڴ�й©
     openAction->setShortcuts(QKeySequence::Open);//˵�����QAction�Ŀ�ݼ�Ctrl+O��Ҳ�����Զ���
     openAction->setStatusTip(tr("Open an existing file"));//etStatusTip()ʵ���˵��û���껬����� action ʱ�������������·���״̬����ʾ��Ӧ����ʾ
     connect(openAction, &QAction::triggered, this, &MainWindow::Open);

     QMenu *file = menuBar()->addMenu(QStringLiteral("�ļ�"));
     file->addAction(openAction);

     ui->toolButton->setDefaultAction(openAction);
}

void MainWindow::Open()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    QStringLiteral("�ļ��Ի���"),
                                                     "F:",
                                                       QStringLiteral("ͼƬ�ļ�(*png *jpg);;" "�ı��ļ�(*txt)"));
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
