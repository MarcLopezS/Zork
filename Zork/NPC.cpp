#include "NPC.h"

NPC::NPC(const std::string& nameNPC, const std::string& descriptionNPC,Room* locationNPC, NPCType typeNPCCreature)
	:Creature(nameNPC,descriptionNPC,locationNPC)
{
	typeNPC = typeNPCCreature;
	stateDialog = 0;
}

NPC::~NPC()
{
}

void NPC::talk()
{

}