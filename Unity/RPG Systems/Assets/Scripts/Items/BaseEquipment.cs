using UnityEngine;
using System.Collections;

[System.Serializable]
public class BaseEquipment : BaseStatItem {

	public enum EquipmentTypes{
		HEAD,
		CHEST,
		SHOULDERS,
		LEGS,
		FEET,
		NECK,
		EARRING,
		RING
	}

	private EquipmentTypes equipmentType;
	private int spellEffectId;

	public EquipmentTypes EquipmentType {
		get { return equipmentType;}
		set{ equipmentType = value;}
	}
	public int SpellEffectId {
		get { return spellEffectId;}
		set{ spellEffectId = value;}
	}
}
