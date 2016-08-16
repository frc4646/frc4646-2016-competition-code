#include "RobotGoalAngle.h"
#include "Subsystems/VisionCalculation.h"
#include "Subsystems/DropDrive.h"
#include <algorithm>

RobotGoalAngle::RobotGoalAngle():
turning(0),
robotTurn(0),
confidence(0),
po(),
ps(visioncalculation),
pc(0.35,0,0,&ps,&po)
{
	SmartDashboard::PutData("RobotGoalAnglePID", &pc);
	Requires(visioncalculation);
	Requires(dropdrive);
}

// Called just before this Command runs the first time
void RobotGoalAngle::Initialize()
{
	pc.Reset();
	pc.SetSetpoint(0.0);
	pc.SetOutputRange(-0.3, 0.3);
	pc.Enable();
}

// Called repeatedly when this Command is scheduled to run
void RobotGoalAngle::Execute()//Optimal middle x ~307 with first shooter modification
{
//	const double turn_power = 0.18;

	robotTurn = pc.Get();
	SmartDashboard::PutNumber("Turn Power", robotTurn);

	float battery = DriverStation::GetInstance().GetBatteryVoltage();
//	float deadband = 0.08;

	//Battery VOltage method
	//13V, 0.07 12.3V,0.08 Linear Regression
	const float deadband = .276349 - .015873 * battery;
	//p of 0.35

	//PID Method
	//float deadband= 0.07;
	//P:0.3 I:0.01 D:0.05
	//Slower
	SmartDashboard::PutNumber("Battery", battery);
	SmartDashboard::PutNumber("Deadband", deadband);

	if(robotTurn > 0)
	{
		robotTurn += deadband;
	}
	if(robotTurn < 0)
	{
		robotTurn -= deadband;
	}

/**	if (turning > 0.01)
	{
		robotTurn = turn_power;
	}
	else if (turning < -0.05)
	{
		robotTurn = -turn_power;
	}
	else
	{
		robotTurn = 0;
	}
**/
	dropdrive->SetDrive(robotTurn, 1);
	SmartDashboard::PutNumber("Goal X Position", robotTurn);
	SmartDashboard::PutBoolean("LinedUp",confidence > 3);
}

// Make this return true when this Command no longer needs to run execute()
bool RobotGoalAngle::IsFinished()
{
	return false;
//	isInRange();
//	return confidence > 3;
}

// Called once after isFinished returns true
void RobotGoalAngle::End()
{
	dropdrive->SetDrive(0,0);
	pc.Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RobotGoalAngle::Interrupted()
{
	End();
}

void RobotGoalAngle::isInRange() {
	if (turning < 0.12 && turning > -0.12)
	{
		confidence++;
	}
	else
	{
		confidence = 0;
	}
}
