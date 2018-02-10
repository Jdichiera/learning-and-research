using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class ObjectPool : MonoBehaviour {
	public RecycleGameObject prefab;
	private List<RecycleGameObject> poolInstances = new List<RecycleGameObject>();
	private RecycleGameObject CreateInstance(Vector3 position){
		var clone = GameObject.Instantiate(prefab);
		clone.transform.position = position;
		clone.transform.parent = transform;

		poolInstances.Add(clone);

		return clone;
	}
	public RecycleGameObject NextObject(Vector3 position){
		RecycleGameObject instance = null;

		foreach(var gameObject in poolInstances){
			if (gameObject.gameObject.activeSelf != true) {
				instance = gameObject;
				instance.transform.position = position;
			}
		}

		if (instance == null) {
			instance = CreateInstance(position);
		}
		instance.Restart();
		return instance;
	}

}
