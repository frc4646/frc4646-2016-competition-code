#include "OI.h"
#include "Commands/RingerCommand.h"

OI::OI():
left(0),
right(1),
ringer(&left, 6)
{
	ringer.WhileHeld(new RingerCommand());
	// Process operator interface input here.
}
Joystick& OI::GetLeftStick() {
	return left;
}
Joystick& OI::GetRightStick() {
	return right;
}
