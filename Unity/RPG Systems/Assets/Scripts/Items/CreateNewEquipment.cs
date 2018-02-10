﻿using UnityEngine;
using System.Collections;

public class CreateNewEquipment : MonoBehaviour {

	private BaseEquipment newEquipment;
	private string[] itemNames = new string[4] {"Common", "Great", "Amazing", "Insane"};
	private string[] itemDescription = new string[2] {"A new cool item", "A new not so cool item"};


	// Use this for initialization
	void Start () {
		CreateEquipment ();
		Debug.Log (newEquipment.ItemName);
		Debug.Log (newEquipment.ItemDescription);
		Debug.Log (newEquipment.ItemId);
		Debug.Log (newEquipment.Endurance);
		Debug.Log (newEquipment.Stamina);
		Debug.Log (newEquipment.Strength);
		Debug.Log (newEquipment.Intellect);
		Debug.Log (newEquipment.SpellEffectId);
		Debug.Log (newEquipment.EquipmentType);
	}

	private void CreateEquipment(){
		newEquipment = new BaseEquipment ();
		newEquipment.ItemName = itemNames [Random.Range (0, itemNames.Length)] + " Item";
		newEquipment.ItemDescription = itemDescription [Random.Range (0, itemDescription.Length)];
		newEquipment.ItemId = Random.Range (1, 101);
		newEquipment.Endurance = Random.Range(1, 11);
		newEquipment.Stamina = Random.Range(1, 11);
		newEquipment.Strength = Random.Range(1, 11);
		newEquipment.Intellect = Random.Range(1, 11);
		newEquipment.SpellEffectId = Random.Range (1, 101);
		ChooseItemType ();
	}


	private void ChooseItemType(){
		int randomTemp = Random.Range (1, 9);
		if (randomTemp == 1) {
			newEquipment.EquipmentType = BaseEquipment.EquipmentTypes.HEAD;
		} else if (randomTemp == 2) {
			newEquipment.EquipmentType = BaseEquipment.EquipmentTypes.SHOULDERS;
		} else if (randomTemp == 3) {
			newEquipment.EquipmentType = BaseEquipment.EquipmentTypes.CHEST;
		} else if (randomTemp == 4) {
			newEquipment.EquipmentType = BaseEquipment.EquipmentTypes.EARRING;
		} else if (randomTemp == 5) {
			newEquipment.EquipmentType = BaseEquipment.EquipmentTypes.FEET;
		} else if (randomTemp == 6) {
			newEquipment.EquipmentType = BaseEquipment.EquipmentTypes.LEGS;
		} else if (randomTemp == 7) {
			newEquipment.EquipmentType = BaseEquipment.EquipmentTypes.NECK;
		} else if (randomTemp == 8) {
			newEquipment.EquipmentType = BaseEquipment.EquipmentTypes.RING;
		} 
	}
	// Update is called once per frame
	void Update () {
	
	}
}
