#ifndef SendI2C_H
#define SendI2C_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Subsystems/LEDSystem.h"

class SendI2C: public CommandBase
{
public:
	SendI2C(LEDSystem::LEDstate state);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	LEDSystem::LEDstate stateLED;

};

#endif
