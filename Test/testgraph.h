#ifndef TESTGRAPH_H
#define TESTGRAPH_H

#include <QObject>
#include <QTest>

#include "graph.h"

class TestGraph : public QObject
{
    Q_OBJECT
private:
    Graph<int, double, true> m_graph;

public:
    explicit TestGraph(QObject *parent = nullptr);

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
    void testOriented();
};

#endif // TESTGRAPH_H
