﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class control : MonoBehaviour {

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		if(Input.GetKey(KeyCode.UpArrow)){
			transform.Translate (-1, 0, 0);
		}
		if(Input.GetKey(KeyCode.DownArrow)){
			transform.Translate (1, 0, 0);
		}
		if(Input.GetKey(KeyCode.LeftArrow)){
			transform.Translate (0, 0, -1);
		}
		if(Input.GetKey(KeyCode.RightArrow)){
			transform.Translate (0, 0, 1);
		}
	}
}

