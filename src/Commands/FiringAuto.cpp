#include "FiringAuto.h"
#include "DriveForTime.h"
#include "DriveUntilClose.h"
#include "RobotGoalAngle.h"
#include "RobotGoalDistance.h"
#include "TurnForAngle.h"
#include "Launch.h"
#include "EmergencySpin.h"
#include "SpinUp.h"
#include "FoldIntakeIn.h"
#include "FoldIntakeOut.h"
#include "ResetGyro.h"

FiringAuto::FiringAuto()
{
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.'

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
	AddSequential(new FoldIntakeOut(), 1.5);
	AddSequential(new TurnForAngle(.3, 0));
	AddSequential(new DriveForTime(.3,0),4.5);
	AddSequential(new FoldIntakeIn(), 1.5);
	AddSequential(new DriveUntilClose(.4,84));
	AddSequential(new TurnForAngle(.3, 60));
	AddSequential(new RobotGoalAngle(),2);
	AddSequential(new RobotGoalDistance(),2);
	AddSequential(new RobotGoalAngle(),2);
//	AddSequential(new SpinUp(.8), 2);
	AddSequential(new Launch(1));

}
