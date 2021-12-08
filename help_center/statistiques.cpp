#include "statistiques.h"
#include "ui_statistiques.h"

statistiques::statistiques(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::statistiques)
{
    ui->setupUi(this);

    QPieSeries *series=new QPieSeries();

    series->append("< 2",tmpc.calcul_An(0,2));
    series->append("[2..5]",tmpc.calcul_An(2,5));
    series->append("[5..10]",tmpc.calcul_An(5,10));
    series->append("[10..25]",tmpc.calcul_An(10,25));



    QPieSlice *slice1=series->slices().at(1);
    slice1->setExploded(true);

    QChart *chart =new QChart();
    chart->addSeries(series);
    chart->setTitle("les annes d'experiences");
    chart->setAnimationOptions(QChart::AllAnimations);
    QChartView *chartview=new QChartView(chart);

    this->setCentralWidget(chartview);
}

statistiques::~statistiques()
{
    delete ui;
}
