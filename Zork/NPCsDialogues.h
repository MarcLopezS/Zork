#ifndef NPCs_Dialogues_h
#define NPCS_Dialogues_h

#include <map>
#include <string>

#include "Global.h"

class NPC;

class NPCsDialogues
{
public:

	NPCsDialogues(NPC* motherNPC, NPC* brotherNPC, NPC* strangerNPC);
	~NPCsDialogues();

	void readJSONDialogues();

	NPC* mother;
	NPC* brother;
	NPC* stranger;
	
	std::map<std::string, std::string> allDialogues;
};

#endif //NPCS_Dialogues_h

