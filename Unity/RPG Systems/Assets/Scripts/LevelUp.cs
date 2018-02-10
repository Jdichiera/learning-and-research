using UnityEngine;
using System.Collections;

public class LevelUp {

	public int maxPlayerLevel = 50;
	public void LevelUpCharacter(){
		//check to see if current xp is > than required
		if (GameInformation.CurrentExp > GameInformation.RequiredExp) {
			GameInformation.CurrentExp -= GameInformation.RequiredExp;
		} else {
			GameInformation.CurrentExp = 0;
		}
		if (GameInformation.PlayerLevel < maxPlayerLevel) {
			GameInformation.PlayerLevel++;
		} else {
			GameInformation.PlayerLevel = maxPlayerLevel;
		}
		DetermineRequiredExp ();
	}

	private void DetermineRequiredExp(){
		int temp = GameInformation.PlayerLevel * 1000 + 250;
		GameInformation.RequiredExp = temp;
	}
}
