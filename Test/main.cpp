#include <QApplication>
#include <QTest>
#include <QDebug>

#include "testexpression.h"
#include "testgraph.h"
#include "testgraphunoriented.h"
#include "Bestiary/abstractcreaturetest.h"
#include "Bestiary/abstractobjecttest.h"
#include "Bestiary/abstractweapontest.h"
#include "Bestiary/abstractcreaturerpgtest.h"
#include "Bestiary/abstractbonustest.h"
#include "Bestiary/abstractpctest.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    qRegisterMetaType<TestCreatureBase>();
    qRegisterMetaType<TestAbstractObject>();
    qRegisterMetaType<TestAbstractWeapon>();
    qRegisterMetaType<TestBonus>();
    qRegisterMetaType<TestCreatureRpg>();

    int status = 0;

    //Tools unit test
    TestExpression tex;
    status |= QTest::qExec(&tex, argc, argv);

    TestGraph tg;
    status |= QTest::qExec(&tg, argc, argv);

    TestGraphUnoriented tguo;
    status |= QTest::qExec(&tguo, argc, argv);


    //Bestiary unit test
    AbstractObjectTest aot;
    status |= QTest::qExec(&aot, argc, argv);

    AbstractWeaponTest awt;
    status |= QTest::qExec(&awt, argc, argv);

    AbstractCreatureTest act;
    status |= QTest::qExec(&act, argc, argv);

    AbstractBonusTest abt;
    status |= QTest::qExec(&abt, argc, argv);

    AbstractPcTest apct;
    status |= QTest::qExec(&apct, argc, argv);

    AbstractCreatureRPGTest acrpgt;
    status |= QTest::qExec(&acrpgt, argc, argv);

    return status;
}
