#ifndef TRIE_H
#define TRIE_H

#include <iostream>

using namespace std;

class Node;

class Trie
{
public:
    Trie();
    ~Trie();

    void insert( string str );
    bool search( string str );

private:
    Node* m_root;
};

#endif // TRIE_H
