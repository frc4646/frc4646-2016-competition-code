#ifndef Ringer_H
#define Ringer_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Ringer: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	 Victor ringerMotor;
 public:
	Ringer();
	void InitDefaultCommand();
	void SetSpeed(double power);
};

#endif
