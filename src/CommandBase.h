#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>
#include "Commands/Command.h"

#include "WPILib.h"

class OI;
class DropDrive;
class UltrasonicSensor;
class LauncherPIDSubsystem;
class SlavedLauncherPID;
class IntakeRoller;
class IntakeArms;
class VisionCalculation;
class LEDSystem;
class SendSmartDash;
class FiringServo;
class FlashlightRelay;
//class WriteInputsCommand;

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
	CommandBase(char const *name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static OI *oi;
	static DropDrive *dropdrive;
	static UltrasonicSensor *ultrasonicsensor;
	static Counter* LeftPidCounter;
	static Counter* RightPidCounter;
	static SpeedController* launcherController;
	static SpeedController* RightLauncherController;
//	static SlavedLauncherPID *slavelauncherpid;
	static LauncherPIDSubsystem *leftlauncherpid;
	static LauncherPIDSubsystem *rightlauncherpid;
	static IntakeRoller *intakeroller;
	static IntakeArms *intakearms;
	static VisionCalculation *visioncalculation;
	static LEDSystem *ledsystem;
	static SendSmartDash *sendsmartdash;
	static FiringServo *firingservo;
	static FlashlightRelay *flashlightrelay;
	//static WriteInputsCommand *writeinputs;
};


#endif
