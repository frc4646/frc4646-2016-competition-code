#include "OI.h"
#include "Commands/EmergencySpin.h"
#include "Commands/StopSpeed.h"
#include "Commands/IntakeCommand.h"
#include "Commands/ReverseSpeed.h"
#include "Commands/FoldIntakeOut.h"
#include "Commands/FoldIntakeIn.h"
#include "Commands/ReverseIntakeCommand.h"
#include "Commands/SpinUp.h"
#include "CommandGroups/Launch.h"
#include "Commands/SendI2C.h"
#include "Commands/ForceFold.h"
#include "Commands/RobotGoalAngle.h"
#include "Commands/RobotGoalDistance.h"
#include "Commands/DriveStraight.h"
#include "Commands/FlashlightOnCommand.h"
#include "Commands/ServoExtend.h"
#include "Commands/ServoRetract.h"

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
launchlow(&mechanism,2),
assistTurn(&left, 2),
assistDistance(&right, 2),
driverFire(&right, 1),
driveStraight(&left, 1),
light(&mechanism, 12)
//fireState(&left, 1),
//alignState(&left, 2),
//outrangeState(&left, 3)

{
	// Process operator interface input here.
//	lowspeed.WhileHeld(new SpinUp(0.4));
//	highspeed.WhileHeld(new SpinUp(1));
	lowspeed.WhileHeld(new ServoRetract());
	highspeed.WhileHeld(new ServoExtend());
	stopspeed.WhileHeld(new StopSpeed());
	emergencyspin.WhileHeld(new EmergencySpin());
	intakeroller.WhileHeld(new IntakeCommand());
	foldintakeout.WhileHeld(new FoldIntakeOut());
	foldintakein.WhileHeld(new FoldIntakeIn());
	emergencyraise.WhileHeld(new ForceFold());
	//reversespeed.WhileHeld(new ReverseSpeed());
	emergencyfire.WhileHeld(new ReverseIntakeCommand());
	launchhigh.WhenPressed(new Launch(1));
	launchlow.WhenPressed(new Launch(0.45));
	assistTurn.WhileHeld(new RobotGoalAngle());
	assistDistance.WhileHeld(new RobotGoalDistance());
	driverFire.WhenPressed(new Launch(1));
	driveStraight.WhileHeld(new DriveStraight());
	light.WhileHeld(new FlashlightOnCommand());
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
