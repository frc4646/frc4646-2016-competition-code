#ifndef RobotAngleDistance_H
#define RobotAngleDistance_H

#include "../CommandBase.h"
#include "WPILib.h"

class RobotAngleDistance: public CommandBase
{
public:
	RobotAngleDistance();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void isInRange();
private:
	int confidence;
	double turning;
	double robotTurn;
	int heightPixels;
};

#endif

