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
	double GetIntakeSpeed();
private:
	Joystick left;
	Joystick right;
	Joystick mechanism;
	Joystick lightswitch;
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
	JoystickButton emergencyraise;
	JoystickButton launchlow;
	JoystickButton assistTurn;
	JoystickButton assistDistance;
	JoystickButton driverFire;
	JoystickButton driveStraight;
	JoystickButton light;
	//	JoystickButton fireState;
//	JoystickButton alignState;
//	JoystickButton outrangeState;
};

#endif
