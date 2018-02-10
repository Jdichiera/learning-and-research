using UnityEngine;
using System.Collections;

public class BaseElfRace : BaseCharacterRace {

	public BaseElfRace(){
		RaceName = "Elf";
		RaceDescription = "Is an Elf";
		HasStrengthBonus = false;
		HasIntellectBonus = false;
		HasStaminaBonus = true;
		HasEnduranceBonus = true;
		HasOverpowerBonus = true;
		HasLuckBonus = false;
		HasMasteryBonus = false;
		HasCharismaBonus = false;
	}
}
