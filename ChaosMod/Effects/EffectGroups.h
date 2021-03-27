#pragma once

#include <unordered_map>

enum class EffectGroupType
{
	DEFAULT,
	TELEPORT,  // Effects which teleport the player potentially far away without (explicitly) being helpful
	SPAWN,     // Effects which spawn "generic" objects (like vehicles or props)
	PEDS,      // Effects which spawn friendly/enemy peds
	WEAPONS,   // Effects which give/remove weapons
	PLAYERKILL // Effects which are (almost) guaranteed to immediately kill the player under any circumstance
};

struct EffectGroup
{
	int WeightMult = 1;
};

inline const std::unordered_map<EffectGroupType, EffectGroup> g_effectGroups
{
	{EffectGroupType::TELEPORT, {}},
	{EffectGroupType::SPAWN, { .WeightMult = 3 }},
	{EffectGroupType::PEDS, { .WeightMult = 3 }},
	{EffectGroupType::WEAPONS, { .WeightMult = 2 }},
	{EffectGroupType::PLAYERKILL, {}},
};

inline std::unordered_map<EffectGroupType, int> g_effectGroupMemberCount;