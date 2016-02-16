#ifndef LEDSystem_H
#define LEDSystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <SerialPort.h>
#include <I2C.h>

class LEDSystem: public Subsystem
{
private:
//	int USB;
	I2C i2c;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	LEDSystem();
	void InitDefaultCommand();
	enum LEDstate { notarget, outrange, misaligned, fire, disabled, autonomous, teleop};
	void SendLEDState(LEDstate state);
};

#endif
