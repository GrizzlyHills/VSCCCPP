/*
 * @Author: GrizzlyHills 
 * @Date: 2017-09-21 10:16:43 
 * @Last Modified by: GrizzlyHills
 * @Last Modified time: 2017-09-21 10:58:28
 * @Target 了解指针数组的工作原理
 */

#include <stdio.h>
#include <string.h>

char const *keyword[] = {
    "do",
    "for",
    "if",
    "register",
    "return",
    "switch",
    "while",
    "unsigned char"
    };
#define  N_KEYWORD  \
    ( sizeof( keyword ) / sizeof( keyword[0] ) )

int lookup_keyword( char const * const desired_word, char const *keyword_table[], int const size );
    

int main() 
{
    printf( "The number of bytes of the keyword is %d.\n", sizeof( keyword ) );         //64， 8个指针的长度
    printf( "The number of bytes of the keyword[0] is %d.\n", sizeof( keyword[0] ) );   //8, 是指针的长度

    //char word[] = "while";
    char const *word = "switch";            //两种皆可用
    int val = lookup_keyword( word, keyword, N_KEYWORD );
    if( val != -1 ) {
        printf( "Be found: *keyword[%d] ----- %s.\n", val, *(keyword + val) );
    } else {
        printf("Nothing.\n");
    }
    getchar();
    return 0;
}

/*
** Determine whether the argument matches any of the words in
** a list of keywords, and return the index to the one it matches.
** If no match is found, return the value -1.
*/
int lookup_keyword( char const * const desired_word, char const *keyword_table[], int const size )
{
    char const **kwp;
    /*
    ** For each word in the table ...
    */
    for( kwp = keyword_table; kwp < keyword_table + size; kwp++ )
        /*
        ** If this word matches the one we're looking for,
        ** return its position in the table.
        */
        if( strcmp( desired_word, *kwp ) == 0 )
            return kwp - keyword_table;
    /*
    ** Not found.
    */
    return -1;
}