#ifndef ReverseSpeed_H
#define ReverseSpeed_H

#include "../CommandBase.h"
#include "WPILib.h"

class ReverseSpeed: public CommandBase
{
public:
	ReverseSpeed();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
