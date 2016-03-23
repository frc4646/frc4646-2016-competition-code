#ifndef ServoRetract_H
#define ServoRetract_H

#include "../CommandBase.h"
#include "WPILib.h"

class ServoRetract: public CommandBase
{
public:
	ServoRetract();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
