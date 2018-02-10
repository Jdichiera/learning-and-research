using UnityEngine;
using System.Collections;

public class LoadInformation {
	public static void LoadAllInformation(){
		GameInformation.PlayerName = PlayerPrefs.GetString ("PLAYERNAME");
		GameInformation.PlayerLevel = PlayerPrefs.GetInt ("PLAYERLEVEL");
		GameInformation.Stamina = PlayerPrefs.GetInt ("STAMINA");
		GameInformation.Endurance = PlayerPrefs.GetInt ("ENDURANCE");
		GameInformation.Strength = PlayerPrefs.GetInt ("STRENGTH");
		GameInformation.Intellect = PlayerPrefs.GetInt ("INTELLECT");
		GameInformation.Agility = PlayerPrefs.GetInt ("AGILITY");
		GameInformation.Resistance = PlayerPrefs.GetInt ("RESISTANCE");
		GameInformation.Gold = PlayerPrefs.GetInt ("GOLD");

		Debug.Log ("Load Complete");

		if (PlayerPrefs.GetString("EQUIPMENT1") != null) {
			GameInformation.Equipment1 = (BaseEquipment)PPSerialization.Load("EQUIPMENT1");
		}
	}
}
