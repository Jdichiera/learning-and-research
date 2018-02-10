using UnityEngine;
using System.Collections;

public static class IncreaseExperience {

	private static int expToGive;
	private static LevelUp levelUpScript = new LevelUp();

	public static void AddExperience(){
		expToGive = GameInformation.PlayerLevel * 100;
		GameInformation.CurrentExp += expToGive;
		CheckToSeeIfPlayerLeveled ();
		Debug.Log (expToGive);
	}



	private static void CheckToSeeIfPlayerLeveled(){
		if (GameInformation.CurrentExp >= GameInformation.RequiredExp) {
			levelUpScript.LevelUpCharacter ();
		}
	}

	 




//	private int DetermineExpForNextLevel(){
//		int playerLevel = 1;
//		int levels = 50;
//		float expLevel1 = 500.0f;
//		float expLevel50 = 400000.0f;
//		float temp1 = Mathf.Log (expLevel50 / expLevel1);
//		float b = temp1 / (levels - 1);
//		float temp2 = (Mathf.Exp (b) - 1);
//		float a = (expLevel1) / temp2;
//		int oldExp = (int)(a * Mathf.Exp ((float)b * (playerLevel - 1)));
//		int newExp = (int)(a * Mathf.Exp ((float)b * playerLevel));
//		int temp = newExp - oldExp;
//		//temp = (int)Mathf.Round((float)temp . 10.0f) * 10;
//		return temp;
//	}
}
