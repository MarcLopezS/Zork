#include "NPCsDialogues.h"
#include "NPC.h"

NPCsDialogues::NPCsDialogues(NPC* motherNPC, NPC* brotherNPC, NPC* strangerNPC)
{
	mother = motherNPC;
	brother = brotherNPC;
	stranger = strangerNPC;

	readJSONDialogues();
}

NPCsDialogues::~NPCsDialogues()
{
}

void NPCsDialogues::readJSONDialogues()
{
	allDialogues = readJson();
}

