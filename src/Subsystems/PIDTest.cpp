#include "PIDTest.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"

PIDTest::PIDTest() :
		PIDSubsystem("PIDTest", 0.9, 0.06, -0.001),	//P:.9, I:.06, D:-.001
		pidMotor(3),
		pidEncoder(0,1)
{
	LiveWindow::GetInstance()->AddActuator("Pid test thing", "foo", GetPIDController());
	LiveWindow::GetInstance()->AddActuator("Pid test thing", "OutputMotor", pidMotor);
	LiveWindow::GetInstance()->AddSensor("Pid test thing", "encoder", pidEncoder);
	pidEncoder.SetDistancePerPulse(1/(71.0*7.0)); 	//7 Pulses per revolution, 1/71 reduction, rotations per second
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
//	SetSetpoint(.5);
//	Enable();
}

double PIDTest::ReturnPIDInput()
{
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	return pidEncoder.GetRate();
}

void PIDTest::UsePIDOutput(double output)
{
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	pidMotor.PIDWrite(output);
}

void PIDTest::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());

}
