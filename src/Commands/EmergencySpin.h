#ifndef EmergencySpin_H
#define EmergencySpin_H

#include "../CommandBase.h"
#include "WPILib.h"

class EmergencySpin: public CommandBase
{
public:
	EmergencySpin();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
