#include "recorder.h"

Recorder::Recorder()
{

}

Recorder::~Recorder()
{

}

//*****************
// 初始化路径
//*****************
void Recorder::initFileStream(QString currentDir)
{
    outFilePath = currentDir+"//label.txt";
}

//*****************
// 添加一条记录到list
//*****************
void Recorder::appendStringList(QString fileName, vector<float> params, bool imgSign)
{
    QString outStr = fileName;
    for (int i = 0; i < params.size(); i++){
        float number = params[i];
        outStr += "      " + QString::number(number);
    }
    outStr += "      " + QString::number(imgSign);	//增加标记为，标记图片是否为劣质图片

    strList.append(outStr);
}


//*****************
// 把list写入到txt文件
//*****************
void Recorder::writeDataFile()
{
    //write to txt
    QFile f(outFilePath);
    if (!f.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug("Open Failed.");
        return;
    }
    QTextStream txt(&f);

    for (int i = 0; i < strList.count(); i++)
    {
        txt << strList.at(i) <<endl;
    }

    f.close();
}

//###记录解析的视频名称到.txt文件
void Recorder::writeLog(QString str)
{
    //write to txt
    QFile f("log.txt");
    if (!f.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug("Open Failed.");
        return;
    }
    QTextStream txt(&f);

    txt << str;

    f.close();
}

