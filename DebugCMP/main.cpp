#include <QApplication>
#include "debug_cmp.h"
//#include "gen.h"
//#include "utils.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	DebugCMP w;
	w.setWindowTitle("Debug component");
	// w.setStyleSheet("QPushButton#exitButton { color: black; };");
	w.show();
	
	return a.exec();
	
}
