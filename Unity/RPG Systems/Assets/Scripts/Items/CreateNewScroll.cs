using UnityEngine;
using System.Collections;

public class CreateNewScroll : MonoBehaviour {

	private BaseScroll newScroll;
	// Use this for initialization
	void Start () {
		CreateScroll ();
		Debug.Log (newScroll.ItemName);
		Debug.Log (newScroll.ItemDescription);
		Debug.Log (newScroll.ItemId);
		Debug.Log (newScroll.SpellEffectId);
	}
	
	private void CreateScroll(){
		newScroll = new BaseScroll();
		newScroll.ItemName = "Scroll";
		newScroll.ItemDescription = "A powerful scroll";
		newScroll.ItemId = Random.Range (1, 101);
		newScroll.SpellEffectId = Random.Range (500, 1000);
	}
}
