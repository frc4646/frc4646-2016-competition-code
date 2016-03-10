#ifndef AccelerometerSensor_H
#define AccelerometerSensor_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class AccelerometerSensor: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Accelerometer *accel;
public:
	AccelerometerSensor();
	void InitDefaultCommand();
	double GetX();
	double GetY();
	double GetZ();
};

#endif
