#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include "Commands/DriveUntilClose.h"

class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	DriveUntilClose *auton;
	LiveWindow *lw;
	double dist;
	double power;

	void RobotInit()
	{
		CommandBase::init();
		dist = SmartDashboard::GetNumber("Autonomous distance", 72);
		power = SmartDashboard::GetNumber("Autonomous power", -0.2);
//		autonomousCommand = new ExampleCommand();
		lw = LiveWindow::GetInstance();
		auton = new DriveUntilClose(power, dist);
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{

//		if (autonomousCommand != NULL)
//			autonomousCommand->Start();
		auton->Start();

	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
//		if (autonomousCommand != NULL)
//			autonomousCommand->Cancel();
		auton->Cancel();
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);

