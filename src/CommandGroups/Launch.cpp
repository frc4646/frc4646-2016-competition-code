#include <CommandGroups/Launch.h>
#include <Commands/ServoExtend.h>
#include <Commands/ServoRetract.h>
#include <Commands/SpinUp.h>
#include <Commands/StopSpeed.h>

Launch::Launch(double speed)
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
//	AddParallel(new FoldIntakeIn(), 1.5);
	AddSequential(new SpinUp(speed), 1.5);
//	AddSequential(new PrepLaunch(speed), 1.5);
	//AddSequential(new ReverseIntakeCommand(),1);
	AddSequential(new ServoExtend(), 0.5);
//	AddSequential(new WaitCommand(1));
	AddSequential(new StopSpeed());
	AddSequential(new ServoRetract(), 0.5);
}
