#ifndef IntakeArms_H
#define IntakeArms_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class IntakeArms: public Subsystem
{

public:
	IntakeArms();
	void InitDefaultCommand();
	bool GetDownValue();
	bool GetUpValue();
	void SetSpeed(double power);
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Victor armright;
	Victor armleft;
	std::unique_ptr<DigitalInput> LimitDown;
	std::unique_ptr<DigitalInput> LimitUp;
};

#endif
