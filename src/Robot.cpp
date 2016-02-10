#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include "Commands/DriveUntilClose.h"
#include "Commands/DriveForTime.h"
#include "Commands/FiringAuto.h"
#include "Commands/CrossDefenseAuto.h"
#include "Commands/SpyAuto.h"

class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	SendableChooser *chooser;
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
		chooser = new SendableChooser();
		chooser->AddDefault("Do Nothing", new DriveForTime(0,0));
		chooser->AddObject("Firing Auto", new FiringAuto());
		chooser->AddObject("Crossing Auto", new CrossDefenseAuto());
		chooser->AddObject("Spy Bot Auto", new SpyAuto());

	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		autonomousCommand = (Command*) chooser->GetSelected();
				if (autonomousCommand != NULL)
					autonomousCommand->Start();
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
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();
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

