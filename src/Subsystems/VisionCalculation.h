#ifndef VisionCalculation_H
#define VisionCalculation_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class VisionCalculation: public Subsystem
{

public:
	VisionCalculation();
	void InitDefaultCommand();
	int GetGoalDistanceInches();
	float RobotToGoalAngle();
	float GoalToRobotAngle();
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
};

#endif
