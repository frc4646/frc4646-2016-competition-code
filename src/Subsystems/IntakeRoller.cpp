#include "IntakeRoller.h"
#include "../RobotMap.h"

IntakeRoller::IntakeRoller(MotorPin rollerPort) :
		Subsystem("ExampleSubsystem"),
		roller(rollerPort)
{
	LiveWindow::GetInstance()->AddActuator("IntakeRoller", "RollerMotor", roller);

}

void IntakeRoller::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void IntakeRoller::SetSpeed(double power)
{
	roller.Set(power);
}

void IntakeRoller::SendSD() {
	SmartDashboard::PutNumber("Roller speed", roller.Get());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
