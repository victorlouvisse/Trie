#ifndef NODE_H
#define NODE_H

#include <vector>

using namespace std;

class Node
{
public:
    Node();
    ~Node();

    char content() { return m_content; }
    void setContent( char letter ) { m_content = letter; }

    bool isEnd() { return m_isEnd; }
    void setIsEnd() { m_isEnd = true; }

    Node* findChild( char letter );
    void appendChild( Node* child ) { m_children.push_back( child ); }

    vector<Node*> children() { return m_children; }

private:
    char m_content;
    bool m_isEnd;
    vector<Node*> m_children;
};

#endif // NODE_H
