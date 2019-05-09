#ifndef CSVREADER_H
#define CSVREADER_H

#include "Game.h"
#include "Move.h"
class CSVReader
{
public:
	CSVReader(std::string filename, char delimeter = ';');
	std::vector<std::vector<std::string>> getData();
	Models::Game loadGame();
private:
	std::string filename;
	char delimeter;
	
	std::ifstream loadCSVFile();

};
#endif //CSVREADER_H