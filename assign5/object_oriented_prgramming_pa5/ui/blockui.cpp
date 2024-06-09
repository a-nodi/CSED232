#include "blockui.h"
#include <QLabel>
#include <Qstring>
#include <Qt>

BlockUi::BlockUi() : value(0){
    setup_ui();
}

BlockUi::~BlockUi() { }

void BlockUi::setup_ui(){
    setAlignment(Qt::AlignCenter); // align center text
    paint();
    // show();
}

void BlockUi::update_value(int value_){
    if (value != value_){
        value = value_;
        if (value != 0) setText(QString::number(value));
        else setText(QString(""));
        paint(); // update color
    }

    return;
}

void BlockUi::paint(){
    // select color using given input
    switch(value){
        case 0:
            setStyleSheet("QLabel { background: rgb(255, 255, 255); color: black; border style:solid; font: 70pt; font: bold; }");
            break;

        case 2:
            setStyleSheet("QLabel { background: rgb(187, 173, 160); color: black; border style:solid; font: 70pt; font: bold; }");
            break;

        case 4:
            setStyleSheet("QLabel { background: rgb(237, 224, 200); color: black; border style:solid; font: 70pt; font: bold; }");
            break;

        case 8:
            setStyleSheet("QLabel { background: rgb(242, 177, 121); color: black; border style:solid; font: 70pt; font: bold; }");
            break;

        case 16:
            setStyleSheet("QLabel { background: rgb(245, 149, 99); color: black; border style:solid; font: 70pt; font: bold; }");
            break;

        case 32:
            setStyleSheet("QLabel { background: rgb(246, 126, 95); color: black; border style:solid; font: 70pt; font: bold; }");
            break;

        case 64:
            setStyleSheet("QLabel { background: rgb(246, 94, 59); color: black; border style:solid; font: 70pt; font: bold; }");
            break;

        case 128:
            setStyleSheet("QLabel { background: rgb(237, 207, 114); color: black; border style:solid; font: 70pt; font: bold; }");
            break;

        case 256:
            setStyleSheet("QLabel { background: rgb(237, 204, 97); color: black; border style:solid; font: 70pt; font: bold; }");
            break;

        case 512:
            setStyleSheet("QLabel { background: rgb(237, 200, 80); color: black; border style:solid; font: 70pt; font: bold; }");
            break;

        case 1024:
            setStyleSheet("QLabel { background: rgb(237, 197, 63); color: black; border style:solid; font: 70pt; font: bold; }");
            break;

        case 2048:
            setStyleSheet("QLabel { background: rgb(237, 194, 46); color: black; border style:solid; font: 70pt; font: bold; }");
            break;
    }

    return;
}
