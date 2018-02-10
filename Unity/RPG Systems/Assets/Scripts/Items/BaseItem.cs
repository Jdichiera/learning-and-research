using UnityEngine;
using System.Collections;

[System.Serializable]
public class BaseItem {

	private string itemName;
	private string itemDescription;
	private int itemId;
	public enum ItemTypes{
		EQUPMENT,
		WEAPON,
		SCROLL,
		POTION,
		CHEST
	}

	private ItemTypes itemType;

	public string ItemName{
		get{ return itemName; }
		set{ itemName = value; }
	}
	public string ItemDescription{
		get{ return itemDescription; }
		set{ itemDescription = value; }
	}
	public int ItemId{
		get{ return itemId; }
		set{ itemId = value; }
	}
	public ItemTypes ItemType{
		get{ return itemType; }
		set{ itemType = value; }
	}
}
