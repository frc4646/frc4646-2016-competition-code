#include "OI.h"
#include "Commands/EmergencySpin.h"
#include "Commands/StopSpeed.h"
#include "Commands/IntakeCommand.h"
#include "Commands/ReverseSpeed.h"
#include "Commands/FoldIntakeOut.h"
#include "Commands/FoldIntakeIn.h"
#include "Commands/ReverseIntakeCommand.h"
#include "Commands/SpinUp.h"
#include "Commands/Launch.h"
#include "Commands/SendI2C.h"

OI::OI():
left(0),
right(1),
mechanism(2),
lowspeed(&mechanism, 3),
highspeed(&mechanism, 5),
stopspeed(&mechanism, 9),
reversespeed(&right, 10),
emergencyspin(&mechanism, 8),
intakeroller(&mechanism, 11),
foldintakeout(&mechanism, 6),
foldintakein(&mechanism,4),
emergencyfire(&mechanism,7),
launchhigh(&mechanism,1),
launchlow(&mechanism,2),
fireState(&left, 1),
alignState(&left, 2),
outrangeState(&left, 3)

{
	// Process operator interface input here.
	lowspeed.WhenPressed(new SpinUp(0.4));
	highspeed.WhenPressed(new SpinUp(1));
	stopspeed.WhileHeld(new StopSpeed());
	emergencyspin.WhileHeld(new EmergencySpin());
	intakeroller.WhileHeld(new IntakeCommand());
	foldintakeout.WhenPressed(new FoldIntakeOut());
	foldintakein.WhenPressed(new FoldIntakeIn());
	//reversespeed.WhileHeld(new ReverseSpeed());
	emergencyfire.WhileHeld(new ReverseIntakeCommand());
	launchhigh.WhenPressed(new Launch(1));
	launchlow.WhenPressed(new Launch(0.4));
	fireState.WhenPressed(new SendI2C(LEDSystem::LEDstate::fire));
	alignState.WhenPressed(new SendI2C(LEDSystem::LEDstate::aligned));
	outrangeState.WhenPressed(new SendI2C(LEDSystem::LEDstate::outrange));

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
