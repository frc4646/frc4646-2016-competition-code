#ifndef SpinUp_H
#define SpinUp_H

#include "../CommandBase.h"
#include "WPILib.h"

class SpinUp: public CommandBase
{
public:
	SpinUp();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
