using UnityEngine;
using System.Collections;

public class BaseDwarfRace : BaseCharacterRace {

	public BaseDwarfRace(){
		RaceName = "Dwarf";
		RaceDescription = "Is a Dwarf";
		HasStrengthBonus = true;
		HasIntellectBonus = true;
		HasStaminaBonus = false;
		HasEnduranceBonus = false;
		HasOverpowerBonus = false;
		HasLuckBonus = false;
		HasMasteryBonus = true;
		HasCharismaBonus = false;
	}
}
