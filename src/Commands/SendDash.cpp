#include "SendDash.h"
#include "Subsystems/SendSmartDash.h"
#include "Subsystems/DropDrive.h"
#include "Subsystems/IntakeArms.h"
#include "Subsystems/IntakeRoller.h"
#include "Subsystems/LauncherPIDSubsystem.h"
#include "Subsystems/SlavedLauncherPID.h"
#include "Subsystems/UltrasonicSensor.h"
#include "Subsystems/VisionCalculation.h"

SendDash::SendDash()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void SendDash::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void SendDash::Execute()
{
	dropdrive->SendSD();
	intakearms->SendSD();
	intakeroller->SendSD();
	ultrasonicsensor->SendSD();
	visioncalculation->SendSD();
	slavelauncherpid->SendSD();
	//	leftlauncherpid->SendSD();
//	rightlauncherpid->SendSD();

}

// Make this return true when this Command no longer needs to run execute()
bool SendDash::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SendDash::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SendDash::Interrupted()
{

}
