//
// Created by Rahul Thai Valappil on 4/5/2016.
// launcher class for city map.
// command line argument 1- Map file path if not specified look for current exe path
// command line argument 2- start city name
// command line argument 3- target city name
//
#include <stdio.h>
#include "List.h"
#include "map.h"
#include "string.h"

/*************************************************************
 * get get folder from a current executable path
 * @param path  full path of executable
 * @return directory of a path
*************************************************************/
static char* getFilePath( char* path ){

    char* word;
    int nOffset = 0;
    word = strrchr(path,'\\');
    if( word ){
        nOffset = strlen( word )-1;
        nOffset = strlen( path ) - nOffset;
        path[nOffset] = '\0';
    }
    else
    {
        path =0;
    }
    return path;
}

int main( int argc, char* argv[] )
{
    char* filepath = argv[1] ;
    if( 4 == argc || 3 == argc )
    {
        if( 3 == argc )
        {
            filepath = argv[0];
            //filepath consider from executabel path and file name is FRANCE.MAP
            filepath = getFilePath(filepath);
            //filepath = getcwd( argv[0],MAX_LENGTH );

            if(!filepath)
            {
                filepath = mapFileName;
            }
            else
            {
                filepath = strcat(filepath,mapFileName);
            }
            printf( "Default file path used for loading Map\n" );
        }
        List* cityList = parseMapFile( filepath );
        if( !cityList )
        {
            printf( "%s\n", message( ERRMAPFILEFAILED ) );
            return 0;
        }
        status sts;
        if( 3 == argc ) {
            sts = findPath( cityList, argv[1], argv[2] );
        }
        else
        {
            sts = findPath( cityList, argv[2], argv[3] );
        }
        if( sts == ERRCITYNOTFOUND )
        {
            printf( "%s\n", message( ERRCITYNOTFOUND ));
        }
        destroyCities( cityList );

    }
    else if( argc < 3 )
    {
        printf( "%s\n", message( ERRARGLESS ) );
    }
    else
    {
        printf( "%s\n", message( ERRARGMORE ) );
    }
return 0;
}
