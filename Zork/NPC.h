#ifndef NPC_h
#define NPC_h

#include "Creature.h"

enum class NPCType
{
	MOM,
	BROTHER,
	STRANGER
};

class NPC : public Creature
{

public:

	NPC(const std::string& nameNPC, const std::string& descriptionNPC, Room* locationNPC, NPCType typeNPCCreature);
	~NPC();

	void talk() override;

	NPCType typeNPC;
	int stateDialog;
};

#endif //NPC_h

