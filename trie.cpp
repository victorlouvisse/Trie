#include "trie.h"

Trie::Trie()
{
    init();
}

Trie::~Trie()
{
}

void Trie::init()
{
    head = new node();
    head->prefixCount = 0;
    head->isEnd = false;
}

void Trie::insert( string str )
{
    node * current = head;
    current->prefixCount++;

    for( unsigned i=0; i < str.length(); ++i )
    {
        int letter = static_cast<int>( str[i] ) - static_cast<int>( 'a' );

        if( current->child[letter] == NULL )
        {
            current->child[letter] = new node();
            current->child[letter]->prefixCount++;
            current = current->child[letter];
        }
    }
    current->isEnd = true;
}

bool Trie::search( string str )
{
    node * current = head;

    for( unsigned i=0; i < str.length(); ++i )
    {
        int letter = static_cast<int>( str[i] ) - static_cast<int>( 'a' );

        if( current->child[letter] == NULL )
        {
            return false;
        }

        current = current->child[letter];
    }
    return current->isEnd;
}

int Trie::wordsWithPrefix( string prefix )
{
    node * current = head;

    for( unsigned i=0; i < prefix.length(); ++i )
    {
        int letter = static_cast<int>( prefix[i] ) - static_cast<int>( 'a' );

        if( current->child[letter] == NULL )
        {
            return 0;
        }
        else
        {
            current = current->child[letter];
        }
    }

    return current->prefixCount;
}
