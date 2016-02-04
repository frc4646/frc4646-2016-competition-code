#include "VisionCalculation.h"
#include "../RobotMap.h"

VisionCalculation::VisionCalculation() :
		Subsystem("VisionCalculation")
{

}

void VisionCalculation::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

int VisionCalculation::GetGoalDistanceInches()
{
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
