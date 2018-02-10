using UnityEngine;
using System.Collections;

public class TBC_StateMachine : MonoBehaviour {

	private bool hasAddedExp = false;

	public enum BattleStates{
		START,
		PLAYERCHOICE,
		ENEMYCHOICE,
		LOSE,
		WIN
	}

	private BattleStates currentState;

	// Use this for initialization
	void Start () {
		hasAddedExp = false;
		currentState = BattleStates.START;
	}
	
	// Update is called once per frame
	void Update () {
		Debug.Log (currentState);
		switch (currentState) {
		case(BattleStates.START):
			break;
		case(BattleStates.PLAYERCHOICE):
			break;
		case(BattleStates.ENEMYCHOICE):
			break;
		case(BattleStates.LOSE):
			break;
		case(BattleStates.WIN):
			if (!hasAddedExp) {
				IncreaseExperience.AddExperience ();
				hasAddedExp = true;
			}
			break;
		}

	}
	void OnGUI(){
		if (GUILayout.Button("NextState")) {
			if (currentState == BattleStates.START) {
				currentState = BattleStates.PLAYERCHOICE;
			} else if(currentState == BattleStates.PLAYERCHOICE) {
				currentState = BattleStates.ENEMYCHOICE;
			}else if(currentState == BattleStates.ENEMYCHOICE) {
				currentState = BattleStates.LOSE;
			}else if(currentState == BattleStates.LOSE) {
				currentState = BattleStates.WIN;
			}else if(currentState == BattleStates.WIN) {
				currentState = BattleStates.START;
			}
		}
	}
}
