#ifndef RingerCommand_H
#define RingerCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class RingerCommand: public CommandBase
{
public:
	RingerCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
