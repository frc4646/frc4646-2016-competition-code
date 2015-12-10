#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
public:
	OI();
	Joystick& GetStick();
private:
	Joystick stick;
	JoystickButton ringer;
};

#endif
