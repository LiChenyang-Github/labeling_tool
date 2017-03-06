#ifndef COLLECTOR_H
#define COLLECTOR_H

#include <QMainWindow>
#include "ui_collector.h"

#include "common.h"

#include <QDir>
#include <QShortCut>
#include <QMouseEvent>
#include <QFileDialog>
#include <QLayout>

//class to process mat
#include "processor.h"
//class to record data
#include "recorder.h"
//class to create databse
#include "database.h"

#include "imagewidget.h"


namespace Ui {
class collector;
}

class collector : public QMainWindow
{
    Q_OBJECT

public:
    explicit collector(QWidget *parent = 0);
    ~collector();

private:
    Ui::collector *ui;
    ImageWidget *imgWidget;

    //core identification of image in path name
    int index;
    int minCount;
    int maxCount;

    QString targetDir;
    QString targetBaseName;

    QString currentImageName;

    QString videoType;	//just like "SingleOne" "PairSix" etc.

    //mat processor
    Processor proc;
    //sqlite db
    Database db;

private slots:
    void on_videoButt_clicked();

    void on_selectButt_clicked();

    void on_startButt_clicked();

    void on_endButt_clicked();

    void on_lastButt_clicked();

    void on_nextButt_clicked();

    void on_lastPoint_clicked();

    void on_passButt_clicked();

protected:
    void mousePressEvent(QMouseEvent *e);

public:
    //auxilary function
    void updateWithIndex(int index);
    void recordDataIntoDb(QString videoType);
    void recordPassDataIntoDb();	//for img in low quality

    //display funcion of ui
    void displayMat(Mat img);
    void displayData();

};

#endif // COLLECTOR_H
