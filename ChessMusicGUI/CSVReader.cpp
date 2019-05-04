#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

#include "CSVReader.h"



CSVReader::CSVReader(std::string filename, char delimeter)
	: filename(filename)
	, delimeter(delimeter)
{
}

// load the CSV file
std::ifstream CSVReader::loadCSVFile()
{
	std::ifstream csvFile(filename);
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

		while (std::getline(ss, lineValue, delimeter))
		{
			lineValues.push_back(lineValue);
			std::cout << lineValue;
		}
		values.emplace_back(lineValues);
	}

	file.close();

	return values;
}
