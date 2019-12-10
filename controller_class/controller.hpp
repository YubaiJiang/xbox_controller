#pragma once
class Controller
{
private:
	int dead_zone = 10;
	int trigger_dead_zone = 10;
	int index;
public:
	static int numberOfControllers;
	Controller();
	Controller(int index); // 0 - 3
	Controller(Controller& controller);
	~Controller();

	void setIndex(int index); // 0 - 3

	// return 0 ~ 3 for empty, low, medium and high, -1 on error
	int getBatteryLevel();
	void printBatterLevel();

	bool isConnected();
	void printConnectionStatus();

	// return 0 ~ 3
	int getIndex();

	// Butons status, 1 for pressed, 0 for not pressed
	//===============================================
	// DPADS
	int buttonUp();
	int buttonDown();
	int buttonLeft();
	int buttonRight();

	int buttonStart();
	int buttonBack();
	int buttonL3(); // left thump
	int buttonR3(); // right thump
	int buttonLB(); // left shoulder
	int buttonRB(); // right shoulder
	int buttonA();
	int buttonB();
	int buttonX();
	int buttonY();
	//===============================================

	// Joysticsks, status is between -1000 and 1000
	//===============================================
	int stickLeftX();
	int stickLeftY();
	int stickRightX();
	int stickRightY();
	int getDeadZone(); // default deadzone is 10
	void setDeadZone(int dead_zone); // between 0 and 1000
	//===============================================

	// Triggers, status is between 0 - 255, with default deadzone 10
	//===============================================
	int LT();
	int RT();
	int getTriggerDeadZone();
	void setTriggerDeadZone(int trigger_dead_zone); // between 0 and 255
	//===============================================

	// Motors, status is between 0 - 100
	//===============================================
	void setMotorLeft(int percentage); // between 0 and 100
	void setMotorRight(int percentage); // between 0 and 100
	void shutMotorLeft();
	void shutMotorRight();
	void shutMotors();
	//===============================================

	void printNumberOfControllerStatus();

};