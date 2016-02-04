#ifndef FoldIntakeOut_H
#define FoldIntakeOut_H

#include "../CommandBase.h"
#include "WPILib.h"

class FoldIntakeOut: public CommandBase
{
public:
	FoldIntakeOut();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
