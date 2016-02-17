#ifndef TurnForAngle_H
#define TurnForAngle_H

#include "../CommandBase.h"
#include "WPILib.h"

class TurnForAngle: public CommandBase
{
public:
	TurnForAngle(double robotPower, double robotAngle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double power;
	double angle;
	double error;
	double drive;
	double initDif;
};

#endif
