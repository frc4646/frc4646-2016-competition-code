#include "OI.h"

OI::OI():
stick(0),
ringer(0)
{

	// Process operator interface input here.
}
Joystick& OI::GetStick() {
	return stick;
}
