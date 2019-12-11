#ifndef NODE_H
#define NODE_H

#include <QSharedPointer>

template<class T>
class Node
{
public:
    enum Color {Black, Grey, White};
    typedef QSharedPointer<Node<T>> SPointer;

    Node() = default;
    Node(const T& data): m_data(data)
    {}

    Node(const Node<T>& n) = default;
    ~Node() = default;

    operator T()
    {
        return m_data;
    }

    void resetColor()
    {
        m_color = Black;
    }

    void setColor(Color c)
    {
        m_color = c;
    }

    Color color() const
    {
        return m_color;
    }

    T data() const
    {
        return m_data;
    }

    void setData(T d)
    {
        m_data = d;
    }

    template<class U>
    friend bool operator == (const Node<U>&, const Node<U>&);
    template<class U>
    friend bool operator < (QSharedPointer<Node<U>>, QSharedPointer<Node<U>>);

    Node<T>& operator = (const Node<T>& n)
    {
        m_data = n.data();
        m_color = n.color();

        return *this;
    }

    Node<T>& operator = (const T& data)
    {
        m_data = data;
        m_color = Black;

        return *this;
    }

private:
    T m_data;
    Color m_color = Black;
};

template<class T>
bool operator == (const Node<T>& n1, const Node<T>& n2)
{
    return n1.data() == n2.data();
}

template<class T>
bool operator < (QSharedPointer<Node<T>> n1, QSharedPointer<Node<T>> n2)
{
    return n1->data() < n2->data();
}

#endif // NODE_H
