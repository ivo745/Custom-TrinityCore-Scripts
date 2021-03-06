/* ScriptData
SDCreator: frostI
SDName: molten_core
SD%Complete: 100
SDComment:
SDCategory: Molten Core
EndScriptData */

#ifndef DEF_MOLTEN_CORE_H
#define DEF_MOLTEN_CORE_H

#define MCScriptName "instance_molten_core"

extern Position const AlexstraszaSpawnPos;

uint32 const EncounterCount = 5;
#define DataHeader "MC"

enum Data64
{
	DATA_HAUNTED_EYE_OF_MAXIMUS = 0,
	DATA_MAXIMUS = 1,
	DATA_JANDICE_BAROV = 2,
	DATA_ALEXSTRASZA_EVENT = 3,
	DATA_CORRUPTED_RAGNAROS = 4,
	DATA_VOLCANO_1 = 5,
	DATA_VOLCANO_2 = 6,
	DATA_CRIMSON_FLAME = 7,
	DATA_ALEXSTRASZA_TRIGGER = 8,
	DATA_ALEXSTRASZA_CONTROLLER = 9,
	DATA_THRALL_2 = 10,
	DATA_RAGNAROS_CONTROLLER = 11
};

enum Creatures
{
	//Haunted Eye of Maximus
	NPC_HAUNTED_EYE_OF_MAXIMUS = 5000030,
	NPC_NIGHTMARE_OF_HALLOWS_END = 5000031,
	NPC_NIGHTMARE_OF_SPIDERS = 5000032,
	NPC_NIGHTMARE_OF_ZOMBIES = 5000033,
	NPC_NIGHTMARE_OF_GHOSTS = 5000034,
	NPC_HALLOWED_PUMPKIN = 5000035,
	NPC_ABANDONED_GHOST = 5000036,
	NPC_VOLCANO_1 = 5000092,
	//Maximus
	NPC_MAXIMUS = 5000037,
	NPC_POOL_OF_LIGHT = 5000038,
	NPC_CRIMSON_FLAME = 5000039,
	NPC_FLAME_SUPPRESSANT = 5000090,
	NPC_SMOLDERING_TSUNAMI_MC = 5000040,
	NPC_MAIEV_SHADOWSONG = 5000041,
	NPC_VOLCANO_2 = 5000091,
	//Jandice Barov
	NPC_JANDICE_BAROV = 5000042,
	NPC_FALSE_JANDICE_ILLUSION = 5000043,
	NPC_SHADOW_TRAP = 39137,
	NPC_TRUE_JANDICE_ILLUSION = 5000044,
	NPC_ILLUSION_EFFECT_TRIGGER = 5000045,
	//Alexstrasza Event
	NPC_ALEXSTRASZA = 5000046,
	NPC_RED_DRAGON_COMBAT_TRIGGER = 5000070,
	NPC_ALEXSTRASZA_CONTROLLER = 5000069,
	NPC_CORRUPTED_DRUID = 5000071,
	NPC_MALFURION_PORTAL = 5000072,
	NPC_MALFURION = 5000073,
	NPC_LATHORIUS_LEFT = 5000074,
	NPC_LILLIANDRA_LEFT = 5000075,
	NPC_STAGHELM_LEFT = 5000076,
	NPC_LATHORIUS_RIGHT = 5000077,
	NPC_LILLIANDRA_RIGHT = 5000078,
	NPC_STAGHELM_RIGHT = 5000079,
	NPC_PROTECTOR_OF_THE_KEEP = 5000080,
	NPC_GUARDIAN_OF_THE_SECRETS = 5000081,
	NPC_FABULOUS_DISTRACTOR = 5000082,
	NPC_INSANE_MARKSMAN = 5000083,
	//Corrupted Ragnaros
	NPC_CORRUPTED_RAGNAROS = 5000095,
	NPC_RAGNAROS_CONTROLLER = 5000096,
	NPC_RAGNAROS_METEOR_STRIKE_MARK = 5000099,
	NPC_RAGNAROS_METEOR_STRIKE_NORTH = 5000110,
	NPC_RAGNAROS_METEOR_STRIKE_EAST = 5000111,
	NPC_RAGNAROS_METEOR_STRIKE_WEST = 5000112,
	NPC_RAGNAROS_METEOR_STRIKE_SOUTH = 5000113,
	NPC_RAGNAROS_METEOR_STRIKE_FLAME = 5000114,
	NPC_TWILIGHT_FIELD = 5000115,
	//Escorts
	//On enter instance
	NPC_BRANN_1 = 5000060,
	NPC_BRANN_2 = 5000061,
	//After first boss
	NPC_BRANN_3 = 5000062,
	//After second boss
	NPC_BRANN_4 = 5000063,
	//After third boss
	NPC_THRALL_1 = 5000064,
	NPC_THRALL_2 = 5000065,
	//After finished alexstrasza event
	NPC_ALEXSTRASZA_1 = 5000066,
	NPC_ALEXSTRASZA_2 = 5000067,
};

enum GameObjectsIds
{
	GO_DOOR_HAUNTED_EYE_OF_MAXIMUS = 600001,
	GO_DOOR_MAXIMUS = 600002,
	GO_DOOR_JANDICE_BAROV_1 = 600003,
	GO_DOOR_JANDICE_BAROV_2 = 600004,
	GO_DOOR_ALEXSTRASZA = 600005,
	GO_DOOR_INSTANCE = 600006,
};

enum InstanceSpells
{
	//On enter instance
	SPELL_SWIFT_WIND = 8385,
	SPELL_VANISH = 42866,
	//After finished boss1
	SPELL_DOOR_EXPLOSION = 59383,
	SPELL_DOOR_EXPLOSION_KNOCKBACK = 51393,
	//After finished WP5
	SPELL_STORMHAMMER = 62042,
	SPELL_EARTHS_WRATH = 54195,
};

template<class AI>
CreatureAI* GetMoltenCoreAI(Creature* creature)
{
	if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
		if (instance->GetInstanceScript())
			if (instance->GetScriptId() == sObjectMgr->GetScriptId(MCScriptName))
				return new AI(creature);

	return NULL;
}

#endif