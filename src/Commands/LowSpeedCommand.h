#ifndef LowSpeedCommand_H
#define LowSpeedCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class LowSpeedCommand: public CommandBase
{
public:
	LowSpeedCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
