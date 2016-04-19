#include <CommandGroups/CrossDefenseAuto.h>
#include <CommandGroups/Launch.h>
#include <Commands/DriveForTime.h>
#include <Commands/DriveUntilClose.h>
#include <Commands/ResetGyro.h>
#include <Commands/RobotGoalAngle.h>
#include <Commands/RobotGoalDistance.h>
#include <Commands/TurnForAngle.h>

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
	AddSequential(new ResetGyro());
	AddSequential(new DriveForTime(.8,0),2);
	AddSequential(new TurnForAngle(.4, 0), 2);
	AddSequential(new DriveForTime(.4, 0), .5);
	AddSequential(new DriveUntilClose(.4,84));
	AddSequential(new TurnForAngle(.3, angle),1);
	AddSequential(new RobotGoalAngle(),2);
	AddSequential(new RobotGoalDistance(),2);
	AddSequential(new RobotGoalAngle(),1);
//	AddSequential(new SpinUp(.8), 2);
	AddSequential(new Launch(1));
}
