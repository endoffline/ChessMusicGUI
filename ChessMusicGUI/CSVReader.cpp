#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

#include "CSVReader.h"
#include "Move.h"
#include "Game.h"

const std::string CSVReader::m_filename = "game.csv";

CSVReader::CSVReader(std::string path, char delimeter)
	: m_path(path)
	, m_delimeter(delimeter)
{
}

// load the CSV file
std::ifstream CSVReader::loadCSVFile()
{
	std::ifstream csvFile(m_path + "/" + m_filename);
	if (!csvFile.is_open())
	{
		std::cout << "Wrong path!" << std::endl;
	}

	return csvFile;
}

std::vector<std::vector<std::string>> CSVReader::getData()
{
	std::ifstream file = loadCSVFile();
	
	std::string line;
	std::vector<std::vector<std::string>> values;
	while (std::getline(file, line))
	{
		std::string lineValue;
		std::vector<std::string> lineValues;
		std::stringstream ss(line);

		while (std::getline(ss, lineValue, m_delimeter))
		{
			lineValues.push_back(lineValue);
			std::cout << lineValue;
		}
		values.emplace_back(lineValues);
	}

	file.close();

	return values;
}

Models::Game CSVReader::loadGame() {
	std::ifstream file = loadCSVFile();

	std::string line;
	Models::Game game(QString::fromStdString(m_path));
	std::getline(file, line); //skip a line
	while (std::getline(file, line))
	{
		std::string lineValue;
		std::vector<std::string> lineValues;
		std::stringstream ss(line);

		while (std::getline(ss, lineValue, m_delimeter))
		{
			lineValues.push_back(lineValue);
		}

		Models::Move move(
			std::stoi(lineValues[0]),
			stob(lineValues[1]),
			lineValues[2],
			lineValues[3],
			std::stoi(lineValues[4]),
			std::stoi(lineValues[5]),
			lineValues[6],
			std::stoi(lineValues[7]),
			std::stoi(lineValues[8]),
			std::stoi(lineValues[9]),
			stob(lineValues[10]),
			stob(lineValues[11]),
			stob(lineValues[12]),
			std::stoi(lineValues[13]),
			std::stoi(lineValues[14]),
			lineValues[15],
			std::stoi(lineValues[16]),
			lineValues[17],
			std::stoi(lineValues[18]),
			lineValues[19],
			std::stoi(lineValues[20]),
			lineValues[21],
			std::stoi(lineValues[22]),
			lineValues[23],
			std::stoi(lineValues[24]),
			lineValues[25],
			std::stoi(lineValues[26])
		);
		game.addMove(move);
	}

	file.close();

	return game;
}

bool stob(std::string s) {
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);
	return (s == "true" || s == "1");
}


