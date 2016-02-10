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
	float GetGoalDistance();
	float RobotToGoalAngle();
	float GoalToRobotAngle();
private:
	std::shared_ptr<NetworkTable> networkTable;
	float goalXPos;
	float goalHeight;
	std::vector<double> xVals;
	std::vector<double> distVals;
};

#endif

