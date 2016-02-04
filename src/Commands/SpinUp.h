#ifndef SpinUp_H
#define SpinUp_H

#include "../CommandBase.h"
#include "WPILib.h"

class SpinUp: public CommandBase
{
public:
	SpinUp(double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double launchSpeed;
};

#endif
