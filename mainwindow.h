#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "plotbuilder.h"
#include <QSizePolicy>
#include "systeminfoprovider.h"

#pragma comment(lib, "wbemuuid.lib")

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_graph_clicked();

private:
    Ui::MainWindow *ui;
    PlotBuilder *m_plot_builder = nullptr;
    SystemInfoProvider m_provider;
};
#endif // MAINWINDOW_H
