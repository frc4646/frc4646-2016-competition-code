#include "VisionCalculation.h"
#include "../RobotMap.h"

//Vision distance calculations
//https://wpilib.screenstepslive.com/s/4485

VisionCalculation::VisionCalculation() :
		Subsystem("VisionCalculation")
{
	networkTable = NetworkTable::GetTable("GRIP");
}

VisionCalculation::~VisionCalculation()
{
	networkTable = NULL;
}

void VisionCalculation::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

int VisionCalculation::GetGoalDistanceInches()
{
	double viewAngle = SmartDashboard::GetNumber("Autonomous distance", 22.5);
	double actualGoalHeightInches = SmartDashboard::GetNumber("actualGoalHeightInches", 14);
	double goalHeightPixels = networkTable->GetNumber("height", 100);

	//Insert distance equation here using the above numbers for calculation

	return 0;
}

float VisionCalculation::RobotToGoalAngle()
{
	return 0.0;
}

float VisionCalculation::GoalToRobotAngle()
{
	return 0.0;
}
