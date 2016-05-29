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

void removeAccents( string * str )
{
    string accents = "àâêôûãõáéíóúçüÀÂÊÔÛÃÕÁÉÍÓÚÇÜ";
    string noAccents = "aaeouaoaeioucuAAEOUAOAEIOUCU";

    for( unsigned i=0; i < str->size(); i++ )
    {
        for( unsigned j=0; j < accents.size(); j++)
        {
            if( str->at( i ) == accents.at( j ) )
            {
                str->at( i ) = noAccents.at( j );
            }
        }
    }
}

void processInput( string * input )
{
    /* No dicionário as palavras não estão acentuadas. Por isso, temos que
     * remover os acentos caso seja necessário. */
    removeAccents( input );

    /* No dicionário todas as palavras estão em letra maiúscula, por isso
     * temos que converter a entrada. Utilizamos algorithm::transform */
    transform( input->begin(), input->end(), input->begin(), ::toupper );
}

void doTheSearch()
{
    cout << "Procurar por: ";

    string input;
    cin >> input;

    processInput( &input );

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
