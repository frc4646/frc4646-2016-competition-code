#ifndef DriveUntilClose_H
#define DriveUntilClose_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveUntilClose: public CommandBase
{
public:
	DriveUntilClose(double power, double distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double robotPower;
	double sensorDistance;
};

#endif
