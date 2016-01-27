#ifndef HighSpeedCommand_H
#define HighSpeedCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class HighSpeedCommand: public CommandBase
{
public:
	HighSpeedCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
