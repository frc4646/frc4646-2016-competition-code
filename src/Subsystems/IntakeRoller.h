#ifndef IntakeRoller_H
#define IntakeRoller_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "PinEnums.h"

class IntakeRoller: public Subsystem
{

public:
	IntakeRoller(MotorPin rollerPort);
	void InitDefaultCommand();
	void SetSpeed(double power);
	void SendSD();
private:
	Victor roller;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
};

#endif
