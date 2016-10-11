/*
 * DoubleMotor.h
 *
 *  Created on: Oct 8, 2016
 *      Author: User
 */

#ifndef SRC_DOUBLEMOTOR_H_
#define SRC_DOUBLEMOTOR_H_

#include <SpeedController.h>
#include <Victor.h>
#include "PinEnums.h"

class DoubleMotor: public SpeedController {
public:
	DoubleMotor(MotorPin leftPin, MotorPin rightPin);
	virtual ~DoubleMotor();

	  virtual void PIDWrite(float output);
	  virtual void Set(float speed, uint8_t syncGroup = 0);
	  virtual float Get() const;
	  virtual void SetInverted(bool isInverted);

	  virtual void Disable();
	  virtual bool GetInverted() const;
	  virtual void StopMotor();


private:
	Victor Left;
	Victor Right;
};

#endif /* SRC_DOUBLEMOTOR_H_ */
