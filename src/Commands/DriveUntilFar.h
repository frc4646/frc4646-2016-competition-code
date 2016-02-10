#ifndef DriveUntilFar_H
#define DriveUntilFar_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveUntilFar: public CommandBase
{
public:
	DriveUntilFar(double power, double distance);
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
