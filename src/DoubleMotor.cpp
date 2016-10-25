/*
 * DoubleMotor.cpp
 *
 *  Created on: Oct 8, 2016
 *      Author: User
 */

#include <DoubleMotor.h>

DoubleMotor::DoubleMotor(MotorPin leftPin, MotorPin rightPin)
: Left(leftPin)
, Right(rightPin)
{
	// TODO Auto-generated constructor stub

}

DoubleMotor::~DoubleMotor() {
	// TODO Auto-generated destructor stub
}

void DoubleMotor::PIDWrite(float output)
{
	Left.PIDWrite(output);
	Right.PIDWrite(output);
}

void DoubleMotor::Set(float speed, uint8_t syncGroup)
{
	// Left.Set(speed, syncGroup);
	// Right.Set(speed, syncGroup);
	Left.Set(speed);
	Right.Set(speed);
}

float DoubleMotor::Get() const
{
	return Left.Get();
}

void DoubleMotor::SetInverted(bool isInverted)
{
	Left.SetInverted(isInverted);
	Right.SetInverted(isInverted);
}

void DoubleMotor::Disable()
{
	Left.Disable();
	Right.Disable();
}

bool DoubleMotor::GetInverted() const
{
	return Left.GetInverted();
}

void DoubleMotor::StopMotor()
{
	Left.StopMotor();
	Right.StopMotor();
}


