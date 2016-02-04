#include <Subsystems/PIDTest.h>
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"

PIDTest::PIDTest() :
		PIDSubsystem("PIDTest", .075, 0, -.01),	//P:.9, I:.06, D:-.001
		pidMotor(3),
		pidEncoder(2)
{
	LiveWindow::GetInstance()->AddActuator("Pid test thing", "PIDController", GetPIDController());
	LiveWindow::GetInstance()->AddActuator("Pid test thing", "OutputMotor", pidMotor);
	LiveWindow::GetInstance()->AddSensor("Pid test thing", "encoder", pidEncoder);
	GetPIDController()->SetOutputRange(0,1);
	SetPIDSourceType(PIDSourceType::kRate);
	pidEncoder.SetSamplesToAverage(2);
//	pidEncoder.SetDistancePerPulse(1/(71.0*7.0)); 	//7 Pulses per revolution, 1/71 reduction, rotations per second
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
	return ((1.0/(pidEncoder.GetPeriod()))*60.0)/5000;
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
