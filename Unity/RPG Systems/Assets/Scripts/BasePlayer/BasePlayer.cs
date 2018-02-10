using UnityEngine;
using System.Collections;

public class BasePlayer {

	private string playerName;
	private int playerLevel;
	private BaseCharacterClass playerClass;

	private int stamina; //Health modifier
	private int endurance; //Energy mod
	private int intellect; //Magic damage mod
	private int strength; // Physical damage mod
	private int agility; // Haste and crit mod
	private int resistance; // all damage reduction

	private int gold; //$$$

	private int currentExp;
	private int requiredExp;

	private int statPointsToAllocate;




	public string PlayerName{
		get{ return playerName;}
		set{ playerName = value;}
	}
	public int PlayerLevel{
		get{ return playerLevel;}
		set{ playerLevel = value;}
	}
	public BaseCharacterClass PlayerClass{
		get{ return playerClass;}
		set{ playerClass = value;}
	}
	public int Stamina{
		get{ return stamina;}
		set{ stamina = value;}
	}
	public int Endurance{
		get{ return endurance;}
		set{ endurance = value;}
	}
	public int Intellect{
		get{ return intellect;}
		set{ intellect = value;}
	}
	public int Strength{
		get{ return strength;}
		set{ strength = value;}
	}
	public int CurrentExp{
		get{ return currentExp;}
		set{ currentExp = value;}
	}	
	public int RequiredExp{
		get{ return requiredExp;}
		set{ requiredExp = value;}
	}
	public int Agility{
		get{ return agility;}
		set{ agility = value;}
	}
	public int Resistance{
		get{ return resistance;}
		set{ resistance = value;}
	}
	public int Gold{
		get{ return gold;}
		set{ gold = value;}
	}
	public int StatPointsToAllocate{
		get{ return statPointsToAllocate; }
		set{ statPointsToAllocate = value; }
	}
}
