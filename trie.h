#ifndef TRIE_H
#define TRIE_H

#include <iostream>

using namespace std;

#define ALPHABET_SIZE 25

class Trie
{

    struct node
    {
        bool isEnd;
        int prefixCount;
        struct node* child[ALPHABET_SIZE];
    } *head;


public:
    Trie();
    ~Trie();

    void init();
    void insert( string str );
    bool search( string str );
    int wordsWithPrefix( string prefix );
};

#endif // TRIE_H
