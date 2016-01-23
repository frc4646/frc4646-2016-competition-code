#include "OI.h"
#include "Commands/RingerCommand.h"
#include "Commands/LowSpeedCommand.h"
#include "Commands/MedSpeedCommand.h"
#include "Commands/HighSpeedCommand.h"
#include "Commands/StopSpeed.h"
#include "Commands/ReverseSpeed.h"

OI::OI():
left(0),
right(1),
ringer(&left, 6),
lowspeed(&right, 6),
medspeed(&right, 11),
highspeed(&right, 8),
stopspeed(&right, 9),
reversespeed(&right, 10)
{
	ringer.WhileHeld(new RingerCommand());
	// Process operator interface input here.
	lowspeed.WhenPressed(new LowSpeedCommand());
	medspeed.WhenPressed(new MedSpeedCommand());
	highspeed.WhenPressed(new HighSpeedCommand());
	stopspeed.WhileHeld(new StopSpeed());
	reversespeed.WhileHeld(new ReverseSpeed());

}
Joystick& OI::GetLeftStick() {
	return left;
}
Joystick& OI::GetRightStick() {
	return right;
}
