using UnityEngine;
using System.Collections;

public class PlayerAnimationManager : MonoBehaviour {

	private Animator animator;
	private InputState inputState;

	void Awake(){
		animator = GetComponent<Animator>();
		inputState = GetComponent<InputState>();
	}
	// Update is called once per frame
	void Update () {
		var running = true;
		if (inputState.absVelocityX > 0 && inputState.absVelocityY <= inputState.standingThreshhold) 
			running = false;
		animator.SetBool("Running", running);
	}
}
