#include "gen.h"
#include "xonix.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Xonix window;
    window.setWindowTitle("Breakout");
    window.show();
    return a.exec();
}
