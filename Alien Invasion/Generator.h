#pragma once
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;






void Earthgenerator() {
	int A = rand() % 100;
	if (A < prob) {
		for (int i = 0; i < N; i++) {
		int B = rand() % 100;
			if(B<=ES) {
				//ES
			}
			else if (B <= ES + ET) {
				//ET
			}
			else if (B <= ES + ET + EG) {
				//EG
			}
		}
	}

}

void Aliengenerator() {
	int A = rand() % 100;
	if (A < prob) {
		for (int i = 0; i < N; i++) {
			int B = rand() % 100;
			if (B <= AS) {
				//AS
			}
			else if (B <= AS + AM) {
				//AM
			}
			else if (B <= AS + AM + AD) {
				//AD
			}
		}
	}
}

void stepgenerator() {
	Earthgenerator();
	Aliengenerator();
}

