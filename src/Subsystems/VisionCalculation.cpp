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
	//SetDefaultCommand(new RobotGoalDistance());
}

float VisionCalculation::GetGoalDistance()
{
//	double viewAngle = SmartDashboard::GetNumber("Autonomous distance", 22.5);
//	double actualGoalHeightInches = SmartDashboard::GetNumber("actualGoalHeightInches", 14);
//	double goalHeightPixels = networkTable->GetNumber("height", 100);

	//Insert distance equation here using the above numbers for calculation
	distVals = networkTable->GetNumberArray("centerY", llvm::ArrayRef<double>());
	if (!distVals.empty())
	{
		goalHeight = (float)distVals[0] - 147;
	}
	else
	{
		goalHeight = 0;
	}

	return goalHeight;
}

float VisionCalculation::RobotToGoalAngle()
{
	const int desiredPosition = 257;
	xVals = networkTable->GetNumberArray("centerX", llvm::ArrayRef<double>());
	if (!xVals.empty())
	{
		goalXPos = (float)xVals[0];
	}
	else
	{
		goalXPos = desiredPosition;
	}
	return goalXPos - desiredPosition;
}

float VisionCalculation::GoalToRobotAngle()
{
	//TODO: Possible calculate the actual angle here. This will include 3D pose estimation from a 2D image. Difficulty - moderate.
	//      Alternative is to just check the height of the left side of the rectangular goal vs the right side and if the left is larger we need to drive right and vice versa.
	return 0.0;
}

void VisionCalculation::SendSD() {
	SmartDashboard::PutNumber("RobotToGoalDistance", GetGoalDistance());
	SmartDashboard::PutNumber("RobotToGoalAngle", RobotToGoalAngle());
}
