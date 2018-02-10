using UnityEngine;
using System.Collections;

public class BaseCharacterRace {

	private string raceName = "Needs a name";
	private string raceDescription = "Needs a race description";
	private bool hasStrengthBonus = false;
	private bool hasIntellectBonus= false;
	private bool hasStaminaBonus = false;
	private bool hasEnduranceBonus = false;
	private bool hasOverpowerBonus = false;
	private bool hasLuckBonus = false;
	private bool hasMasteryBonus = false;
	private bool hasCharismaBonus = false;

//	public BaseCharacterRace(){
//		raceName = "Needs a name";
//		raceDescription = "Needs a race description";
//		hasStrengthBonus = false;
//     	hasIntellectBonus= false;
//		hasEnduranceBonus = false;
//		hasStaminaBonus = false;
//		hasOverpowerBonus = false;
//		hasLuckBonus = false;
//     	hasMasteryBonus = false;
//     	hasCharismaBonus = false;
//
//
//	}
	public string RaceName { get{ return raceName; } set{ raceName = value; }}
	public string RaceDescription { get { return raceDescription;} set{ raceDescription = value; }}
	public bool HasStrengthBonus { get { return hasStrengthBonus;} set{ hasStrengthBonus = value; }}
	public bool HasIntellectBonus { get { return hasIntellectBonus;} set{ hasIntellectBonus = value; }}
	public bool HasStaminaBonus { get { return hasStaminaBonus;} set{ hasStaminaBonus = value; }}
	public bool HasEnduranceBonus { get { return hasEnduranceBonus;} set{ hasEnduranceBonus = value; }}
	public bool HasOverpowerBonus { get { return hasOverpowerBonus;} set{ hasOverpowerBonus = value; }}
	public bool HasLuckBonus { get { return hasLuckBonus;} set{ hasLuckBonus = value; }}
	public bool HasMasteryBonus { get { return hasMasteryBonus;} set{ hasMasteryBonus = value; }}
	public bool HasCharismaBonus {  get { return hasCharismaBonus;} set{ hasCharismaBonus = value; }}
}