using UnityEngine;
using System.Collections;

public class PixelPerfectCamera : MonoBehaviour {

	//Camera properties
	public static float pixelsToUnits = 1f;
	public static float scale = 1f;
	public Vector2 nativeResolution = new Vector2 (240, 160);

	// Use this for initialization
	void Awake () {
		//grab camera
		var camera = GetComponent<Camera>();
		//Scale up camera from native resolution based on screen
		if (camera.orthographic) {
			scale = Screen.height / nativeResolution.y;
			pixelsToUnits *= scale;
			camera.orthographicSize = (Screen.height / 2.0f) / pixelsToUnits;
		}
	}

}
