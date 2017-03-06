#ifndef DATABASE_H
#define DATABASE_H

#include "common.h"

#include <QtSql\qsql.h>
#include <QtSql\qsqldatabase.h>
#include <QtSql\qsqlquery.h>
#include <QtSql\qsqltablemodel.h>
#include <QtSql\qsqlerror.h>

enum SQLType
{
    TypeCreate = 0,
    TypeSelect,
    TypeInsert,
    TypeUpdate,
    TypeDelete,
    TypeClear,
    TypeSelectAll,
};

enum VideoType
{
    SingleOne = 0,
    SingleTwo,
    SingleThree,
    SingleFour,
    SingleFive,
    SingleSix,
    SingleSeven,
    SingleEight,
    SingleNine,
    SingleGood,
    SingleBad,
    PairSix,
    PairSeven,
    PairEight,
    PairNine,
    PairTen,
    TypeError,
};

class Database
{
private:
    QSqlDatabase db;

public:
    Database();
    ~Database();

    //prepare sql command
    VideoType getVideoType(QString videoType);	//change QString videoType into enum VideoType
    int getCorrectParamCcount(QString videoType);	//return the number of parameter according to QString videoType
    QString getSql(SQLType type,QString videoType);
    void prepareDB(QString targetDir,QString videoType);

    //select
    vector<float> execSelect(int index, QString currentImgName,QString videoType);
    //insert or update
    void execInsert(int index, QString fileName, vector<float> params, bool imgSign, QString videoType);
    //write
    void convertDBtoTxt(QString targetDir,QString videoType);
};


#endif // DATABASE_H
