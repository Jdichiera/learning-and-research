﻿using UnityEngine;
using System.Collections;

public class CameraController : MonoBehaviour {

	public Transform cameraTarget;
	private float x = 0.0f;
	private float y = 0.0f;
	private int mouseXSpeedMod = 5;
	private int mouseYSpeedMod = 3;

	public float maxViewDistance = 25.0f;
	public float minViewDistance = 2.0f;
	public int zoomRate = 30;
	public int lerpRate = 5;
	public float cameraTargetHeight = 1.5f;
	private float distance = 3.0f;
	private float desiredDistance;
	private float correctedDistance;
	private float currentDistance;

	// Use this for initialization
	void Start () {
		Vector3 angles = transform.eulerAngles;
		x = angles.x;
		y = angles.y;

		currentDistance = distance;
		desiredDistance = distance;
		correctedDistance = distance;
	}

	void LateUpdate(){
		if (Input.GetMouseButton(0)) {
			x += Input.GetAxis("Mouse X") * mouseXSpeedMod;
			y -= Input.GetAxis("Mouse Y") * mouseYSpeedMod;
		} else if (Input.GetAxis("Vertical") != 0 || Input.GetAxis("Horizontal") != 0) {
			float targetRotationAngle = cameraTarget.eulerAngles.y;
			float cameraRotationAngle = transform.eulerAngles.y;
			x = Mathf.LerpAngle (cameraRotationAngle, targetRotationAngle, lerpRate * Time.deltaTime);
		}



		y = ClampAngle(y,-50,80);
		Quaternion rotation = Quaternion.Euler(y,x,0);

		desiredDistance -= Input.GetAxis ("Mouse ScrollWheel") * Time.deltaTime * zoomRate * Mathf.Abs(desiredDistance);
		desiredDistance = Mathf.Clamp(desiredDistance, minViewDistance, maxViewDistance);
		correctedDistance = desiredDistance;

		Vector3 position = cameraTarget.position - (rotation * Vector3.forward * desiredDistance);

		RaycastHit collisionHit;
		Vector3 cameraTargetPosition = new Vector3 (cameraTarget.position.x, cameraTarget.position.y + cameraTargetHeight, cameraTarget.position.z);
		bool isCorrected = false;

		if (Physics.Linecast(cameraTargetPosition, position, out collisionHit)) {
			position = collisionHit.point;
			correctedDistance = Vector3.Distance (cameraTargetPosition, position);
			isCorrected = true;
		}

		currentDistance = !isCorrected || correctedDistance > currentDistance ? Mathf.Lerp (currentDistance, correctedDistance, Time.deltaTime * zoomRate) : correctedDistance;

		position = cameraTarget.position - (rotation * Vector3.forward * currentDistance + new Vector3(0, -cameraTargetHeight, 0));


		transform.rotation = rotation;
		transform.position = position;
	}


	private static float ClampAngle(float angle,float min,float max){
		if (angle < -360) {
			angle += 360;
		}

		if (angle > 360) {
			angle -= 360;
		}
		return Mathf.Clamp(angle,min,max);
	}
}