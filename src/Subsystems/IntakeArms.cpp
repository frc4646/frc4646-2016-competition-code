#include "IntakeArms.h"
#include "../RobotMap.h"
namespace {
	const int UNBALANCED_THRESHOLD = 50;
//	const float MAX_ENCODER_COUNT = (71.0*7.0)*(135.0/360.0);
	const float MAX_ENCODER_COUNT = 160;
}
IntakeArms::IntakeArms(MotorPin motorPort, DIOPin limitPort, DIOPin leftEncoderA, DIOPin leftEncoderB, DIOPin rightEncoderA, DIOPin rightEncoderB) :
		Subsystem("ExampleSubsystem"),
		arms(motorPort),
		LimitUp(new DigitalInput(limitPort)),
		LeftEncoder(leftEncoderA,leftEncoderB),
		RightEncoder(rightEncoderA,rightEncoderB)
{
	LiveWindow::GetInstance()->AddActuator("IntakeArms", "ArmMotor", arms);
	LiveWindow::GetInstance()->AddSensor("IntakeArms", "LimitUp", LimitUp.get());
	LiveWindow::GetInstance()->AddSensor("IntakeArms", "LeftEncoder", LeftEncoder);
	LiveWindow::GetInstance()->AddSensor("IntakeArms", "RightEncoder", RightEncoder);


}

void IntakeArms::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}


bool IntakeArms::GetUpValue()
{
	//return LimitUp->Get();
	return false;
}

void IntakeArms::SetSpeed(double power)
{
	arms.Set(power);
}

void IntakeArms::Raise() {

	arms.Set(-.4);
	//	if(LimitUp->Get())
//	{
//		LeftEncoder.Reset();
//		RightEncoder.Reset();
//	}
//	if(!MotorsUnbalanced()){
//		arms.Set((-RightEncoder.Get())/MAX_ENCODER_COUNT);
//	}
//	else{
//		arms.Set(0);
//	}
}

void IntakeArms::ForceRaise() {
	if(LimitUp->Get())
	{
		LeftEncoder.Reset();
		RightEncoder.Reset();
	}
	if(!MotorsUnbalanced()){
		arms.Set((-RightEncoder.Get())/MAX_ENCODER_COUNT);
	}
}

void IntakeArms::Lower() {
	arms.Set(.45);
	//	if(!MotorsUnbalanced()){
//		arms.Set((MAX_ENCODER_COUNT-RightEncoder.Get())/MAX_ENCODER_COUNT);
//	}
//	else{
//		arms.Set(0);
//	}
}

bool IntakeArms::IsFullyOut() {
	return false;
//	return RightEncoder.Get()>=MAX_ENCODER_COUNT;
}

void IntakeArms::SendSD() {
	SmartDashboard::PutNumber("LeftArmEncoder", LeftEncoder.Get());
	SmartDashboard::PutNumber("RightArmEncoder", RightEncoder.Get());
	SmartDashboard::PutBoolean("ArmLimitswitch", LimitUp.get());
}

bool IntakeArms::MotorsUnbalanced() {
	return abs(LeftEncoder.Get()-RightEncoder.Get())>UNBALANCED_THRESHOLD;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
