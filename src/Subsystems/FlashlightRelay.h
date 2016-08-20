#ifndef FlashlightRelay_H
#define FlashlightRelay_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class FlashlightRelay: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Relay lightSpike;
public:
	FlashlightRelay();
	void InitDefaultCommand();
	void On();
	void Off();
};

#endif
