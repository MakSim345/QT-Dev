#include "mView.h"
#include "mControl.h"
#include "mModel.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mView *myView = new mView();
    mModel *myModel = new mModel();
    //mView myView;
    //mModel myModel;
    mControl *myControl = new mControl(myModel, myView);
    myControl->showView();
    //myView._show();
    return a.exec();
}
