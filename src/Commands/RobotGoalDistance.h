#ifndef RobotGoalDistance_H
#define RobotGoalDistance_H

#include "../CommandBase.h"
#include "WPILib.h"

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
	int heightPixels;
};

#endif
