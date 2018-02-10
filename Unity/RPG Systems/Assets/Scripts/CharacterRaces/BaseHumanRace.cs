using UnityEngine;
using System.Collections;

public class BaseHumanRace : BaseCharacterRace {

	public BaseHumanRace(){
		RaceName = "Human";
		RaceDescription = "Is a Human";
		HasStrengthBonus = true;
		HasIntellectBonus = false;
		HasStaminaBonus = true;
		HasEnduranceBonus = false;
		HasOverpowerBonus = false;
		HasLuckBonus = false;
		HasMasteryBonus = false;
		HasCharismaBonus = true;
	}
}
