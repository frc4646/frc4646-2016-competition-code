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
#include "Commands/ForceFold.h"

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
emergencyraise(&mechanism,10),
launchlow(&mechanism,2)
//fireState(&left, 1),
//alignState(&left, 2),
//outrangeState(&left, 3)

{
	// Process operator interface input here.
	lowspeed.WhenPressed(new SpinUp(0.4));
	highspeed.WhenPressed(new SpinUp(1));
	stopspeed.WhileHeld(new StopSpeed());
	emergencyspin.WhileHeld(new EmergencySpin());
	intakeroller.WhileHeld(new IntakeCommand());
	foldintakeout.WhileHeld(new FoldIntakeOut());
	foldintakein.WhileHeld(new FoldIntakeIn());
	emergencyraise.WhileHeld(new ForceFold());
	//reversespeed.WhileHeld(new ReverseSpeed());
	emergencyfire.WhileHeld(new ReverseIntakeCommand());
	launchhigh.WhenPressed(new Launch(1));
	launchlow.WhenPressed(new Launch(0.4));
//	fireState.WhenPressed(new SendI2C(LEDSystem::LEDstate::autonomous));
//	alignState.WhenPressed(new SendI2C(LEDSystem::LEDstate::teleop));
//	outrangeState.WhenPressed(new SendI2C(LEDSystem::LEDstate::disabled));



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

double OI::GetIntakeSpeed() {
	return (mechanism.GetRawAxis(3)*-0.4) + 0.6;
}
