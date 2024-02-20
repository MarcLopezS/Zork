#ifndef NPCs_Dialogues_h
#define NPCS_Dialogues_h

#include <map>
#include <string>

#include "Global.h"
#include "NPC.h"

class NPCsDialogues
{
public:

	NPCsDialogues();
	~NPCsDialogues();

	void dialogueController(NPCType npcType, int& stateDialog);
	void momController(int& stateDialog);
	void brotherController(int& stateDialog);
	
	std::map<std::string, std::string> allDialogues;
};

#endif //NPCS_Dialogues_h

