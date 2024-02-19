#ifndef Global_h
#define	Global_h

#include <string>
#include <vector>
#include <map>


std::vector<std::string> tokenize(const std::string& userInput);
std::string toLowerCase(std::string str);

std::map<std::string, std::string> readJson();


#endif // Global_h