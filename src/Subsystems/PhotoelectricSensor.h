#ifndef PhotoelectricSensor_H
#define PhotoelectricSensor_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class PhotoelectricSensor: public Subsystem
{
private:
	Counter PhotoSensor;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	PhotoelectricSensor();
	void InitDefaultCommand();
	double GetValue();
};

#endif
