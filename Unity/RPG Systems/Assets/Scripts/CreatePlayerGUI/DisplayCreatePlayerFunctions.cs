using UnityEngine;
using System.Collections;

public class DisplayCreatePlayerFunctions  {


	private StatAllocationModule statAllocationModule = new StatAllocationModule();
	private int classSelection;
	private string playerFirstName = "Enter First Name";
	private string playerLastName = "Enter Last Name";
	private string playerBio = "Enter player bio";
	private int genderSelection;
	private string[] genderTypes = new string[2] {"Male", "Female"};
	private string[] classSelectionNames = new string[]{"Mage", "Warrior", "Archer", "Rogue", "Warlock", "Paladin"};
	public void DisplayClassSelections(){
		classSelection = GUI.SelectionGrid (new Rect (50, 50, 250, 300), classSelection, classSelectionNames, 3);
		GUI.Label (new Rect (450, 50, 300, 300), FindClassDescription (classSelection));
		GUI.Label (new Rect (450, 70, 300, 300), FindClassStatValues (classSelection));

	}

//	public void CharacterCreationStateSwitch(CreatePlayerGUI.CreatePlayerStates previousState, CreatePlayerGUI.CreatePlayerStates nextState){
//		if (GUI.Button(new Rect(45, 450, 50, 25),"Back")) {
//			CreatePlayerGUI.currentState = previousState;
//		}
//		if (GUI.Button(new Rect(150, 450, 50, 25),"Next")) {
//			CreatePlayerGUI.currentState = nextState;
//
//		}
//	}
	private string FindClassDescription(int classSelection){
		if (classSelection == 0) {
			BaseCharacterClass tempClass = new BaseMageClass ();
			return tempClass.CharacterClassDescription;
		} else if (classSelection == 1) {
			BaseCharacterClass tempClass = new BaseWarriorClass ();
			return tempClass.CharacterClassDescription;
		}
		return "No class found";
	}

	private string FindClassStatValues(int classSelection){
		if (classSelection == 0) {
			BaseCharacterClass tempClass = new BaseMageClass ();
			string tempStats = GenerateCharacterStatString (tempClass);
			return tempStats;
		} else if (classSelection == 1) {
			BaseCharacterClass tempClass = new BaseWarriorClass ();
			string tempStats = GenerateCharacterStatString (tempClass);
			return tempStats;
		} 
		return "No stats found";
	}

	public void DisplayStatAllocation(){
		statAllocationModule.DisplayStatAllocationModule();
	}

	public void DisplayFinalSetup(){
		playerFirstName = GUI.TextArea(new Rect(20, 10, 150, 25), playerFirstName, 25);
		playerLastName = GUI.TextArea (new Rect (20, 55, 150, 25), playerLastName, 25);
		playerBio = GUI.TextArea (new Rect (20, 90, 250, 200), playerBio, 300);
		genderSelection = GUI.SelectionGrid (new Rect (200, 10, 150, 55), genderSelection, genderTypes, 1);
	}

	private void ChooseClass(int classSelection){
		if (classSelection == 0) {
			GameInformation.PlayerClass = new BaseMageClass ();
		} else if (classSelection == 1) {
			GameInformation.PlayerClass = new BaseWarriorClass ();
		}
	}
	public void DisplayMainItems(){
		Transform player = GameObject.FindGameObjectWithTag ("Player").transform;
		GUI.Label (new Rect (Screen.width / 2, 20, 250, 100), "Create New Player");
		if (GUI.Button(new Rect(340, 410, 50, 50), "<<<")) {
			player.Rotate (Vector3.up * 10);
			//turn transform tagges as player to left
		}
		if (GUI.Button(new Rect(470, 410, 50, 50), ">>>")) {
				//turn transform tagges as player to right
			player.Rotate (Vector3.down * 10);

		}
		if (CreatePlayerGUI.currentState != CreatePlayerGUI.CreatePlayerStates.CLASSSELECTION) {
			if (GUI.Button(new Rect(45, 450, 50, 25),"Back")) {
				//CreatePlayerGUI.currentState = CreatePlayerGUI.CreatePlayerStates.CLASSSELECTION;
				if (CreatePlayerGUI.currentState == CreatePlayerGUI.CreatePlayerStates.STATALLOCATION) {
					statAllocationModule.didRunOnce = false;
					GameInformation.PlayerClass = null;
					CreatePlayerGUI.currentState = CreatePlayerGUI.CreatePlayerStates.CLASSSELECTION;
				} else if (CreatePlayerGUI.currentState == CreatePlayerGUI.CreatePlayerStates.FINALSETUP) {
					CreatePlayerGUI.currentState = CreatePlayerGUI.CreatePlayerStates.STATALLOCATION;
				}
			}
		}



		if (CreatePlayerGUI.currentState != CreatePlayerGUI.CreatePlayerStates.FINALSETUP) {
			if (GUI.Button(new Rect(150, 450, 50, 25),"Next")) {
				if (CreatePlayerGUI.currentState == CreatePlayerGUI.CreatePlayerStates.CLASSSELECTION) {
					CreatePlayerGUI.currentState = CreatePlayerGUI.CreatePlayerStates.STATALLOCATION;
					ChooseClass (classSelection);
				} else if (CreatePlayerGUI.currentState == CreatePlayerGUI.CreatePlayerStates.STATALLOCATION) {
					GameInformation.Stamina = statAllocationModule.pointsToAllocate [0];
					GameInformation.Endurance = statAllocationModule.pointsToAllocate [1];
					GameInformation.Intellect = statAllocationModule.pointsToAllocate [2];
					GameInformation.Strength = statAllocationModule.pointsToAllocate [3];
					GameInformation.Agility = statAllocationModule.pointsToAllocate [4] ;
					GameInformation.Resistance = statAllocationModule.pointsToAllocate [5];
					CreatePlayerGUI.currentState = CreatePlayerGUI.CreatePlayerStates.FINALSETUP;
				}
			}
		} else if(CreatePlayerGUI.currentState == CreatePlayerGUI.CreatePlayerStates.FINALSETUP){
			if (GUI.Button (new Rect (150, 450, 50, 25), "Finish")) {
				GameInformation.PlayerName = playerFirstName + " " + playerLastName;
				GameInformation.PlayerBio = playerBio;
				if (genderSelection == 0) {
					
					GameInformation.IsMale = true;
				} else if (genderSelection == 1) {
					GameInformation.IsMale = false;
				}
				SaveInformation.SaveAllInformation ();
			}
		}
	}

	public string GenerateCharacterStatString(BaseCharacterClass characterClass){
		string tempStats = "Stamina: " + characterClass.Stamina + "\n"
		                   + "Endurance: " + characterClass.Endurance + "\n"
		                   + "Strength: " + characterClass.Strength + "\n"
		                   + "Intellect: " + characterClass.Intellect + "\n";
		return tempStats;
	}
	
}