#ifndef LauncherPIDSubsystem_H
#define LauncherPIDSubsystem_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"

class LauncherPIDSubsystem: public PIDSubsystem
{
public:
	LauncherPIDSubsystem(std::string side, int motorPin, int encoderPin);
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	void Reverse();
	void Manual();
	void SetManual(double power);

private:
	Victor pidMotor;
	Counter pidEncoder;
	double reverseMultiplier;
};
#endif
