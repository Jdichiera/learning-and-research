﻿using UnityEngine;
using System.Collections;

public class CreateNewWeapon : MonoBehaviour {

	private BaseWeapon newWeapon;

	void Start(){
		CreateWeapon ();
		Debug.Log (newWeapon.ItemName);
		Debug.Log (newWeapon.ItemDescription);
		Debug.Log (newWeapon.ItemId);
		Debug.Log (newWeapon.Endurance);
		Debug.Log (newWeapon.Stamina);
		Debug.Log (newWeapon.Strength);
		Debug.Log (newWeapon.Intellect);
		Debug.Log (newWeapon.SpellEffectId);
		Debug.Log (newWeapon.WeaponType);


	}

	public void CreateWeapon(){
		newWeapon = new BaseWeapon ();
		newWeapon.ItemName = "W" + Random.Range (1, 101);
		newWeapon.ItemDescription = "This is a new weapon.";
		newWeapon.ItemId = Random.Range (1, 101);
		newWeapon.Endurance = Random.Range(1, 11);
		newWeapon.Stamina = Random.Range(1, 11);
		newWeapon.Strength = Random.Range(1, 11);
		newWeapon.Intellect = Random.Range(1, 11);
		newWeapon.SpellEffectId = Random.Range (1, 101);
		ChooseWeaponType ();
	}

	private void ChooseWeaponType(){
		System.Array weapons = System.Enum.GetValues (typeof(BaseWeapon.WeaponTypes));
		newWeapon.WeaponType = (BaseWeapon.WeaponTypes)weapons.GetValue(Random.Range(0, weapons.Length));
//		int randomTemp = Random.Range (1, 7);
//		if (randomTemp == 1) {
//			newWeapon.WeaponType = BaseWeapon.WeaponTypes.SWORD;
//		}else if(randomTemp == 2){
//			newWeapon.WeaponType = BaseWeapon.WeaponTypes.STAFF;
//		}else if(randomTemp == 3){
//			newWeapon.WeaponType = BaseWeapon.WeaponTypes.DAGGER;
//		}else if(randomTemp == 4){
//			newWeapon.WeaponType = BaseWeapon.WeaponTypes.BOW;
//		}else if(randomTemp == 5){
//			newWeapon.WeaponType = BaseWeapon.WeaponTypes.SHIELD;
//		}else if(randomTemp == 6){
//			newWeapon.WeaponType = BaseWeapon.WeaponTypes.POLEARM;
//		}
	}

}