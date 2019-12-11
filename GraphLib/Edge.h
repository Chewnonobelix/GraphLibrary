#ifndef EDGE_H
#define EDGE_H

#include "Node.h"

template<class T>
class Edge
{
    //TODO Class edge
public:
    typedef QSharedPointer<Edge<T>> SPointer;

    Edge() = default;
    Edge(const Edge<T>& n) = default;
    Edge(const T& data): m_data(data) {}
    ~Edge() = default;

    operator T()
    {
        return m_data;
    }

    T data() const
    {
        return m_data;
    }

    void setData(T d)
    {
        m_data = d;
    }

    double distance() const
    {
        return m_distance;
    }

    void setDistance(double d)
    {
        m_distance = d;
    }

private:
    T m_data;
    double m_distance = 1.0;
};

#endif // EDGE_H
