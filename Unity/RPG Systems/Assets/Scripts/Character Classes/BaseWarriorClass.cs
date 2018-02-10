using UnityEngine;
using System.Collections;

public class BaseWarriorClass : BaseCharacterClass {

	public BaseWarriorClass(){
		CharacterClassName = "Warrior";
		CharacterClassDescription = "A strong warrior";
		MainStat = MainStatBonuses.STRENGTH;
		SecondMainStat = SecondStatBonuses.ENDURANCE;
		BonusStat = BonusStatBonuses.OVERPOWER;
	}
}
