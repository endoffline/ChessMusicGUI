#ifndef CSVREADER_H
#define CSVREADER_H

class CSVReader
{
public:
	CSVReader(std::string filename, char delimeter = ';');
	std::vector<std::vector<std::string>> getData();
	
private:
	std::string filename;
	char delimeter;
	
	std::ifstream loadCSVFile();

};
#endif //CSVREADER_H