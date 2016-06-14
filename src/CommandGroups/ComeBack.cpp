#include "ComeBack.h"
#include "../Commands/ResetGyro.h"
#include "../Commands/DriveForTime.h"
#include "../Commands/TurnForAngle.h"
#include "Launch.h"

ComeBack::ComeBack()
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
	AddSequential(new Launch(.1),1);
	AddSequential(new DriveForTime(-.8,0),1.5);
}
