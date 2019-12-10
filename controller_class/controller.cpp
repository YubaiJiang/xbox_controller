// controller_class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <xinput.h>

#include "controller.hpp"

using namespace std;

static int numberOfControllers;
	
Controller::Controller()
{
	XInputEnable(true);
	index = numberOfControllers < 4 ? numberOfControllers : 3;
	++numberOfControllers;
	printNumberOfControllerStatus();
}

Controller::Controller(int index) // 0 - 3
{
	XInputEnable(true);
	this->index = index;
	++numberOfControllers;
	printNumberOfControllerStatus();
}

Controller::Controller(Controller &controller)
{
	XInputEnable(true);
	++numberOfControllers;
	printNumberOfControllerStatus();
}
Controller::~Controller()
{
	--numberOfControllers;
	if (numberOfControllers == 0) XInputEnable(false);
}

void Controller::setIndex(int index) // 0 - 3
{
	this->index = index;
}

// return 0 ~ 3 for empty, low, medium and high, -1 on error
int Controller::getBatteryLevel()
{
	XINPUT_BATTERY_INFORMATION BatteryInformation;
	XInputGetBatteryInformation(index, BATTERY_DEVTYPE_GAMEPAD, &BatteryInformation);

	if (BatteryInformation.BatteryType == BATTERY_TYPE_DISCONNECTED) return -1;

	int battery;
	switch (BatteryInformation.BatteryLevel)
	{
	case BATTERY_LEVEL_EMPTY:
	{
		battery = 0;
		break;
	}
	case BATTERY_LEVEL_LOW:
	{
		battery = 1;
		break;
	}
	case BATTERY_LEVEL_MEDIUM:
	{
		battery = 2;
		break;
	}
	case BATTERY_LEVEL_FULL:
	{
		battery = 3;
		break;
	}
	default:
	{
		battery = -1;
		break;
	}
	}

	return battery;
}
void Controller::printBatterLevel()
{
	switch (getBatteryLevel())
	{
	case 0:
	{
		cout << "Battery level of controller " << index << ": empty " << endl;
		break;
	}
	case 1:
	{
		cout << "Battery level of controller " << index << ": low " << endl;
		break;
	}
	case 2:
	{
		cout << "Battery level of controller " << index << ": medium " << endl;
		break;
	}
	case 3:
	{
		cout << "Battery level of controller " << index << ": full " << endl;
		break;
	}
	default:
	{
		cout << "Battery level of controller " << index << " cannot be displayed " << endl;
		break;
	}
	}
}

bool Controller::isConnected()
{
	XINPUT_STATE State;
	if (XInputGetState(index, &State) == ERROR_DEVICE_NOT_CONNECTED) return false;
	return true;
}

void Controller::printConnectionStatus()
{
	if (isConnected()) cout << "Controller " << index << " is conected" << endl;
	else cout << "Controller " << index << " is not conected" << endl;
}

// return 0 ~ 3
int Controller::getIndex()
{
	return index;
}

// Butons status, 1 for pressed, 0 for not pressed
//===============================================
// DPADS
int Controller::buttonUp()
{
	XINPUT_STATE State;
	if (!(XInputGetState(index, &State) == ERROR_DEVICE_NOT_CONNECTED))
	{
		if (State.Gamepad.wButtons & 1) return 1;
	}
	return 0;
}
int Controller::buttonDown()
{
	XINPUT_STATE State;
	if (!(XInputGetState(index, &State) == ERROR_DEVICE_NOT_CONNECTED))
	{
		if (State.Gamepad.wButtons & 2) return 1;
	}
	return 0;
}
int Controller::buttonLeft()
{
	XINPUT_STATE State;
	if (!(XInputGetState(index, &State) == ERROR_DEVICE_NOT_CONNECTED))
	{
		if (State.Gamepad.wButtons & 4) return 1;
	}
	return 0;
}
int Controller::buttonRight()
{
	XINPUT_STATE State;
	if (!(XInputGetState(index, &State) == ERROR_DEVICE_NOT_CONNECTED))
	{
		if (State.Gamepad.wButtons & 8) return 1;
	}
	return 0;
}

int Controller::buttonStart()
{
	XINPUT_STATE State;
	if (!(XInputGetState(index, &State) == ERROR_DEVICE_NOT_CONNECTED))
	{
		if (State.Gamepad.wButtons & 0x10) return 1;
	}
	return 0;
}

int Controller::buttonBack()
{
	XINPUT_STATE State;
	if (!(XInputGetState(index, &State) == ERROR_DEVICE_NOT_CONNECTED))
	{
		if (State.Gamepad.wButtons & 0x20) return 1;
	}
	return 0;
}

int Controller::buttonL3() // left thump
{
	XINPUT_STATE State;
	if (!(XInputGetState(index, &State) == ERROR_DEVICE_NOT_CONNECTED))
	{
		if (State.Gamepad.wButtons & 0x40) return 1;
	}
	return 0;
}

int Controller::buttonR3() // right thump
{
	XINPUT_STATE State;
	if (!(XInputGetState(index, &State) == ERROR_DEVICE_NOT_CONNECTED))
	{
		if (State.Gamepad.wButtons & 0x80) return 1;
	}
	return 0;
}

int Controller::buttonLB() // left shoulder
{
	XINPUT_STATE State;
	if (!(XInputGetState(index, &State) == ERROR_DEVICE_NOT_CONNECTED))
	{
		if (State.Gamepad.wButtons & 0x100) return 1;
	}
	return 0;
}

int Controller::buttonRB() // right shoulder
{
	XINPUT_STATE State;
	if (!(XInputGetState(index, &State) == ERROR_DEVICE_NOT_CONNECTED))
	{
		if (State.Gamepad.wButtons & 0x200) return 1;
	}
	return 0;
}

int Controller::buttonA()
{
	XINPUT_STATE State;
	if (!(XInputGetState(index, &State) == ERROR_DEVICE_NOT_CONNECTED))
	{
		if (State.Gamepad.wButtons & 0x1000) return 1;
	}
	return 0;
}

int Controller::buttonB()
{
	XINPUT_STATE State;
	if (!(XInputGetState(index, &State) == ERROR_DEVICE_NOT_CONNECTED))
	{
		if (State.Gamepad.wButtons & 0x2000) return 1;
	}
	return 0;
}

int Controller::buttonX()
{
	XINPUT_STATE State;
	if (!(XInputGetState(index, &State) == ERROR_DEVICE_NOT_CONNECTED))
	{
		if (State.Gamepad.wButtons & 0x4000) return 1;
	}
	return 0;
}

int Controller::buttonY()
{
	XINPUT_STATE State;
	if (!(XInputGetState(index, &State) == ERROR_DEVICE_NOT_CONNECTED))
	{
		if (State.Gamepad.wButtons & 0x8000) return 1;
	}
	return 0;
}

//===============================================

// Joysticsks, status is between -1000 and 1000
//===============================================
int Controller::stickLeftX()
{
	int value = 0;
	XINPUT_STATE State;
	if (!(XInputGetState(index, &State) == ERROR_DEVICE_NOT_CONNECTED))
	{
		value = (State.Gamepad.sThumbLX) * 1000 / 32767;
	}
	value = (value > dead_zone || value < -dead_zone) ? value : 0;
	return value;
}

int Controller::stickLeftY()
{
	int value = 0;
	XINPUT_STATE State;
	if (!(XInputGetState(index, &State) == ERROR_DEVICE_NOT_CONNECTED))
	{
		value = (State.Gamepad.sThumbLY) * 1000 / 32767;
	}
	value = (value > dead_zone || value < -dead_zone) ? value : 0;
	return value;
}

int Controller::stickRightX()
{
	int value = 0;
	XINPUT_STATE State;
	if (!(XInputGetState(index, &State) == ERROR_DEVICE_NOT_CONNECTED))
	{
		value = (State.Gamepad.sThumbRX) * 1000 / 32767;
	}
	value = (value > dead_zone || value < -dead_zone) ? value : 0;
	return value;
}

int Controller::stickRightY()
{
	int value = 0;
	XINPUT_STATE State;
	if (!(XInputGetState(index, &State) == ERROR_DEVICE_NOT_CONNECTED))
	{
		value = (State.Gamepad.sThumbRY) * 1000 / 32767;
	}
	value = (value > dead_zone || value < -dead_zone) ? value : 0;
	return value;
}

int Controller::getDeadZone() // default deadzone is 10
{
	return dead_zone;
}

void Controller::setDeadZone(int dead_zone) // between 0 and 1000
{
	this->dead_zone = dead_zone;
}
//===============================================

// Triggers, status is between 0 - 255, with default deadzone 10
//===============================================
int Controller::LT()
{
	int value = 0;
	XINPUT_STATE State;
	if (!(XInputGetState(index, &State) == ERROR_DEVICE_NOT_CONNECTED))
	{
		value = State.Gamepad.bLeftTrigger;
	}
	value = (value > trigger_dead_zone) ? value : 0;
	return value;
}

int Controller::RT()
{
	int value = 0;
	XINPUT_STATE State;
	if (!(XInputGetState(index, &State) == ERROR_DEVICE_NOT_CONNECTED))
	{
		value = State.Gamepad.bRightTrigger;
	}
	value = (value > trigger_dead_zone) ? value : 0;
	return value;
}

int Controller::getTriggerDeadZone()
{
	return trigger_dead_zone;
}

void Controller::setTriggerDeadZone(int trigger_dead_zone) // between 0 and 255
{
	this->trigger_dead_zone = trigger_dead_zone;
}

//===============================================

// Motors, status is between 0 - 100
//===============================================
void Controller::setMotorLeft(int percentage) // between 0 and 100
{
	int value = percentage * 65535 / 100;
	XINPUT_VIBRATION Vibration;
	Vibration.wLeftMotorSpeed = value;
	XInputSetState(index, &Vibration);
}

void Controller::setMotorRight(int percentage) // between 0 and 100
{
	int value = percentage * 65535 / 100;
	XINPUT_VIBRATION Vibration;
	Vibration.wRightMotorSpeed = value;
	XInputSetState(index, &Vibration);
}

void Controller::shutMotorLeft()
{
	setMotorLeft(0);
}

void Controller::shutMotorRight()
{
	setMotorRight(0);
}

void Controller::shutMotors()
{
	shutMotorLeft();
	shutMotorRight();
}
//===============================================

void Controller::printNumberOfControllerStatus()
{
	if (numberOfControllers > 4) cout << "Too many controllers" << endl;
}


int Controller::numberOfControllers = 0;