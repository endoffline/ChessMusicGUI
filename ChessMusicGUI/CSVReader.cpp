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
			stob(lineValues[2]),
			lineValues[3],
			lineValues[4],
			std::stoi(lineValues[5]),
			std::stoi(lineValues[6]),
			std::stof(lineValues[7]),
			std::stoi(lineValues[8]),
			lineValues[9],
			std::stoi(lineValues[10]),
			std::stoi(lineValues[11]),
			std::stoi(lineValues[12]),
			stob(lineValues[13]),
			stob(lineValues[14]),
			stob(lineValues[15]),
			std::stoi(lineValues[16]),
			std::stoi(lineValues[19]),
			lineValues[21],
			std::stoi(lineValues[22]),
			lineValues[23],
			std::stoi(lineValues[24]),
			lineValues[25],
			std::stoi(lineValues[26]),
			lineValues[27],
			std::stoi(lineValues[28]),
			lineValues[29],
			std::stoi(lineValues[30]),
			lineValues[31],
			std::stoi(lineValues[32]),
			lineValues[38],
			std::stoi(lineValues[39]),
			lineValues[40],
			std::stoi(lineValues[41]),
			lineValues[42],
			std::stoi(lineValues[43]),
			lineValues[44],
			std::stoi(lineValues[45]),
			lineValues[46],
			std::stoi(lineValues[47]),
			lineValues[48],
			std::stoi(lineValues[49]),
			std::stoi(lineValues[56]),
			std::stoi(lineValues[58]),
			std::stoi(lineValues[59]),
			std::stoi(lineValues[60]),
			std::stoi(lineValues[63]),
			std::stoi(lineValues[65]),
			std::stoi(lineValues[66]),
			std::stoi(lineValues[67]),
			std::stoi(lineValues[84])
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


