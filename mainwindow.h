#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once
#pragma execution_character_set("utf-8")//display chinese words

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/types_c.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/ml.hpp>
#include <QFileDialog>
#include <QVector>
#include <iostream>
#include <algorithm>
#include <limits>
#include <qmath.h>
#include <vector>
#include <opencv2/calib3d/calib3d.hpp>
#include "opencv2/calib3d.hpp"
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <stdio.h>
#include <fstream>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/highgui.hpp>
#include <opencv2/optflow/motempl.hpp>
#include <opencv2/xfeatures2d.hpp>
#include "opencv2/imgcodecs/legacy/constants_c.h"
using namespace cv;
using namespace std;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    Mat srcImg, grayImg, noiseImg;

private slots:
    void on_pushButton_clicked();

    //    void on_checkBox_stateChanged();
private:
    Ui::MainWindow* ui;
};
#endif // MAINWINDOW_H