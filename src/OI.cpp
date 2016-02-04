#include "OI.h"
#include "Commands/LowSpeedCommand.h"
#include "Commands/MedSpeedCommand.h"
#include "Commands/HighSpeedCommand.h"
#include "Commands/EmergencySpin.h"
#include "Commands/StopSpeed.h"
#include "Commands/IntakeCommand.h"
#include "Commands/ReverseSpeed.h"
#include "Commands/FoldIntakeOut.h"
#include "Commands/FoldIntakeIn.h"
#include "Commands/ReverseIntakeCommand.h"

OI::OI():
left(0),
right(5),
mechanism(1),
lowspeed(&mechanism, 3),
medspeed(&right, 11),
highspeed(&mechanism, 5),
stopspeed(&mechanism, 9),
reversespeed(&right, 10),
emergencyspin(&mechanism, 8),
intakeroller(&mechanism, 11),
foldintakeout(&mechanism, 6),
foldintakein(&mechanism,4),
emergencyfire(&mechanism,7)

{
	// Process operator interface input here.
	lowspeed.WhenPressed(new LowSpeedCommand());
	highspeed.WhenPressed(new HighSpeedCommand());
	stopspeed.WhileHeld(new StopSpeed());
	emergencyspin.WhileHeld(new EmergencySpin());
	intakeroller.WhileHeld(new IntakeCommand());
	foldintakeout.WhenPressed(new FoldIntakeOut());
	foldintakein.WhenPressed(new FoldIntakeIn());
	//reversespeed.WhileHeld(new ReverseSpeed());
	emergencyfire.WhileHeld(new ReverseIntakeCommand());

}
Joystick& OI::GetLeftStick() {
	return left;
}
Joystick& OI::GetRightStick() {
	return right;
}
Joystick& OI::GetMechanismStick() {
	return mechanism;
}
