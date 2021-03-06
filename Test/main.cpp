#include <QApplication>
#include <QTest>
#include <QDebug>

#include "testgraph.h"
#include "testgraphunoriented.h"
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    int status = 0;

    //Tools unit test

    TestGraph tg;
    TestGraphUnoriented tguo;
    status |= QTest::qExec(&tg, argc, argv);

    status |= QTest::qExec(&tguo, argc, argv);


    return status;
}
