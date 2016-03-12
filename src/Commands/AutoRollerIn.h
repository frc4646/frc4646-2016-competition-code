#ifndef AutoRollerIn_H
#define AutoRollerIn_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoRollerIn: public CommandBase
{
public:
	AutoRollerIn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
