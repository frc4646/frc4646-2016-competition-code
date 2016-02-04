#ifndef IntakeRoller_H
#define IntakeRoller_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class IntakeRoller: public Subsystem
{

public:
	IntakeRoller();
	void InitDefaultCommand();
	void SetSpeed(double power);
private:
	Victor right;
	Victor left;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
};

#endif
