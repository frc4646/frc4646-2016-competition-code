#ifndef VisionTrackingCommand_H
#define VisionTrackingCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class VisionTrackingCommand: public CommandBase
{
public:
	VisionTrackingCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

};

#endif
