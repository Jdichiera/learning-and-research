using UnityEngine;
using System.Collections;

public class BaseCharacterClass {

	private string characterClassName;
	private string characterClassDescription;

	private int stamina = 12;
	private int endurance = 10;
	private int strength = 8;
	private int intellect = 8;
	private int overPower = 10;
	private int luck = 10;
	private int mastery = 10;
	private int charisma = 10;

	public enum MainStatBonuses{
		STAMINA,
		ENDURANCE,
		STRENGTH,
		INTELLECT
	}

	public enum SecondStatBonuses{
		STAMINA,
		ENDURANCE,
		STRENGTH,
		INTELLECT
	}

	public enum BonusStatBonuses{
		LUCK,
		OVERPOWER,
		MASTERY,
		CHARISMA
	}

	public string CharacterClassName{ get{ return characterClassName;}set{ characterClassName = value;}}
	public string CharacterClassDescription{get{ return characterClassDescription;}set{ characterClassDescription = value;}}

	public int Stamina{get{ return stamina;}set{ stamina = value;}}
	public int Endurance{get{ return endurance;}set{ endurance = value;}}
	public int Strength{ get { return strength; } set { strength = value; } }
	public int Intellect{ get { return intellect; } set { intellect = value; } }
	public int Overpower{get{ return overPower;}set{ overPower = value;}}
	public int Luck	{get{ return luck;}set{ luck = value;}}
	public int Mastery	{get{ return mastery;}set{ mastery = value;}}
	public int Charisma	{get{ return charisma;}set{ charisma = value;}}

	public MainStatBonuses MainStat { get; set; }
	public SecondStatBonuses SecondMainStat {get; set;}
	public BonusStatBonuses BonusStat { get; set; }
}


