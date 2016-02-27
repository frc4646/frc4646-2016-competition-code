#ifndef ForceFold_H
#define ForceFold_H

#include "../CommandBase.h"
#include "WPILib.h"

class ForceFold: public CommandBase
{
public:
	ForceFold();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
