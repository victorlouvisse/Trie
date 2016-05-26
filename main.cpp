#include <iostream>

#include "trie.h"

using namespace std;

int main()
{
    Trie trie;

    trie.insert( "Coco" );

    if( trie.search( "Coco" ) )
    {
        cout << "Achei" << endl;
    }
}
