#ifndef NPC_h
#define NPC_h

#include "Creature.h"

enum class NPCType
{
	MOM,
	BROTHER,
	STRANGER
};

class NPCsDialogues;

class NPC : public Creature
{

public:

	NPC(const std::string& nameNPC, const std::string& descriptionNPC, Room* locationNPC, NPCType typeNPCCreature, NPCsDialogues* dialogContr);
	~NPC();

	void talk() override;

	NPCType typeNPC;
	int stateDialog;
	NPCsDialogues* controllerNPCDialogue;
};

#endif //NPC_h

