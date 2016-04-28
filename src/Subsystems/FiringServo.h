#ifndef FiringServo_H
#define FiringServo_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "PinEnums.h"

class FiringServo: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Servo StagingServo;
public:
	FiringServo(MotorPin servoPort);
	void InitDefaultCommand();
	void GoToAngle(double angle);
	void Set(double value);

	void RetractServo();
	void ExtendServo();
};

#endif
