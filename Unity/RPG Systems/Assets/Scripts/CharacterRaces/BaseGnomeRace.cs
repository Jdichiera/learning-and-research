using UnityEngine;
using System.Collections;

public class BaseGnomeRace : BaseCharacterRace {

	public BaseGnomeRace(){
		RaceName = "Gnome";
		RaceDescription = "Is a Gnome";
		HasStrengthBonus = false;
		HasIntellectBonus = true;
		HasStaminaBonus = false;
		HasEnduranceBonus = true;
		HasOverpowerBonus = false;
		HasLuckBonus = true;
		HasMasteryBonus = false;
		HasCharismaBonus = false;
	}
}
