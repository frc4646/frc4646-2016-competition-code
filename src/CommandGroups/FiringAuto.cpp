#include "FiringAuto.h"
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
#include "Commands/AutoRollerIn.h"
#include "Commands/IntakeCommand.h"

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
	AddSequential(new FoldIntakeOut(), 1);
	AddSequential(new TurnForAngle(.3, 0), .5);
	AddSequential(new DriveForTime(.45,0),3.75);
	AddSequential(new AutoRollerIn(), 1.5);
	AddSequential(new IntakeCommand(), .1);
	AddSequential(new DriveUntilClose(.4,94));
	AddSequential(new TurnForAngle(.3, 60));
	AddSequential(new DriveForTime(.4, 0), 1.2);
	AddSequential(new RobotGoalAngle(),2);
	AddSequential(new RobotGoalDistance(),2);
	AddSequential(new RobotGoalAngle(),2);
//	AddSequential(new SpinUp(.8), 2);
	AddSequential(new Launch(.9));

}
