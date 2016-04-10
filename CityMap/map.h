/********************************************************************
 *
 * map.h 2016-04-04 Rahul Thai Valappil
 *
 ********************************************************************
 */
/**
 *
 * Responsible for loading map details from the user input file to a data structure
 * which using the list implementation from list.h. Map file contain information about
 * cities and it's neighbouring cities. Also implemented path finder which returns lowest
 * path between the cities using A start algorithm
 * .
 *
 ********************************************************************/

#ifndef CITYMAP_MAP_H
#define CITYMAP_MAP_H

#include "status.h"
#include "List.h"

#define MAX_LENGTH 1024
//using this as default map file name if user not mention
static char* mapFileName = "FRANCE.MAP";

/** The struct holds the information about city in a Map file*/
typedef struct City {
    char* name;
    int lang;
    int lat;
    int g;
    int h;
    List* neighbour;
    struct City* backptr;
}City;

/** The struct holds information of Neighbour(name and distance) city from parent city*/
typedef struct Neighbour {
    char* name;
    int distance;
}Neighbour;

/** Function loads the Map details about cities and connected neighboring cities to a List .
 *  @param(1) map file path
 *  @return (a pointer to) list which contains all cities as node
 *  @return 0 otherwise
 */
List* parseMapFile( char* );

/** Find City details from list bu using comparison function provided during list creation.
 *  @param(1) List of cities
 *  @param(2) City name
 *  @return a pointer to City which contains details about City
 *  @return 0 otherwise
 */
City* findCity( List* , char* );

/** Finds shortest path between two cities using A Star algorithm and display using
 *  function provided during list creation  .
 *  @param(1) List of cities
 *  @param(2) Source city name
 *  @param(3) Destination city name
 *  @return ERRCITYNOTFOUND if invalid city
 *  @return OK if everything worked fine
 */
status findPath( List*, char*, char* );

/** Empty City creation by dynamic memory allocation.
 *  @return a new (empty) city if memory allocation OK
 *  @return 0 otherwise
 */
City* createCity( );

/** Empty Neighbour creation by dynamic memory allocation.
 *  @return a new (empty) Neighbour if memory allocation OK
 *  @return 0 otherwise
 */
Neighbour* createNeighbour( );

/** destroy the list of Cities by deallocation of the the used memory.
 *  @param(1) list of Cities to destroy
 */

void destroyCities( List* );

/** destroy the City by deallocation of the the used memory.
 *  @param(1) City to destroy
 */
void destroyCity( City** );

/** destroy the City by deallocation of the the used memory.
 *  @param(1) Neighbour to destroy
 */
void destroyNeighbour( Neighbour** );

#endif //CITYMAP_MAP_H
