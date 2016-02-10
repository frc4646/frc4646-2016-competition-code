#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
public:
	OI();
	Joystick& GetLeftStick();
	Joystick& GetRightStick();
	Joystick& GetMechanismStick();
private:
	Joystick left;
	Joystick right;
	Joystick mechanism;
	JoystickButton lowspeed;
	JoystickButton highspeed;
	JoystickButton stopspeed;
	JoystickButton reversespeed;
	JoystickButton emergencyspin;
	JoystickButton intakeroller;
	JoystickButton foldintakeout;
	JoystickButton foldintakein;
	JoystickButton emergencyfire;
	JoystickButton launchhigh;
	JoystickButton launchlow;
	JoystickButton fireState;
	JoystickButton alignState;
	JoystickButton outrangeState;
};

#endif
