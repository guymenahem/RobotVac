#ifndef _MENUS_H_
#define _MENUS_H_

#include "ConsoleUtils.h"
#include "SimulationPrintUtils.h"
#include "FilesUtils.h"
#include <string.h>
#include <list>


enum class MainMenuState{ Start, StartFromHouse, ContinueSavedGame, Instruction, Exit };
enum class SeconderyMenuState{Continue, Restart,SaveGame,ShowSolution,MainMenu, Exit};

class Menus
{


public:
	static MainMenuState mainMenu();

	static SeconderyMenuState seconderyMenu();

	static string saveGameMenu();

	static void instructionMenu();

	static bool overrideMenu();

	static void clearSeconderyMenu();

	static list<string> selectHouseToStart();

	static string selectSavedHouseToStart(string selectedHouse);
};

#endif