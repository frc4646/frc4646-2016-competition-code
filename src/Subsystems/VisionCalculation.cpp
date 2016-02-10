#include "VisionCalculation.h"
#include "../RobotMap.h"
#include "Commands/RobotGoalAngle.h"
#include "Commands/RobotGoalDistance.h"

//Vision distance calculations
//https://wpilib.screenstepslive.com/s/4485

VisionCalculation::VisionCalculation() :
		Subsystem("VisionCalculation"),
		goalXPos(0),
		goalHeight(0)
{
	networkTable = NetworkTable::GetTable("GRIP/Contours");
}

VisionCalculation::~VisionCalculation()
{
	networkTable = NULL;
}

void VisionCalculation::InitDefaultCommand()
{
	SetDefaultCommand(new RobotGoalDistance());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

float VisionCalculation::GetGoalDistance()
{
//	double viewAngle = SmartDashboard::GetNumber("Autonomous distance", 22.5);
//	double actualGoalHeightInches = SmartDashboard::GetNumber("actualGoalHeightInches", 14);
//	double goalHeightPixels = networkTable->GetNumber("height", 100);

	//Insert distance equation here using the above numbers for calculation
	distVals = networkTable->GetNumberArray("height", llvm::ArrayRef<double>());
	if (!distVals.empty())
	{
		goalHeight = (float)distVals[0];
	}
	else
	{
		goalHeight = 0;
	}

	return goalHeight;
}

float VisionCalculation::RobotToGoalAngle()
{
	xVals = networkTable->GetNumberArray("centerX", llvm::ArrayRef<double>());
	if (!xVals.empty())
	{
		goalXPos = (float)xVals[0];
	}
	else
	{
		goalXPos = 320;
	}
	return goalXPos - 320;
//	return 0.0;
}

float VisionCalculation::GoalToRobotAngle()
{
	return 0.0;
}