#include "OI.h"
#include "Commands/RingerCommand.h"

OI::OI():
stick(0),
ringer(&stick, 1)
{
	ringer.WhileHeld(new RingerCommand());
	// Process operator interface input here.
}
Joystick& OI::GetStick() {
	return stick;
}
