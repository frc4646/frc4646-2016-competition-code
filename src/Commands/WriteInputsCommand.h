#ifndef WriteInputs_H
#define WriteInputs_H

#include "../CommandBase.h"
#include "WPILib.h"

class WriteInputsCommand: public CommandBase
{
public:
	WriteInputsCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
