#include "testgraph.h"

TestGraph::TestGraph() : QObject(nullptr)
{

}

void TestGraph::initTestCase()
{
}
void TestGraph::cleanupTestCase() {}

void TestGraph::addNode()
{
    QVERIFY(m_graph.addNode(1));
}

void TestGraph::checkNode()
{
    QVERIFY(m_graph.hasNode(1));
    Q_ASSERT(m_graph.addNode(2));
    Q_ASSERT(m_graph.addNode(3));
    Q_ASSERT(m_graph.addNode(4));
    Q_ASSERT(m_graph.addNode(5));
    Q_ASSERT(m_graph.addNode(6));
}

void TestGraph::doNotAddNode()
{
    QVERIFY(!m_graph.addNode(2));
}

void TestGraph::addEdge()
{
    QVERIFY(m_graph.setConnection(1, 2, 1.2));
}

void TestGraph::checkEdge()
{
    QVERIFY(m_graph.hasEdge(1.2));
    Q_ASSERT(m_graph.setConnection(1, 1, 1.1));
    Q_ASSERT(m_graph.setConnection(1, 3, 1.3));
    Q_ASSERT(m_graph.setConnection(2, 3, 2.3));
    Q_ASSERT(m_graph.setConnection(3, 5, 3.5));
    Q_ASSERT(m_graph.setConnection(5, 4, 5.4));
    Q_ASSERT(m_graph.setConnection(4, 3, 4.3));
    Q_ASSERT(m_graph.setConnection(4, 2, 4.2));
}

void TestGraph::removeEdge()
{
    QVERIFY(m_graph.removeEdge(1.1) && m_graph.hasEdge(1.1));
}

void TestGraph::removeNode()
{
    QVERIFY(m_graph.removeNode(6) && !m_graph.hasNode(6));
}

void TestGraph::testAccessOperator()
{

    QCOMPARE(m_graph(2,3)->data(), 2.3);
}

void TestGraph::testInNode()
{
    QSet<Node<int>::SPointer> data;
    data<<m_graph.node(1)<<m_graph.node(2)<<m_graph.node(4);

    QCOMPARE(m_graph.inOfNode(3).first.toSet(), data);
}

void TestGraph::testOutNode()
{
    QSet<Node<int>::SPointer> data;
    data<<m_graph.node(5);

    QCOMPARE(m_graph.outOfNode(3).first.toSet(), data);
}

void TestGraph::testInOutNode()
{
    QSet<Node<int>::SPointer> data;
    data<<m_graph.node(1)<<m_graph.node(2)<<m_graph.node(4)<<m_graph.node(5);

    QCOMPARE(m_graph.inOutOfNode(3).first.toSet(), data);
}

void TestGraph::testInDeg()
{
    QCOMPARE(m_graph.inNodeDeg(3), 3);
}

void TestGraph::testOutDeg()
{
    QCOMPARE(m_graph.outNodeDeg(3), 1);
}

void TestGraph::testInOutDeg()
{
    QCOMPARE(m_graph.inOutNodeDeg(1), 2);
}

void TestGraph::testOriented()
{
    QVERIFY(m_graph(1,2) != m_graph(2,1));
}
