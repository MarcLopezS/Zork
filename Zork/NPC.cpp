#include "NPC.h"
#include "NPCsDialogues.h"

NPC::NPC(const std::string& nameNPC, const std::string& descriptionNPC,Room* locationNPC, NPCType typeNPCCreature, NPCsDialogues* dialogContr)
	:Creature(nameNPC,descriptionNPC,locationNPC)
{
	typeNPC = typeNPCCreature;
	stateDialog = 0;
	controllerNPCDialogue = dialogContr;
}

NPC::~NPC()
{
}


void NPC::talk()
{
	//checks the dialogue in the dialogue controller
	controllerNPCDialogue->dialogueController(typeNPC, stateDialog); 
}