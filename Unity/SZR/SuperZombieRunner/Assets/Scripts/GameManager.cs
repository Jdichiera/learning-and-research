﻿using UnityEngine;
using System.Collections;
using UnityEngine.UI;
using System;

public class GameManager : MonoBehaviour {

	public Text scoreText;
	public GameObject playerPrefab;
	public Text continueText;
	private float bestTime = 0f;
	private float timeElapsed = 0f;
	private float blinkTime = 0f;
	private bool blink;
	private GameObject player;
	private GameObject floor;
	private Spawner spawner;
	private TimeManager timeManager;
	private bool gameStarted;
	private bool beatBestTime;

	void Awake(){
		floor = GameObject.Find("Foreground");
		spawner = GameObject.Find("Spawner").GetComponent<Spawner>();
		timeManager = GetComponent<TimeManager>();
	}
	// Use this for initialization
	void Start () {
		var floorHeight = floor.transform.localScale.y;
		var position = floor.transform.position;
		position.x = 0;
		position.y = -((Screen.height / PixelPerfectCamera.pixelsToUnits) / 2) + (floorHeight / 2);
		floor.transform.position = position;

		spawner.active = false;
		Time.timeScale = 0;
		continueText.text = "Press any button to start ...";
		bestTime = PlayerPrefs.GetFloat("BestTime");
	}
	
	// Update is called once per frame
	void Update () {
		if (!gameStarted && Time.timeScale == 0) {
			if (Input.anyKeyDown) {
				timeManager.ManipulateTime(1, 1f);
				ResetGame();
			}
		}
		if (!gameStarted) {
			blinkTime ++;
			if (blinkTime % 40 == 0) {
				blink = !blink;
			}
			continueText.canvasRenderer.SetAlpha(blink ? 0 : 1);
			var textColor = beatBestTime ? "#FF0" : "#FFF";
			scoreText.text = "Time: " + FormatTime(timeElapsed) + "\n<color=" + textColor + ">" + "Best: " + FormatTime(bestTime) + "</color>";
		} else {
			timeElapsed += Time.deltaTime;
			scoreText.text = "Time: " + FormatTime(timeElapsed);
		}
	}

	void OnPLayerKilled(){
		spawner.active = false;
		var playerDestroyScript = player.GetComponent<DestroyOffscreen>();
		playerDestroyScript.DestroyCallback -= OnPLayerKilled;
		player.GetComponent<Rigidbody2D>().velocity = Vector2.zero;
		timeManager.ManipulateTime(0, 5.5f);
		gameStarted = false;
		continueText.text = "Press any button to restart ...";
		if (timeElapsed > bestTime) {
			bestTime = timeElapsed;
			PlayerPrefs.SetFloat("BestTime", bestTime);
			beatBestTime = true;
		}
	}
	void ResetGame(){
		spawner.active = true;
		player = GameObjectUtil.Instantiate(playerPrefab, new Vector3(0, (Screen.height / PixelPerfectCamera.pixelsToUnits) / 2 + 100, 0));

		var playerDestroyScript = player.GetComponent<DestroyOffscreen>();
		playerDestroyScript.DestroyCallback += OnPLayerKilled;
		gameStarted = true;
		continueText.canvasRenderer.SetAlpha(0);
		timeElapsed = 0;
		beatBestTime = false;
	}

	string FormatTime(float value){
		TimeSpan t = TimeSpan.FromSeconds(value);
		return string.Format("{0:D2}:{1:D2}", t.Minutes, t.Seconds);
	}
}
