#include <stdafx.h>

//Effect by ProfessorBiddle

static void OnStop()
{
	for (auto veh : GetAllVehs())
	{
		SET_VEHICLE_REDUCE_GRIP(veh, false);
	}
}

static void OnTick()
{
	for (auto veh : GetAllVehs())
	{
		static bool toggle = true;

		SET_VEHICLE_REDUCE_GRIP(veh, toggle);
		
		SET_VEHICLE_FRICTION_OVERRIDE(veh, 0.f);

		toggle = !toggle;
	}
}

static RegisterEffect registerEffect(EFFECT_MISC_NO_FRICTION, nullptr, OnStop, OnTick);