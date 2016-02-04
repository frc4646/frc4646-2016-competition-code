#ifndef PIDTest_H
#define PIDTest_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"

class PIDTest: public PIDSubsystem
{
public:
	PIDTest();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
private:
	Victor pidMotor;
	Counter pidEncoder;
};

#endif
