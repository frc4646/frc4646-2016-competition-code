#include "FiringAuto.h"
#include "DriveForTime.h"
#include "DriveUntilClose.h"
#include "RobotGoalAngle.h"
#include "RobotGoalDistance.h"
#include "Launch.h"

FiringAuto::FiringAuto()
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
	AddParallel(new DriveForTime(.5,0),3);
	AddSequential(new DriveUntilClose(.5,72));
	AddSequential(new RobotGoalAngle());
	AddSequential(new RobotGoalDistance());
	AddSequential(new Launch(1));

}
