#ifndef IntakeArms_H
#define IntakeArms_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "PinEnums.h"

class IntakeArms: public Subsystem
{

public:
	IntakeArms(MotorPin motorPort, DIOPin limitPort, DIOPin leftEncoderA, DIOPin leftEncoderB, DIOPin rightEncoderA, DIOPin rightEncoderB);
	void InitDefaultCommand();
	bool GetUpValue();
	bool IsFullyOut();
	void SetSpeed(double power);
	void Raise();
	void ForceRaise();
	void Lower();
	void SendSD();
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Victor arms;
	std::unique_ptr<DigitalInput> LimitUp;
	Encoder LeftEncoder;
	Encoder RightEncoder;
	bool MotorsUnbalanced();

};

#endif
