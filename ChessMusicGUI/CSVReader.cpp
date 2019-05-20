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
	std::ifstream csvFile(m_path + m_filename);
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
			lineValues[1],
			lineValues[2],
			std::stoi(lineValues[3]),
			std::stoi(lineValues[4]),
			lineValues[5],
			std::stoi(lineValues[6]),
			std::stoi(lineValues[7]),
			std::stoi(lineValues[8]),
			stob(lineValues[9]),
			stob(lineValues[10]),
			stob(lineValues[11]),
			std::stoi(lineValues[12]),
			std::stoi(lineValues[13]),
			lineValues[14],
			std::stoi(lineValues[15]),
			lineValues[16],
			std::stoi(lineValues[17]),
			lineValues[18],
			std::stoi(lineValues[19]),
			lineValues[20],
			std::stoi(lineValues[21]),
			lineValues[22],
			std::stoi(lineValues[23]),
			lineValues[24],
			std::stoi(lineValues[25])
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


