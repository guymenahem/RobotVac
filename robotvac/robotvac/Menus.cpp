#include "Menus.h"
#include "ConsoleUtils.h"
#include "SimulationPrintUtils.h"
#include "FilesUtils.h"
#include <string.h>
#include <list>


MainMenuState Menus::mainMenu()
{
	char input;

	clear_screen();
	SimulationPrintUtils::printInitialMenu();

	input = getch();

	switch (input)
	{
		// Start Simulation
	case '1':
		return MainMenuState::Start;

	case '2':
		return MainMenuState::StartFromHouse;

	case '3':
		return MainMenuState::ContinueSavedGame;
		// Open Instrucation
	case '8':
		return MainMenuState::Instruction;

		// Exit
	case '9':
	default:
		return MainMenuState::Exit;
	}


}

SeconderyMenuState Menus::seconderyMenu()
{
	char input;

	SimulationPrintUtils::printSecondaryMenu();

	input = getch();

	while (true)
	{
		switch (input)
		{
			// Start Simulation
		case '1':
			return SeconderyMenuState::Continue;

			// Open Instrucation
		case '2':
			return SeconderyMenuState::Restart;

		case '3':
			return SeconderyMenuState::SaveGame;

		case '4':
			return SeconderyMenuState::ShowSolution;

		case '8':
			return SeconderyMenuState::MainMenu;


			// Exit
		case '9':
			return SeconderyMenuState::Exit;

		default:
			input = getch();
		}
	}
}

string Menus::saveGameMenu()
{
	string fileName;

	while (true)
	{
		SimulationPrintUtils::printSaveMenu();
		cin >> fileName;

		if (fileName != "")
		{
			return fileName;
		}
	}

}

void Menus::instructionMenu()
{
	clear_screen();
	SimulationPrintUtils::printInsruction();
	getch();
}

bool Menus::overrideMenu()
{
	char input;
	SimulationPrintUtils::printSaveOverrideMenu();

	input = getch();

	while (true)
	{
		switch (input)
		{
		case '1':
			return true;
		case '2':
			return false;
		default:
			input = getch();
		}
	}
}

void Menus::clearSeconderyMenu()
{
	SimulationPrintUtils::clearSecondaryMenu();
}

string Menus::selectSavedHouseToStart(string selectedHouse)
{
	string input;

	bool isSavedGameExists = FilesUtils::isSavedGameExist(selectedHouse);
	
	if (isSavedGameExists)
	{
		list<string> savedHouses = FilesUtils::getAllSavedGames(selectedHouse.substr(0, 3));
		if (savedHouses.size() == 1)
		{
			return savedHouses.front();
		}
		else
		{
			while (true)
			{
				SimulationPrintUtils::printSelectSaved(savedHouses);
				cin >> input;

				if (input == "x")
				{
					return "";
				}

				for each(string str in savedHouses)
				{
					if (str.substr(4, str.length() - 16) == input)
					{
						return str;
					}
				}

				SimulationPrintUtils::printSavedNotFound();

				getch();
			}
		}
	}
	else
	{
		clear_screen();
		cout << "no saved game for house " + selectedHouse.substr(0,3) << endl <<
			"press any key to go back to main menu";
		getch();
		return "";
	};

}

list<string> Menus::selectHouseToStart()
{
	string input, curHouse;
	list<string> housesFilesList = FilesUtils::getHousesListInFolder();
	list<string> tempHousesFilesList = housesFilesList;
	SimulationPrintUtils::printSelectHouseMenu(housesFilesList);

	cin >> input;

	while (true)
	{
		if ((input[0] >= '0' && input[0] <= '9') &&
			(input[1] >= '0' && input[1] <= '9') &&
			(input[2] >= '0' && input[2] <= '9') &&
			input.length() == 3)
		{
			while (!tempHousesFilesList.empty())
			{
				curHouse = tempHousesFilesList.front();

				if (curHouse.substr(0, 3) == input)
				{
					return tempHousesFilesList;
				}

				tempHousesFilesList.pop_front();
			}
			
			tempHousesFilesList = housesFilesList;
			SimulationPrintUtils::printFileNotFound();
		}

		if (input == "x")
		{
			return list<string>();
		}

		cin >> input;

	}
}