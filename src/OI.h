#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
public:
	OI();
	Joystick& GetLeftStick();
	Joystick& GetRightStick();
private:
	Joystick left;
	Joystick right;
	JoystickButton ringer;
	JoystickButton lowspeed;
	JoystickButton medspeed;
	JoystickButton highspeed;
	JoystickButton stopspeed;
	JoystickButton reversespeed;
};

#endif
