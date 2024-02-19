#include <sstream>
#include <algorithm>
#include <iostream>
#include <fstream>

#include "Global.h"
#include "json.hpp"

using json = nlohmann::json;


std::vector<std::string> tokenize(const std::string& userInput)
{
	std::vector<std::string> arguments;

	std::stringstream ss(userInput);

	std::string temp_str;

	while (std::getline(ss, temp_str, ' '))
	{
		arguments.push_back(temp_str);
	}

	return arguments;
}

std::string toLowerCase(std::string str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}

std::map<std::string, std::string> readJson()
{
	std::map<std::string, std::string> allDialogues;

	std::ifstream file("TextDialogues.json");

	if (!file.is_open())
	{
		std::cerr << "Exception when opening the JSON file." << std::endl;
		return allDialogues;
	}

	json jsonDataDialogues;

	file >> jsonDataDialogues;

	file.close();

	for (auto it = jsonDataDialogues.begin(); it != jsonDataDialogues.end(); ++it)
	{
		std::string keyNPC = it.key();
		std::string valueDialogue = it.value();
		allDialogues[keyNPC] = valueDialogue;
	}

	return allDialogues;
}