#ifndef UltrasonicCommand_H
#define UltrasonicCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class UltrasonicCommand: public CommandBase
{
public:
	UltrasonicCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
