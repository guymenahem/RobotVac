#ifndef _MENUS_H_
#define _MENUS_H_

#include "ConsoleUtils.h"
#include "SimulationPrintUtils.h"
#include <string.h>


enum class MainMenuState{ Start, Instruction, Exit };
enum class SeconderyMenuState{Continue, Restart, MainMenu, SaveGame, Exit};


class Menus
{


public:
	static MainMenuState MainMenu()
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

		// Open Instrucation
		case '8':
			return MainMenuState::Instruction;

		// Exit
		case '9':
		default:
			return MainMenuState::Exit;
		}


	}

	static SeconderyMenuState SeconderyMenu()
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

	string SaveGameMenu()
	{

	}

	static void InstructionMenu()
	{
		clear_screen();
		SimulationPrintUtils::printInsruction();
		getch();
	}



};

#endif