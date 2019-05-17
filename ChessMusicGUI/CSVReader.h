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

	friend bool stob(std::string s);
private:
	static const std::string m_filename;
	std::string m_path;
	char m_delimeter;
	
	std::ifstream loadCSVFile();

};
#endif //CSVREADER_H