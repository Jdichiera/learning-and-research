using UnityEngine;
using System.Collections;

public class BaseWeapon : BaseStatItem { //BaseWeapon <- BaseStatItem <- BaseItem

	public enum WeaponTypes{
		SWORD,
		STAFF,
		DAGGER,
		BOW,
		SHIELD,
		POLEARM
	}

	private WeaponTypes weaponType;
	private int spellEffectId;

	public WeaponTypes WeaponType{
		get { return weaponType;}
		set { weaponType = value;}
	}

	public int SpellEffectId{
		get { return spellEffectId;}
		set { spellEffectId = value;}
	}
}