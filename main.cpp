#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

#include "trie.h"

using namespace std;

Trie TRIE;

void loadDictionary()
{
    ifstream dictionary( "dicionario.txt" );
    if( !dictionary )
    {
        cout << "Erro ao abrir o arquivo" << endl;
        return;
    }

    //Popula a trie com as palavras do dicionário
    bool dontStopUntilYouGetEnough = true;
    while( dontStopUntilYouGetEnough )
    {
        string str;
        if( !( dictionary >> str ) )
        {
            break;
        }

        TRIE.insert( str );
    }
}

void doTheSearch()
{
    cout << "Procurar por: ";

    string input;
    cin >> input;

    /* No dicionário todas as palavras estão em letra maiúscula, por isso
     * temos que converter a entrada */
    transform( input.begin(), input.end(), input.begin(), ::toupper );

    if( TRIE.search( input ) )
    {
        cout << "Achei!" << endl;
    }
    else
    {
        cout << "Ih, não encontrei :(" << endl;
    }
}

int main()
{
    loadDictionary();
    doTheSearch();
}
