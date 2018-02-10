using UnityEngine;
using System.Collections;

[System.Serializable]
public class BaseStatItem : BaseItem {

	private int stamina;
	private int endurance;
	private int strength;
	private int intellect;
	private int overPower;
	private int luck;
	private int mastery;
	private int charisma;

	public int Stamina{get{ return stamina;}set{ stamina = value;}}
	public int Endurance{get{ return endurance;}set{ endurance = value;}}
	public int Strength{ get { return strength; } set { strength = value; } }
	public int Intellect{ get { return intellect; } set { intellect = value; } }
	public int Overpower{get{ return overPower;}set{ overPower = value;}}
	public int Luck	{get{ return luck;}set{ luck = value;}}
	public int Mastery	{get{ return mastery;}set{ mastery = value;}}
	public int Charisma	{get{ return charisma;}set{ charisma = value;}}
}