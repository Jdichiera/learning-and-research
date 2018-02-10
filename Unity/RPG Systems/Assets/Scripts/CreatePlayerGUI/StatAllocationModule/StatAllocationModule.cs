using UnityEngine;
using System.Collections;

public class StatAllocationModule {
	private string[] statNames = new string[8]{ "Stamina", "Endurance", "Intellect", "Strength", "Overpower", "Luck", "Mastery", "Charisma" };
	private string[] statDescriptions = new string[8] {"Health Modifier", "Energy Modifier", "Magical Damage Modifier", "Physical Damage Modifier" , "Overpower", "Luck", "Mastery", "Charisma"};
	private bool[] statSelections = new bool[8];
	public int[] pointsToAllocate = new int[8];
	private int[] baseStatPoints = new int[8];

	private int availablePoints = 5;
	public bool didRunOnce = false;

	public void DisplayStatAllocationModule(){
		if (!didRunOnce) {
			RetrieveStatBaseStatPoints ();
			didRunOnce = true;
		}
		DisplayStatSToggleSwitches ();
		DisplayStatIncreaseDecreaseButtons ();
	}

	private void DisplayStatSToggleSwitches(){
		for (int i = 0; i < statNames.Length; i++) {
			statSelections [i] = GUI.Toggle (new Rect (10 , 60 * i + 10, 100, 50), statSelections [i], statNames [i]);
			GUI.Label (new Rect (100, 60 * i + 10, 50, 50), pointsToAllocate [i].ToString ());
			if (statSelections[i]) {
				GUI.Label (new Rect (20, 60 * i + 30, 150, 100), statDescriptions[i]);
			}
		}
	}

	private void DisplayStatIncreaseDecreaseButtons(){
		for (int i = 0; i < pointsToAllocate.Length; i++) {
			if (pointsToAllocate [i] >= baseStatPoints [i] && availablePoints > 0) {
				if (GUI.Button (new Rect (200, 60 * i + 10, 50, 50), "+")) {
					pointsToAllocate [i] += 1;
					--availablePoints;
				}
			}
				if (pointsToAllocate[i] > baseStatPoints[i]) {
					if (GUI.Button(new Rect(260,60 * i + 10, 50, 50), "-")) {
						pointsToAllocate [i] -= 1;
						++availablePoints;
					}
				}
			}
		}


	private void RetrieveStatBaseStatPoints(){
		BaseCharacterClass cClass = GameInformation.PlayerClass;
		pointsToAllocate [0] = cClass.Stamina;
		pointsToAllocate [1] = cClass.Endurance;
		pointsToAllocate [2] = cClass.Intellect;
		pointsToAllocate [3] = cClass.Strength;
		pointsToAllocate [4] = cClass.Overpower;
		pointsToAllocate [5] = cClass.Luck;
		pointsToAllocate [6] = cClass.Mastery;
		pointsToAllocate [7] = cClass.Charisma;


		baseStatPoints [0] = cClass.Stamina;
		baseStatPoints [1] = cClass.Endurance;
		baseStatPoints [2] = cClass.Intellect;
		baseStatPoints [3] = cClass.Strength;
		baseStatPoints [4] = cClass.Overpower;
		baseStatPoints [5] = cClass.Luck;
		baseStatPoints [6] = cClass.Mastery;
		baseStatPoints [7] = cClass.Charisma;

	}

//	private void DisplayStatDescriptions(bool[] statSelections){
//		if (statSelections[0]) {
//			GUI.Label (new Rect (20, 90, 100, 50), statDescriptions [0]);
//		}
//		if (statSelections[1]) {
//			GUI.Label (new Rect (20, 90, 100, 50), statDescriptions [1]);
//		}
//		if (statSelections[2]) {
//			GUI.Label (new Rect (20, 90, 100, 50), statDescriptions [2]);
//		}
//		if (statSelections[3]) {
//			GUI.Label (new Rect (20, 90, 100, 50), statDescriptions [3]);
//		}
//		if (statSelections[4]) {
//			GUI.Label (new Rect (20, 90, 100, 50), statDescriptions [4]);
//		}
//		if (statSelections[5]) {
//			GUI.Label (new Rect (20, 90, 100, 50), statDescriptions [5]);
//		}
//	}

}
