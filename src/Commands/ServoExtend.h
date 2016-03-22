#ifndef ServoExtend_H
#define ServoExtend_H

#include "../CommandBase.h"
#include "WPILib.h"

class ServoExtend: public CommandBase
{
public:
	ServoExtend();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
