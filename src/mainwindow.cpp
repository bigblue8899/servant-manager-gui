#include "mainwindow.h"
#include "VirtualMachine.hpp"
#include <QDebug>
#include <QDir>

QObject *MainWindow::ui = nullptr;

MainWindow::MainWindow(QObject *ui) : QObject()
{
    connect(this, &MainWindow::servantBaseIsReady, this, &MainWindow::initialServantManager);
    MainWindow::ui = ui;
    loadingScreen = new LoadingScreen;
    loadingScreen->setVisible(true);
    loadingScreen->setStatusText(L"Getting Ready...");
    std::thread(&MainWindow::initialServantBase, this).detach();
}

MainWindow::~MainWindow()
{
    if(loadingScreen)
        delete loadingScreen;
    if(firstTimeSetup)
        delete firstTimeSetup;
}

QObject *MainWindow::getUi()
{
    return ui;
}

void MainWindow::initialServantBase()
{
    ServantBase::getInstance()->initialWithLocalWrapper();
    emit servantBaseIsReady();
}

void MainWindow::initialServantManager()
{
    mall = new Mall;
    myServer = new MyServer;
    if(ServantBase::getInstance()->getPackageManager()->isFirstTime())
    {
        firstTimeSetup = new FirstTimeSetup;
        firstTimeSetup->setVisible(true);
    }
    else
    {
        controlPane = ui->findChild<QObject*>("controlPane");
        if(ServantBase::getInstance()->getPackageManager()->getMachines()->empty())
        {
            controlPane->setProperty("noMachineCreated", true);
        }else
        {
            controlPane->setProperty("noMachineCreated", false);
            myServer->updateServerQuickAction();
        }
    }
    loadingScreen->setVisible(false);
}


