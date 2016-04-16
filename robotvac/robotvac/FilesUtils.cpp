#include "FilesUtils.h"
#include <string.h>

using namespace std;


list<string> FilesUtils::getHousesListInFolder()
{
	list<string> listNames;
	string str;

	system("dir /b *.House > House_names.txt");
	//system("dir /b .\\Houses\\*.House > Houses\\House_names.txt");

	ifstream names_of_files_in_dir("House_names.txt");
	const size_t buff_size = 1024;
	char buff[buff_size];
	while (!names_of_files_in_dir.eof()) {
		names_of_files_in_dir.getline(buff, buff_size - 1);
		str = buff;

		if (FilesUtils::isValidHouseName(str))
			listNames.push_back(str);
	}

	// Close the Houses list file
	names_of_files_in_dir.close();

	// Delete the files
	system("del House_names.txt");

	return listNames;
}

House FilesUtils::loadHouseFromFile(string fileName)
{
	string name;
	char temp[80];
	char* board[24];
	int numberOfSteps,height,width;

	ifstream inFile(fileName, ios::in);

	inFile.getline(temp, 80);
	name = temp;

	inFile.getline(temp, 80);
	numberOfSteps = stoi(temp);

	inFile.getline(temp, 80);
	height = stoi(temp);
	
	inFile.getline(temp, 80);
	width = stoi(temp);


	for (size_t i = 0; i < height; i++)
	{
		inFile.getline(temp, 80);
		board[i] = new char[width];
		strncpy(board[i],temp,width);
	}

	inFile.close();

	House house(name.c_str(), height, width,numberOfSteps, board);

	return house;

}

list<string> FilesUtils::getAllSolutions ()
{
	list<string> listNames;
	string str;

	system("dir /b *.house_solution > House_sol_names.txt");

	ifstream names_of_files_in_dir("House_sol_names.txt");
	const size_t buff_size = 1024;
	char buff[buff_size];
	while (!names_of_files_in_dir.eof()) {
		names_of_files_in_dir.getline(buff, buff_size - 1);
		str = buff;
		if (isValidSolutionName(str))
			listNames.push_back(str);
	}

	// Close the Houses list file
	names_of_files_in_dir.close();

	// Delete the files
	system("del House_sol_names.txt");

	return listNames;
}

list<string> FilesUtils::getAllSavedGames(string houseNumber)
{
	list<string> listNames;
	string str;

	system("dir /b *.house_saved > House_saved.txt");
	//system("dir /b .\\Houses\\*.House > Houses\\House_names.txt");

	ifstream names_of_files_in_dir("House_saved.txt");
	const size_t buff_size = 1024;
	char buff[buff_size];
	while (!names_of_files_in_dir.eof()) {
		names_of_files_in_dir.getline(buff, buff_size - 1);
		str = buff;

		if (isVaildSavedName(str, houseNumber))
			listNames.push_back(str);
	}

	// Close the Houses list file
	names_of_files_in_dir.close();

	// Delete the files
	system("del House_saved.txt");

	return listNames;
}

bool FilesUtils::isValidSolutionName(string name)
{
	// check length
	if (name.length() != 18) 
		return false;

	// check start
	if ((name[0] >= '0' && name[0] <= '9') &&
		(name[1] >= '0' && name[1] <= '9') &&
		(name[2] >= '0' && name[2] <= '9') &&
		(name[3] == '.'))
	{
		// check ending
		string fin = name.substr(4,string::npos);
		if (fin.compare("house_solution") == 0)
		{
			return true;
		}
	}

	return false;

}

bool FilesUtils::isValidHouseName(string name)
{
	// check length
	if (name.length() != 9)
		return false;

	// check start
	if ((name[0] >= '0' && name[0] <= '9') &&
		(name[1] >= '0' && name[1] <= '9') &&
		(name[2] >= '0' && name[2] <= '9') &&
		(name[3] == '.'))
	{
		// check ending
		string fin = name.substr(4, string::npos);
		if (fin.compare("House") == 0)
		{
			return true;
		}
	}

	return false;
}

bool FilesUtils::isVaildSavedName(string name, string houseNumber)
{
	// check length
	if (name.length() <= 16)
		return false;

	// check start
	if (name.substr(0, 4) == houseNumber + '-')
	{
		// check ending
		string fin = name.substr(name.length()-12, string::npos);
		if (fin.compare(".house_saved") == 0)
		{
			return true;
		}
	}

	return false;
}

void FilesUtils::writeSoultionToFile(const list<string>& lstDirections, int numOfMoves, string houseNumber)
{
	string fileName = houseNumber + ".house_solution";

	ofstream outFile(fileName, ios::out | ios::trunc);

	outFile << numOfMoves << endl;

	for each (string direction in lstDirections)
	{
		outFile << direction << endl;
	}

	outFile.close();
}

list<string> FilesUtils::readSolutionFromFile(string houseNumber)
{
	list<string> lstDirections;
	char temp[10];

	ifstream inFile(houseNumber + ".house_solution", ios::in);

	 inFile.getline(temp,10);
	 int numOfSteps = stoi(temp);

	while (!inFile.eof())
	{
		inFile.getline(temp, 10);
		lstDirections.push_back(temp);
	}

	// pop EOF Record
	lstDirections.pop_back();

	inFile.close();

	return lstDirections;
}

bool FilesUtils::isThereSolution(string houseNumber)
{
	list<string> lstSols = FilesUtils::getAllSolutions();

	for each(string sol in lstSols)
	{
		if (houseNumber[0] == sol[0] &&
			houseNumber[1] == sol[1] &&
			houseNumber[2] == sol[2])
		{
			return true;
		}
	}

	return false;
}

bool IsThereBetterSol(string houseNumber, int numOfSteps)
{
	list<string> lstSols = FilesUtils::getAllSolutions();

	for each(string sol in lstSols)
	{
		if (houseNumber[0] == sol[0] &&
			houseNumber[1] == sol[1] &&
			houseNumber[2] == sol[2])
		{
			char temp[10];
			ifstream inFile(houseNumber + ".house_solution", ios::in);
			inFile.getline(temp, 10);
			int solNumOfSteps = stoi(temp);
			inFile.close();

			if (solNumOfSteps < numOfSteps)
			{
				return true;
			}
			else
			{
				return false;
			}

		}
	}

	return false;
}