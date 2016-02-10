#include "LEDSystem.h"
#include "../RobotMap.h"

LEDSystem::LEDSystem() :
		Subsystem("LEDSystem"), i2c(I2C::kOnboard, 4)
{

}


void LEDSystem::InitDefaultCommand()
{
//	SetDefaultCommand(new SendTeamCommand());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void LEDSystem::SendLEDState(LEDstate state) {

	unsigned char charHeight = state;
	i2c.Transaction(&charHeight, 1, NULL,0);

}
