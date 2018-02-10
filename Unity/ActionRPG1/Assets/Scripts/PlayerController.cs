﻿using UnityEngine;
using System.Collections;

public class PlayerController : MonoBehaviour {

	public float moveSpeed;
	private Animator animator;
	private bool playerMoving;
	private Vector2 lastMove;

	// Use this for initialization
	void Start () {
		animator = GetComponent<Animator> ();
		
	
	}
	
	// Update is called once per frame
	void Update () {
		playerMoving = false;

		if (Input.GetAxisRaw("Horizontal") > 0.5f || Input.GetAxisRaw("Horizontal") < -0.5f) {
			transform.Translate (new Vector3 (Input.GetAxisRaw ("Horizontal") * moveSpeed * Time.deltaTime, 0, 0));
			playerMoving = true;
			lastMove = new Vector2 (Input.GetAxisRaw("Horizontal"), 0f);
		} 

		if (Input.GetAxisRaw ("Vertical") > 0.5f || Input.GetAxisRaw ("Vertical") < -0.5f) {
			transform.Translate (new Vector3 (0, Input.GetAxisRaw ("Vertical") * moveSpeed * Time.deltaTime, 0));
			playerMoving = true;
			lastMove = new Vector2 (0, Input.GetAxisRaw ("Vertical"));
		} 
	

		animator.SetFloat ("MoveX", Input.GetAxisRaw ("Horizontal"));
		animator.SetFloat ("MoveY", Input.GetAxisRaw ("Vertical"));
		animator.SetFloat ("LastMoveX", lastMove.x);
		animator.SetFloat ("LastMoveY", lastMove.y);
		animator.SetBool ("PlayerMoving", playerMoving);
	}
}
