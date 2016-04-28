#include "SlavedLauncherPid.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"

SlavedLauncherPID::SlavedLauncherPID(std::string side, MotorPin motorPin, MotorPin motorPin2, DIOPin encoderPin) :
		PIDSubsystem(side + "SlavedLauncherPID", 4.5, 0.167, .0),
		pidMotor(motorPin),
		pidMotor2(motorPin2),

		pidEncoder(encoderPin),
		reverseMultiplier(1)
{
	LiveWindow::GetInstance()->AddActuator(side + "LauncherPID2", side + "PIDController", GetPIDController());
	LiveWindow::GetInstance()->AddActuator(side + "LauncherPID2", side + "OutputMotor", pidMotor);
	LiveWindow::GetInstance()->AddActuator(side + "LauncherPID2", side + "OutputMotor2", pidMotor2);
	LiveWindow::GetInstance()->AddSensor(side + "LauncherPID2", side + "Encoder", pidEncoder);
//	SmartDashboard::PutData(side+"LauncherPidController", GetPIDController().get());
	GetPIDController()->SetOutputRange(0,1);
	SetAbsoluteTolerance(.05);
	SetPIDSourceType(PIDSourceType::kDisplacement);
	pidEncoder.SetSamplesToAverage(1);
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
}

double SlavedLauncherPID::ReturnPIDInput()
{
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	double speed = (1.0/(pidEncoder.GetPeriod()))*60.0;
//	SmartDashboard::PutNumber(GetName() + "RPMs", speed);
	return (speed)/5000;
}

void SlavedLauncherPID::UsePIDOutput(double output)
{
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	pidMotor.PIDWrite(output * reverseMultiplier);
	pidMotor2.PIDWrite(output * reverseMultiplier);

	//	pidMotor.PIDWrite(.5);

}

void SlavedLauncherPID::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
}

void SlavedLauncherPID::Reverse()
{
	reverseMultiplier *= -1;
}

void SlavedLauncherPID::Manual()
{
	Disable();

}

void SlavedLauncherPID::SetManual(double power)
{
	pidMotor.Set(power);
	pidMotor2.Set(power);

}

void SlavedLauncherPID::SendSD() {
	SmartDashboard::PutNumber(GetName() + "speed", ReturnPIDInput());
	SmartDashboard::PutNumber(GetName() + "power", pidMotor.Get());
	SmartDashboard::PutNumber(GetName() + "power2", pidMotor2.Get());
	Command* comm = GetCurrentCommand();
	if(comm)
	{
		SmartDashboard::PutString(GetName() + "command" , comm->GetName());
	}
}
