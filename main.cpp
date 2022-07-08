#include "GUI.h"
#include "teste.h"
#include "repository.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
    teste();
    
    QApplication a(argc, argv);
    Repository repo{ "populare.txt" };
    Service service{ repo };
    GUI w{ service };
    w.show();
    return a.exec();
}
