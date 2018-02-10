﻿using UnityEngine;
using System.Collections;

public class TestScript : MonoBehaviour {

	// Use this for initialization
	void Start () {
		LoadInformation.LoadAllInformation ();

		Debug.Log ("PlayerName: " + GameInformation.PlayerName);
		Debug.Log ("Player Level: " + GameInformation.PlayerLevel);
		Debug.Log ("Player Stamina: " + GameInformation.Stamina);
		Debug.Log ("Player Endurance: " + GameInformation.Endurance);
		Debug.Log ("Player Intellect: " + GameInformation.Intellect);
		Debug.Log ("Player Strength: " + GameInformation.Strength);
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
