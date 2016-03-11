#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMainWindow::showMaximized();

    QFont customFont("Arial", 35, QFont::Bold);
    ui->mainTextEdit->setFont(customFont);
    symbolScrollArea = new QScrollArea;

    ui->tabWidget->removeTab(0);
    ui->tabWidget->removeTab(0);
    ui->tabWidget->addTab(symbolScrollArea, "Symbols");


    symbolSelection = new ScientificNotationSelection(this);

    QStringList capitalGreekList = symbolSelection->generateSelectionList(CapitalGreek);
    capitalGreekButtons = symbolSelection->generateWidgets(capitalGreekList, symbolScrollArea);

    QGridLayout *symbolLayout = new QGridLayout;
    symbolScrollArea->setLayout(symbolLayout);


    int row = 0, column = 0;

    foreach(symbolButton, capitalGreekButtons)
    {
        if(column == 5)
        {
            column = 0;
            row++;
        }
        else
            column++;

        symbolButton->setMaximumSize
                (QSize(symbolScrollArea->width() / 5, symbolScrollArea->height() / 20));

        symbolLayout->addWidget(symbolButton, row, column);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

