using UnityEngine;
using System.Collections;

public class CreatePlayerGUI : MonoBehaviour{

	public int pos1;
	public int pos2;
	public int pos3;
	public int pos4;


	public enum CreatePlayerStates
	{
		CLASSSELECTION, //Display all class types
		STATALLOCATION, //Allocate stats
		FINALSETUP //Name and hit create

	}

	private DisplayCreatePlayerFunctions displayFunctions = new DisplayCreatePlayerFunctions();
	public static CreatePlayerStates currentState;

	// Use this for initialization
	void Start () {
		currentState = CreatePlayerStates.CLASSSELECTION;

	}

	// Update is called once per frame
	void Update () {
		switch (currentState) {
		case(CreatePlayerStates.CLASSSELECTION):
			break;
		case(CreatePlayerStates.STATALLOCATION):
			break;
		case(CreatePlayerStates.FINALSETUP):
			break;
		}
	}

	void OnGUI(){

		if (currentState == CreatePlayerStates.CLASSSELECTION) {
			displayFunctions.DisplayMainItems ();
			displayFunctions.DisplayClassSelections ();
			//displayFunctions.CharacterCreationStateSwitch (CreatePlayerStates.CLASSSELECTION, CreatePlayerStates.STATALLOCATION);

		}
		if (currentState == CreatePlayerStates.STATALLOCATION) {
			displayFunctions.DisplayMainItems ();
			displayFunctions.DisplayStatAllocation ();
			//displayFunctions.CharacterCreationStateSwitch (CreatePlayerStates.CLASSSELECTION, CreatePlayerStates.FINALSETUP);

		}
		if (currentState == CreatePlayerStates.FINALSETUP) {
			displayFunctions.DisplayMainItems ();
			displayFunctions.DisplayFinalSetup ();
			//displayFunctions.CharacterCreationStateSwitch (CreatePlayerStates.STATALLOCATION, CreatePlayerStates.FINALSETUP);

		}
	}
}
