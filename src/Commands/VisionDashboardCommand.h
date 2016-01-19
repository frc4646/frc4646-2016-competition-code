#ifndef VisionDashboardCommand_H
#define VisionDashboardCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class VisionDashboardCommand: public CommandBase
{
public:
	VisionDashboardCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
