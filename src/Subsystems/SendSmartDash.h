#ifndef SEND_SMART_DASH_H
#define SEND_SMART_DASH_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class SendSmartDash: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	SendSmartDash();
	void InitDefaultCommand();
};

#endif
