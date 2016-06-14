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

#include "Commands/ServoExtend.h"
#include "Commands/ServoRetract.h"

OI::OI():
Gamepad(0),
Intake(&Gamepad,1),
foldintakein(&Gamepad,2),
foldintakeout(&Gamepad,4),
LowGoal(&Gamepad,3),
HighGoal(&Gamepad,6),
straightdrive(&Gamepad,5)
//fireState(&left, 1),
//alignState(&left, 2),
//outrangeState(&left, 3)

{
	// Process operator interface input here.
	Intake.WhileHeld(new IntakeCommand());
	foldintakein.WhileHeld(new FoldIntakeIn());
	foldintakeout.WhileHeld(new FoldIntakeOut());
	LowGoal.WhenPressed(new Launch(.45));
	HighGoal.WhenPressed(new Launch(1));
	straightdrive.WhileHeld(new DriveStraight());

}

Joystick& OI::GetGamepad(){
	return Gamepad;
}
