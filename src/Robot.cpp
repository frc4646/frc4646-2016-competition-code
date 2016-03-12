#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include "Commands/DriveUntilClose.h"
#include "Commands/DriveForTime.h"
#include "CommandGroups/FiringAuto.h"
#include "CommandGroups/CrossDefenseAuto.h"
#include "CommandGroups/SpyAuto.h"
#include "Commands/SendI2C.h"
#include "Commands/RobotGoalDistance.h"
#include "Commands/RobotGoalAngle.h"
#include "CommandGroups/FiringAuto.h"
#include "Subsystems/LEDSystem.h"
#include "Subsystems/DropDrive.h"

class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	SendableChooser *chooser;
	LiveWindow *lw;
	SendI2C *autonomous;
	SendI2C *teleop;
	SendI2C *disable;
	double dist;
	double power;

	void RobotInit()
	{
		CommandBase::init();
		dist = SmartDashboard::GetNumber("Autonomous distance", 72);
		power = SmartDashboard::GetNumber("Autonomous power", -0.2);
		lw = LiveWindow::GetInstance();
		chooser = new SendableChooser();
		chooser->AddDefault("Do Nothing", new DriveForTime(0,0));
		chooser->AddObject("Low Bar Auto", new FiringAuto());
		chooser->AddObject("Defense 2 Auto", new CrossDefenseAuto(45));
		chooser->AddObject("Defense 3 Auto", new CrossDefenseAuto(0));
		chooser->AddObject("Spy Bot Auto", new SpyAuto());
		disable = new SendI2C(LEDSystem::LEDstate::disabled);
		disable->Initialize();
		SmartDashboard::PutData("Autonomous mode", chooser);
//		CameraServer::GetInstance()->SetQuality(50);
//		//the camera name (ex "cam0") can be found through the roborio web interface
//		CameraServer::GetInstance()->StartAutomaticCapture("cam1");
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
		disable->Initialize();
	}

	void AutonomousInit()
	{
		autonomous = new SendI2C(LEDSystem::LEDstate::autonomous);
		autonomous->Initialize();
		autonomousCommand = (Command*) chooser->GetSelected();
//		autonomousCommand = (new FiringAuto());
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
		teleop = new SendI2C(LEDSystem::LEDstate::teleop);
		teleop->Initialize();
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

