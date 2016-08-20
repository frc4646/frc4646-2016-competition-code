#ifndef FlashlightOnCommand_H
#define FlashlightOnCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class FlashlightOnCommand: public CommandBase
{
public:
	FlashlightOnCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
