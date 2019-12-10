#include <iostream>
#include <Windows.h>

#include "controller.hpp"

using namespace std;

int main()
{
	Controller controller(0);
	Sleep(1000);
	controller.setDeadZone(100);
	controller.setTriggerDeadZone(30);

	while (!controller.buttonBack())
	{
		cout << "u" << controller.buttonUp();
		cout << "d" << controller.buttonDown();
		cout << "l" << controller.buttonLeft();
		cout << "r" << controller.buttonRight();
		cout << "s" << controller.buttonStart();
		cout << "lb" << controller.buttonLB();
		cout << "RB" << controller.buttonRB();
		cout << "A" << controller.buttonA();
		cout << "B" << controller.buttonB();
		cout << "X" << controller.buttonX();
		cout << "Y" << controller.buttonY();
		cout << "L3" << controller.buttonL3();
		cout << "R3" << controller.buttonR3();
		cout << "LX" << controller.stickLeftX();
		cout << "LY" << controller.stickLeftY();
		cout << "RX" << controller.stickRightX();
		cout << "RY" << controller.stickRightY();
		cout << "LT" << controller.LT();
		cout << "RT" << controller.RT();
		

		int lv = controller.LT() * 100 / 255;
		int rv = controller.RT() * 100 / 255;

		cout << "LV" << lv;
		cout << "RV" << rv << endl;

		// controller.setMotorLeft(lv);
		// controller.setMotorRight(rv);
	}

	Controller a = controller;
	Controller b = a;
	Controller c = b;
	Controller d = c;


	return 0;
}