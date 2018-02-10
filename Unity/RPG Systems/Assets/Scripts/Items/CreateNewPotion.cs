using UnityEngine;
using System.Collections;

public class CreateNewPotion : MonoBehaviour {

	private BasePotion newPotion;

	// Use this for initialization
	void Start () {
		CreatPotion ();
		Debug.Log (newPotion.ItemName);
		Debug.Log (newPotion.ItemDescription);
		Debug.Log (newPotion.ItemId);
		Debug.Log (newPotion.PotionType);
	}

	private void CreatPotion(){
		newPotion = new BasePotion ();
		newPotion.ItemName = "Potion";
		newPotion.ItemDescription = "A potion";
		newPotion.ItemId = Random.Range (1, 101);
		ChoosePotionType ();
	}

	private void ChoosePotionType(){
		System.Array potions = System.Enum.GetValues (typeof(BasePotion.PotionTypes));
		newPotion.PotionType = (BasePotion.PotionTypes)potions.GetValue (Random.Range (0, potions.Length));

//		int randomTemp = Random.Range (0, 7);
//		if (randomTemp == 0) {
//			newPotion.PotionType = BasePotion.PotionTypes.ENDURANCE;
//		} else if (randomTemp == 1) {
//			newPotion.PotionType = BasePotion.PotionTypes.ENERGY;
//		} else if (randomTemp == 2) {
//			newPotion.PotionType = BasePotion.PotionTypes.HEALTH;
//		} else if (randomTemp == 3) {
//			newPotion.PotionType = BasePotion.PotionTypes.INTELLECT;
//		} else if (randomTemp == 4) {
//			newPotion.PotionType = BasePotion.PotionTypes.SPEED;
//		} else if (randomTemp == 5) {
//			newPotion.PotionType = BasePotion.PotionTypes.STRENGTH;
//		} else if (randomTemp == 6) {
//			newPotion.PotionType = BasePotion.PotionTypes.VITALITY;
//		} 
	}
}
