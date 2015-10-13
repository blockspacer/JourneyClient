/////////////////////////////////////////////////////////////////////////////
// This file is part of the Journey MMORPG client                           //
// Copyright � 2015 SYJourney                                               //
//                                                                          //
// This program is free software: you can redistribute it and/or modify     //
// it under the terms of the GNU Affero General Public License as           //
// published by the Free Software Foundation, either version 3 of the       //
// License, or (at your option) any later version.                          //
//                                                                          //
// This program is distributed in the hope that it will be useful,          //
// but WITHOUT ANY WARRANTY; without even the implied warranty of           //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            //
// GNU Affero General Public License for more details.                      //
//                                                                          //
// You should have received a copy of the GNU Affero General Public License //
// along with this program.  If not, see <http://www.gnu.org/licenses/>.    //
//////////////////////////////////////////////////////////////////////////////
#pragma once
#include "CharEquips.h"
#include "WeaponData.h"

namespace Character
{
	void CharEquips::draw(Equipslot slot, string stance, CharacterLayer layer, uint8_t frame, DrawArgument* args)
	{
		if (equips.count(slot))
		{
			equips[slot]->draw(stance, layer, frame, args);
		}
	}

	void CharEquips::addequip(EquipData* eq)
	{
		Equipslot slot = eq->geteqslot();
		equips[slot] = eq;
	}

	void CharEquips::removeequip(Equipslot slot)
	{
		equips.erase(slot);
	}

	bool CharEquips::isvisible(Equipslot slot)
	{
		if (equips.count(slot))
		{
			if (equips[slot]->istransparent())
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}

	bool CharEquips::istwohanded()
	{
		if (equips.count(EQL_WEAPON))
		{
			WeaponData* weapon = reinterpret_cast<WeaponData*>(equips[EQL_WEAPON]);
			return weapon->istwohanded();
		}
		return false;
	}

	EquipData* CharEquips::getequip(Equipslot slot)
	{
		if (equips.count(slot))
		{
			return equips[slot];
		}
		else
		{
			return 0;
		}
	}
}