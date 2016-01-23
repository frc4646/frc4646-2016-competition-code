#ifndef StopSpeed_H
#define StopSpeed_H

#include "../CommandBase.h"
#include "WPILib.h"

class StopSpeed: public CommandBase
{
public:
	StopSpeed();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
