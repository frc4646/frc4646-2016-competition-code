#ifndef RobotGoalDistance_H
#define RobotGoalDistance_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Subsystems/NullPIDOutput.h"
#include "Subsystems/RobotDistancePIDSource.h"

class RobotGoalDistance: public CommandBase
{
public:
	RobotGoalDistance();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	NullPIDOutput po;
	RobotDistancePIDSource ps;
	PIDController pc;
	float distancePower;
};

#endif
