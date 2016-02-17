#include "DriveForTime.h"
#include "Subsystems/DropDrive.h"

DriveForTime::DriveForTime(double power, double curve):
drivePower(power),
driveCurve(curve)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(dropdrive);
}

// Called just before this Command runs the first time
void DriveForTime::Initialize()
{
	dropdrive->ResetGyro();
}

// Called repeatedly when this Command is scheduled to run
void DriveForTime::Execute()
{
	gyroCurve = dropdrive->GetHeading()/90.0;
	dropdrive->SetDrive(drivePower, driveCurve - gyroCurve);
	SmartDashboard::PutNumber("Gyro Heading", dropdrive->GetHeading());
}

// Make this return true when this Command no longer needs to run execute()
bool DriveForTime::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveForTime::End()
{
	dropdrive->SetDrive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForTime::Interrupted()
{

}
