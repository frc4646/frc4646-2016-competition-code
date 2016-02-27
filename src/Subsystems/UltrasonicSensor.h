#ifndef UltrasonicSensor_H
#define UltrasonicSensor_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "PinEnums.h"

class UltrasonicSensor: public Subsystem
{
private:
	std::unique_ptr<AnalogInput> DistSensor;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	UltrasonicSensor(AnalogPin port);
	void InitDefaultCommand();
	double GetDistance();
	double GetVoltage();
	void SendSD();
};

#endif
