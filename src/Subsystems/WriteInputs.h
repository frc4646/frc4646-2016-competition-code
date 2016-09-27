#ifndef WriteInputs_H
#define WriteInputs_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "Subsystems/WriteInputs.cpp"

class WriteInputs: public Subsystem
{
private:
	//std::unique_ptr<AnalogPort> hall;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	WriteInputs();
	void InitDefaultCommand();
	void SendSD();
	double GetInput();
};

#endif
