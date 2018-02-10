using UnityEngine;
using System.Collections;

public class BaseWarlockClass : BaseCharacterClass {

	public BaseWarlockClass(){
		CharacterClassName = "Warlock";
		CharacterClassDescription = "A warlock";
		MainStat = MainStatBonuses.STRENGTH;
		SecondMainStat = SecondStatBonuses.ENDURANCE;
		BonusStat = BonusStatBonuses.OVERPOWER;
	}
}
