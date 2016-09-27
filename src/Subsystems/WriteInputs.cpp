/*#include "WriteInputs.h"
#include "../RobotMap.h"

WriteInputs::WriteInputs() :
		Subsystem("WriteInputs")

{
	//LiveWindow::GetInstance()->Add("WriteInputs", "Sensor", GetInput());
}

void WriteInputs::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void WriteInputs::SendSD() {
	SmartDashboard::PutNumber("WriteInputs", GetInput());
}


double WriteInputs::GetInput(){
	AnalogInput *hall = new AnalogInput(0);
	double val = hall->GetVoltage();
	delete hall;
	return val;
}
*/
