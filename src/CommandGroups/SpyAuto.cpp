#include <CommandGroups/Launch.h>
#include <CommandGroups/SpyAuto.h>
#include <Commands/DriveUntilFar.h>
#include <Commands/RobotGoalAngle.h>
#include <Commands/RobotGoalDistance.h>

SpyAuto::SpyAuto()
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
	AddSequential(new DriveUntilFar(-.5,72));
	AddSequential(new RobotGoalAngle());
	AddSequential(new RobotGoalDistance());
	AddSequential(new Launch(1));
}
