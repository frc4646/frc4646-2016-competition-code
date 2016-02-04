#include "LauncherPIDSubsystem.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"

LauncherPIDSubsystem::LauncherPIDSubsystem(std::string side, int motorPin, int encoderPin) :
		PIDSubsystem(side + "LauncherPIDSubsystem", 0.588, 0.375, .094),
		pidMotor(motorPin),
		pidEncoder(encoderPin),
		reverseMultiplier(1)
{
	LiveWindow::GetInstance()->AddActuator(side + "LauncherPID", side + "PIDController", GetPIDController());
	LiveWindow::GetInstance()->AddActuator(side + "LauncherPID", side + "OutputMotor", pidMotor);
	LiveWindow::GetInstance()->AddSensor(side + "LauncherPID", side + "Encoder", pidEncoder);
	SmartDashboard::PutData(side+"LauncherPidController", GetPIDController().get());
	GetPIDController()->SetOutputRange(0,1);
	SetPIDSourceType(PIDSourceType::kDisplacement);
	pidEncoder.SetSamplesToAverage(2);
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
}

double LauncherPIDSubsystem::ReturnPIDInput()
{
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	double speed = (1.0/(pidEncoder.GetPeriod()))*60.0;
	SmartDashboard::PutNumber(GetName() + "RPMs", speed);
	return (speed)/5000;
}

void LauncherPIDSubsystem::UsePIDOutput(double output)
{
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	pidMotor.PIDWrite(output * reverseMultiplier);
}

void LauncherPIDSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
}

void LauncherPIDSubsystem::Reverse()
{
	reverseMultiplier *= -1;
}

void LauncherPIDSubsystem::Manual()
{
	Disable();

}

void LauncherPIDSubsystem::SetManual(double power)
{
	pidMotor.Set(power);
}
