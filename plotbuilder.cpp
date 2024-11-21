#include "plotbuilder.h"
#include "qbarset.h"
#include "qvalueaxis.h"

PlotBuilder::PlotBuilder(const QList<qreal> data, const QString title) : m_data(data), m_title(title){
    m_chart = new QChart();
    m_chart->setTitle(m_title);
    m_view = new QChartView();
}
PlotBuilder::PlotBuilder(){
    m_chart = new QChart();
    m_view = new QChartView();
}
PlotBuilder::~PlotBuilder(){
    if(m_chart != nullptr){
        delete m_chart;
    }
    if(m_view != nullptr){
        delete m_view;
    }
}

void PlotBuilder::showBarPlot() {
    QBarSeries *plot = new QBarSeries();
    QBarSet *barset = new QBarSet("My set");

    for (qreal d : m_data) {
        *barset << d;
    }

    plot->append(barset);

    // Create axes
    QValueAxis *axisX = new QValueAxis();
    QValueAxis *axisY = new QValueAxis();
    axisX->setTitleText("Categories");
    axisY->setTitleText("Values");

    m_chart->addSeries(plot);
    m_chart->addAxis(axisX, Qt::AlignBottom);
    m_chart->addAxis(axisY, Qt::AlignLeft);

    plot->attachAxis(axisX);
    plot->attachAxis(axisY);

    m_view->setChart(m_chart);
    m_view->show();
}

void PlotBuilder::setData(const QList<qreal> data){
    if(data.size() == 0){
        throw std::invalid_argument("The data is empty!");
    }
    m_data = data;
}
void PlotBuilder::setTitle(const QString title){
    m_title = title;
    m_chart->setTitle(m_title);
}
QList<qreal> PlotBuilder::getData() const{
    return m_data;
}
QString PlotBuilder::getTitle() const{
    return m_title;
}
