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
			return SeconderyMenuState::MainMenu;

		case '4':
			return SeconderyMenuState::SaveGame;

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

list<string> Menus::selectHouseToStart()
{
	string input, curHouse;
	list<string> housesFilesList = FilesUtils::getHousesListInFolder();

	SimulationPrintUtils::printSelectHouseMenu(housesFilesList);

	cin >> input;

	while (true)
	{
		if ((input[0] >= '0' && input[0] <= '9') &&
			(input[1] >= '0' && input[1] <= '9') &&
			(input[2] >= '0' && input[2] <= '9') &&
			input.length() == 3)
		{
			while (!housesFilesList.empty())
			{
				curHouse = housesFilesList.front();

				if (curHouse.substr(0, 3) == input)
				{
					return housesFilesList;
				}

				housesFilesList.pop_front();
			}

			SimulationPrintUtils::printFileNotFound();
		}

		if (input == "x")
		{
			return list<string>();
		}

		cin >> input;

	}
}