using UnityEngine;
using System.Collections;

public class DestroyOffscreen : MonoBehaviour {

	public delegate void OnDestroy();
	public event OnDestroy DestroyCallback;
	public float offset = 16f;
	private bool offScreen;
	private float offScreenX = 0;
	private Rigidbody2D body2d;
	// Use this for initialization
	void Awake () {
		body2d = GetComponent<Rigidbody2D>();
	}
	void Start () {
		offScreenX = (Screen.width / PixelPerfectCamera.pixelsToUnits) / 2 + offset;
	}
	// Update is called once per frame
	void Update () {
		var positionX = transform.position.x;
		var directionX = body2d.velocity.x;

		if (Mathf.Abs(positionX) > offScreenX) {
			if (directionX < 0 && positionX < -offScreenX) {
				offScreen = true;
			}else if (directionX > 0 && positionX > offScreenX) {
				offScreen = true;
			}
		}else {
			offScreen = false;
		}
		if (offScreen) {
			OnOutOfBounds();
		}
	}
	
	public void OnOutOfBounds(){
		offScreen = false;
		GameObjectUtil.Destroy(gameObject);

		if (DestroyCallback != null) {
			DestroyCallback();
		}
	}
}
