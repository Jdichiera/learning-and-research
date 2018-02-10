using UnityEngine;
using System.Collections;

public class BasePaladinClass : BaseCharacterClass {

	public BasePaladinClass(){
		CharacterClassName = "Paladin";
		CharacterClassDescription = "A paladin";
		MainStat = MainStatBonuses.STRENGTH;
		SecondMainStat = SecondStatBonuses.ENDURANCE;
		BonusStat = BonusStatBonuses.OVERPOWER;
	}
}
