#ifndef GRAPH_H
#define GRAPH_H

#include <QMap>
#include <QSharedPointer>
#include <QPair>
#include <QString>
#include "graph_global.h"
#include "Node.h"
#include "Edge.h"

template<class NodeType, class  EdgeType, bool Oriented = false>
class GRAPHSHARED_EXPORT Graph
{
private:
    typedef typename Node<NodeType>::SPointer NodePointer;
    typedef typename Edge<EdgeType>::SPointer EdgePointer;

    QMap<NodePointer, QMap<NodePointer, EdgePointer>> m_adjacency;
    QList<NodePointer> m_node;
    QList<EdgePointer> m_edge;

    auto removeMultiple(auto l) const ->decltype(l)
    {
        auto ret = l;
        for(auto it = ret.begin(); it != ret.end(); it++)
        {
            while(ret.count(*it) > 1)
            {
                ret.removeAt(ret.lastIndexOf(*it));
            }
        }

        return ret;
    }


public:
    Graph()
    {}

    EdgePointer operator()(NodeType n1, NodeType n2)
    {
        if(!hasEdge(n1, n2))
            return EdgePointer::create();
        else
        {
            NodePointer p1, p2;
            p1 = node(n1);
            p2 = node(n2);
            return m_adjacency[p1][p2];
        }
    }

    NodePointer node(NodeType n) const
    {
        NodePointer ret;

        for(auto it: m_node)
            if(*it == n)
                ret = it;

        return ret;
    }

    EdgePointer edge(EdgeType e) const
    {
        EdgePointer ret;


        return ret;
    }

    bool setConnection(NodeType n1, NodeType n2, EdgeType e)
    {
        if(!(hasNode(n1) && hasNode(n2) && !hasEdge(e)))
            return false;

        EdgePointer p = EdgePointer::create();
        p->setData(e);
        m_adjacency[node(n1)][node(n2)] = p;

        if(!Oriented)
            m_adjacency[node(n2)][node(n1)] = p;

        m_edge << p;

        return true;
    }

    bool addNode(NodeType n)
    {
        if(hasNode(n))
            return false;

        NodePointer p = NodePointer::create();
        *p = n;

        m_node << p;

        return true;
    }

    bool hasNode(NodeType n) const
    {
        bool ret = false;

        for(auto it: m_node)
            if(*it == n)
                ret = true;

        return ret;
    }

    bool hasEdge(NodeType n1, NodeType n2) const
    {
        NodePointer p1, p2;
        if(hasNode(n1) && hasNode(n2))
        {
            p1 = node(n1);
            p2 = node(n2);

            bool ret = false;
            ret = m_adjacency[p1].contains(p2);

            return ret;
        }
        else
        {
            return false;
        }
    }

    bool hasEdge(EdgeType e) const
    {
        bool find = false;

        for(auto it: m_edge)
            if(*it == e)
                find = true;

        return find;
    }

    bool removeEdge(EdgeType e)
    {
        if(!hasEdge(e))
           return false;

        auto rem = getNodesFromEdge(e);
        m_adjacency[rem.first].remove(rem.second);

        return true;
    }

    bool removeNode(NodeType n)
    {
        if(!hasNode(n))
            return false;

        NodePointer p = node(n);

        m_adjacency.remove(p);

        for(auto it = m_adjacency.begin(); it != m_adjacency.end(); it++)
        {
            it->remove(p);
        }

        m_node.removeAll(p);

        return true;
    }

    QPair<QList<NodePointer>, QList<EdgePointer>> outOfNode(NodeType n) const
    {
        //TODO to test

        NodePointer p = node(n);

        QList<NodePointer> nodes;
        QList<EdgePointer> edges;

        for(auto it = m_adjacency[p].begin(); it != m_adjacency[p].end();
            it++)
        {
            nodes << it.key();
            edges << it.value();
        }

        nodes = removeMultiple(nodes);
        edges = removeMultiple(edges);

        return qMakePair(nodes, edges);
    }

    QPair<QList<NodePointer>, QList<EdgePointer>> inOfNode(NodeType n) const
    {
        //TODO to test

        NodePointer p = node(n);

        QList<NodePointer> nodes;
        QList<EdgePointer> edges;

        for(auto it = m_adjacency.begin(); it != m_adjacency.end(); it++)
        {
            if(it->contains(p))
            {
                nodes << it.key();
                edges << (*it)[p];
            }
        }

        nodes = removeMultiple(nodes);
        edges = removeMultiple(edges);

        return qMakePair(nodes, edges);
    }

    QPair<QList<NodePointer>, QList<EdgePointer>> inOutOfNode(NodeType n) const
    {
        //TODO test
        NodePointer p = node(n);

        QList<NodePointer> nodes;
        QList<EdgePointer> edges;

        auto inNode = inOfNode(n);
        auto outNode = outOfNode(n);

        nodes = inNode.first + outNode.first;
        edges = inNode.second + outNode.second;


        nodes = removeMultiple(nodes);
        edges = removeMultiple(edges);

        return qMakePair(nodes, edges);
    }

    int inNodeDeg(NodeType n) const
    {
        return inOfNode(n).first.size();
    }

    int outNodeDeg(NodeType n) const
    {
        return outOfNode(n).first.size();
    }


    int inOutNodeDeg(NodeType n) const
    {
        return inOutOfNode(n).first.size();
    }

    QPair<NodePointer, NodePointer> getNodesFromEdge(EdgeType e) const
    {
        QPair<NodePointer, NodePointer> ret = QPair<NodePointer, NodePointer>();
        for(auto it = m_adjacency.begin(); it != m_adjacency.end(); it++)
        {
            for(auto it2 = it->begin(); it2 != it->end(); it2++)
            {
                if(**it2 == e)
                {
                    ret = qMakePair(it.key(), it2.key());
                }
            }
        }

        return ret;
    }

};

#endif // GRAPH_H
