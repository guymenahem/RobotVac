#ifndef _FILESUTILS_H_
#define _FILESUTILS_H_

#include <iostream>
#include <fstream>
#include <list>
#include "House.h"


using namespace std;

class FilesUtils
{

public:

// Houses
static list<string> getHousesListInFolder();
static bool isValidHouseName(string name);
static House loadHouseFromFile(string fileName);

// Solutions
static void writeSoultionToFile(const list<string>& lstDirections, int numOfMoves, string houseNumber);
static list<string> readSolutionFromFile(string houseNumber);
static list<string> getAllSolutions();
static bool isThereSolution(string houseNumber);
static bool isValidSolutionName(string name);
static bool isThereBetterSol(string houseNumber, int numOfSteps);

// Saved Games
static void writeSaveToFile(const list<string>& lstDirections,const string houseNumber,const string name);
static list<string> getAllSavedGames(string houseNumber);
static bool isVaildSavedName(string name, string houseNumber);
static bool isSavedGameExist(string name, string gameNumber);
static bool isSavedGameExist(string gameNumber);
static list<string> readSavedGameFromFile(string houseNumber);

};

#endif