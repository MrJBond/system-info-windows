#ifndef PLOTBUILDER_H
#define PLOTBUILDER_H

#include "qchart.h"
#include "qchartview.h"
#include "qvalueaxis.h"
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QBarSeries>

class PlotBuilder
{
private:
    QChart *m_chart = nullptr;
    QChartView *m_view = nullptr;
    QString m_title = "";
    QList<qreal> m_data;

public:
    PlotBuilder(const QList<qreal> data, const QString title = "Title");
    PlotBuilder();
    ~PlotBuilder();
    void showBarPlot();
    void setData(const QList<qreal> data);
    void setTitle(const QString title);
    QList<qreal> getData() const;
    QString getTitle() const;
};

#endif // PLOTBUILDER_H
