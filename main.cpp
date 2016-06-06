#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <wchar.h>

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

/* Função necessária para pegar o tamanho das strings que
 * tem caracteres utf8 */
int strlenUtf8( string * str )
{
   const char * s = str->c_str();
   int i = 0;
   int j = 0;
   while ( s[i] )
   {
     /* Filtra caracteres do utf8 e conta somente os que
      * não são */
     if ( ( s[i] & 0xc0 ) != 0x80 )
     {
         j++;
     }

     i++;
   }
   return j;
}

void removeAccents( string * input )
{
    int inputUtf8Size = strlenUtf8( input );

    /* Pela diferença de tamanho sabemos se o input possui caraceteres utf8 */
    bool hasUtf8 = inputUtf8Size != static_cast<int>( input->size() );

    if( hasUtf8 )
    {
        wchar_t accents[] = L"àâêôûãõáéíóúçüÀÂÊÔÛÃÕÁÉÍÓÚÇÜ";
        wchar_t noAccents[] = L"aaeouaoaeioucuAAEOUAOAEIOUCU";
        wchar_t tempWideStr[inputUtf8Size];

        /* Converte o input que é um multi byte string em um wide char string */
        mbstowcs( tempWideStr, input->c_str(), inputUtf8Size );

        for( int i=0; i < inputUtf8Size; i++ )
        {
            for( unsigned j=0; j < wcslen( accents ); j++)
            {
                if( tempWideStr[i] == accents[j] )
                {
                    tempWideStr[i] = noAccents[j];
                }
            }
        }

        /* Precisamos reconverter para multi byte string */
        char converted[inputUtf8Size];
        wcstombs( converted, tempWideStr, sizeof( converted ) );

        *input = converted;
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
    /* Necessário para conversão dos caracteres utf8 */
    setlocale( LC_ALL, "pt_BR.UTF-8" );

    loadDictionary();
    doTheSearch();
}
