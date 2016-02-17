#ifndef DriveForTime_H
#define DriveForTime_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveForTime: public CommandBase
{
public:
	DriveForTime(double power, double curve);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double drivePower;
	double driveCurve;
	double gyroCurve;
};

#endif
