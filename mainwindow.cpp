#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_provider = SystemInfoProvider();
    int horizontal = 0, vertical = 0;
    m_provider.getDesktopResolution(horizontal, vertical);
    this->resize(horizontal, vertical);
    ui->label->setText(QString("The info about the system will be here soon!"));
}

MainWindow::~MainWindow()
{
    if(m_plot_builder){
        delete m_plot_builder;
    }
    delete ui;
}


#include <thread>
void MainWindow::on_graph_clicked()
{

    if (m_plot_builder) {
        delete m_plot_builder;
        m_plot_builder = nullptr;
    }

    QList<qreal> data;
    auto begin = std::chrono::steady_clock::now();
    while(1){
        auto end = std::chrono::steady_clock::now();
        if(std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() > 30){
            break;
        }
        ULONGLONG mem = 0;
        try{
            mem = m_provider.printMemoryStatus();
        }
        catch(const std::runtime_error& e){
            qDebug() << e.what();
        }
        data.push_back(mem);
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    m_plot_builder = new PlotBuilder();
    m_plot_builder->setTitle("RAM");
    try{
        m_plot_builder->setData(data);
    }
    catch(const std::invalid_argument& e){
        qDebug() << e.what();
    }
    m_plot_builder->showBarPlot();
}

