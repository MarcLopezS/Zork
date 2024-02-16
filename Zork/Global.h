#ifndef Global_h
#define	Global_h

#include <string>
#include <vector>


std::vector<std::string> tokenize(const std::string& userInput);
std::string toLowerCase(std::string str);
bool sameName(const std::string& str1, const std::string& str2);


#endif // Global_h