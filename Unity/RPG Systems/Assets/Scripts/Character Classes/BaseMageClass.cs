using UnityEngine;
using System.Collections;

public class BaseMageClass : BaseCharacterClass {

	public BaseMageClass(){
		CharacterClassName = "Mage";
		CharacterClassDescription = "A wise wizard";
		MainStat = MainStatBonuses.INTELLECT;
		SecondMainStat = SecondStatBonuses.STRENGTH;
		BonusStat = BonusStatBonuses.MASTERY;
	}
}