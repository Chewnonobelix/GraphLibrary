#ifndef TESTGRAPHUNO_H
#define TESTGRAPHUNO_H

#include <QObject>
#include <QTest>

#include "graph.h"

class TestGraphUnoriented : public QObject
{
    Q_OBJECT
private:
    Graph<int, double> m_graph;

public:
    explicit TestGraphUnoriented(QObject *parent = nullptr);

signals:

public slots:

private slots:
    void initTestCase();
    void cleanupTestCase();

    void addNode();
    void checkNode();
    void doNotAddNode();
    void addEdge();
    void checkEdge();
    void testAccessOperator();
    void removeEdge();
    void removeNode();
    void testInNode();
    void testOutNode();
    void testInOutNode();
    void testOutDeg();
    void testInDeg();
    void testInOutDeg();
    void testDeg();
    void testUnoriented();
};

#endif // TESTGRAPHUNO_H
