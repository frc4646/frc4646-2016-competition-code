#ifndef RobotGoalAngle_H
#define RobotGoalAngle_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Subsystems/NullPIDOutput.h"
#include "Subsystems/RobotAnglePIDSource.h"

class RobotGoalAngle: public CommandBase
{
public:
	RobotGoalAngle();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void isInRange();
private:
	float turning;
	float robotTurn;
	int confidence;
	NullPIDOutput po;
	RobotAnglePIDSource ps;
	PIDController pc;
};

#endif
