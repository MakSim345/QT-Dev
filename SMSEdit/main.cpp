#include <QtGui>
#include <QApplication>
#include "SMSEdit.h"
//#include "gen.h"
//#include "utils.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	SMSEditForm w;
	w.setWindowTitle("SMS Edit Form");
	w.show();
	
	return a.exec();
	
}
