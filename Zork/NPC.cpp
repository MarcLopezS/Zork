#include "NPC.h"
#include "NPCsDialogues.h"

NPC::NPC(const std::string& nameNPC, const std::string& descriptionNPC,Room* locationNPC, NPCType typeNPCCreature, NPCsDialogues* dialogContr)
	:Creature(nameNPC,descriptionNPC,locationNPC)
{
	type = EntityType::NPC;
	typeNPC = typeNPCCreature;
	stateDialog = 1;
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