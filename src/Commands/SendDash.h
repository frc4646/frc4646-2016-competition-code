#ifndef SendDash_H
#define SendDash_H

#include "../CommandBase.h"
#include "WPILib.h"

class SendDash: public CommandBase
{
public:
	SendDash();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
