#ifndef ReverseIntakeCommand_H
#define ReverseIntakeCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class ReverseIntakeCommand: public CommandBase
{
public:
	ReverseIntakeCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
