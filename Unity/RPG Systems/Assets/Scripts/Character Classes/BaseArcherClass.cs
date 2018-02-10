using UnityEngine;
using System.Collections;

public class BaseArcherClass : BaseCharacterClass {

	public BaseArcherClass(){
		CharacterClassName = "Archer";
		CharacterClassDescription = "An archer";
		MainStat = MainStatBonuses.STRENGTH;
		SecondMainStat = SecondStatBonuses.ENDURANCE;
		BonusStat = BonusStatBonuses.OVERPOWER;
	}
}
