#ifndef Launch_H
#define Launch_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class Launch: public CommandGroup
{
public:
	Launch(double speed);
};

#endif
