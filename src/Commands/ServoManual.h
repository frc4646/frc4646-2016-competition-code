#ifndef ServoManual_H
#define ServoManual_H

#include "../CommandBase.h"
#include "WPILib.h"

class ServoManual: public CommandBase
{
public:
	ServoManual();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
