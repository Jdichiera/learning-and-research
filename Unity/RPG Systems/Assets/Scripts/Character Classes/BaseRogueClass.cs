using UnityEngine;
using System.Collections;

public class BaseRogueClass : BaseCharacterClass {

	public BaseRogueClass(){
		CharacterClassName = "Rogue";
		CharacterClassDescription = "A rogue";
		MainStat = MainStatBonuses.STRENGTH;
		SecondMainStat = SecondStatBonuses.ENDURANCE;
		BonusStat = BonusStatBonuses.OVERPOWER;
	}
}
