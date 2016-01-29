#ifndef PhotoelectricCommand_H
#define PhotoelectricCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class PhotoelectricCommand: public CommandBase
{
public:
	PhotoelectricCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
