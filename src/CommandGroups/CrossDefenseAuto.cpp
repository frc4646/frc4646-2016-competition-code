#include "CrossDefenseAuto.h"
#include "Commands/DriveForTime.h"
#include "Commands/DriveUntilClose.h"
#include "Commands/RobotGoalAngle.h"
#include "Commands/RobotGoalDistance.h"
#include "Commands/TurnForAngle.h"
#include "CommandGroups/Launch.h"
#include "Commands/EmergencySpin.h"
#include "Commands/SpinUp.h"
#include "Commands/FoldIntakeIn.h"
#include "Commands/FoldIntakeOut.h"
#include "Commands/ResetGyro.h"

CrossDefenseAuto::CrossDefenseAuto(double angle)
{
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
	AddParallel(new DriveForTime(.8,0),3);
	AddSequential(new DriveUntilClose(.5,72));
	AddSequential(new TurnForAngle(.3, angle));
	AddSequential(new RobotGoalAngle(),2);
	AddSequential(new RobotGoalDistance(),2);
	AddSequential(new RobotGoalAngle(),2);
//	AddSequential(new SpinUp(.8), 2);
	AddSequential(new Launch(1));
}
