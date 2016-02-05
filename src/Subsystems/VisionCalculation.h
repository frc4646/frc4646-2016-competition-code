#ifndef VisionCalculation_H
#define VisionCalculation_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class VisionCalculation: public Subsystem
{

public:
	VisionCalculation();
	~VisionCalculation();
	void InitDefaultCommand();
	int GetGoalDistanceInches();
	float RobotToGoalAngle();
	float GoalToRobotAngle();
private:
	std::shared_ptr<NetworkTable> networkTable;
};

#endif
