#ifndef LauncherPIDSubsystem_H
#define LauncherPIDSubsystem_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "PinEnums.h"

class LauncherPIDSubsystem: public PIDSubsystem
{
public:
	LauncherPIDSubsystem(std::string side, SpeedController& motorPin, Counter& encoderPin);
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	void Reverse();
	void Manual();
	void SetManual(double power);
	void SendSD();

private:
	SpeedController& pidMotor;
	Counter& pidEncoder;
	double reverseMultiplier;
};
#endif
