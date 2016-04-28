#ifndef SlavedLauncherPID_H
#define SlavedLauncherPID_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "PinEnums.h"


class SlavedLauncherPID: public PIDSubsystem
{
public:
public:
	SlavedLauncherPID(std::string side, MotorPin motorPin, MotorPin motorPin2, DIOPin encoderPin);
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	void Reverse();
	void Manual();
	void SetManual(double power);
	void SendSD();

private:
	Victor pidMotor;
	Victor pidMotor2;
	Counter pidEncoder;
	double reverseMultiplier;
};

#endif
