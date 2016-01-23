#ifndef MedSpeedCommand_H
#define MedSpeedCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class MedSpeedCommand: public CommandBase
{
public:
	MedSpeedCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
