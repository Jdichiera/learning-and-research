using UnityEngine;
using System.Collections;

public class BasePotion : BaseStatItem {

	public enum PotionTypes{
		HEALTH,
		ENERGY,
		STRENGTH,
		INTELLECT,
		STAMINA,
		ENDURANCE,
		SPEED,
		OVERPOWER,
		MASTERY,
		LUCK,
		CHARISMA
	}

	private PotionTypes potionType;
	private int spellEffectId;

	public PotionTypes PotionType{
		get { return potionType;}
		set { potionType = value;}
	}
	public int SpellEffectId{
		get { return spellEffectId;}
		set { spellEffectId = value;}
	}
}
