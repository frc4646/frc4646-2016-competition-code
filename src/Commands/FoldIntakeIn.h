#ifndef FoldIntakeIn_H
#define FoldIntakeIn_H

#include "../CommandBase.h"
#include "WPILib.h"

class FoldIntakeIn: public CommandBase
{
public:
	FoldIntakeIn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
