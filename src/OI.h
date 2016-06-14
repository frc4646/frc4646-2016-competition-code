#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
public:
	OI();
	Joystick& GetGamepad();
private:
	Joystick Gamepad;
	JoystickButton Intake;
	JoystickButton foldintakein;
	JoystickButton foldintakeout;
	JoystickButton LowGoal;
	JoystickButton HighGoal;
	JoystickButton straightdrive;
};

#endif
