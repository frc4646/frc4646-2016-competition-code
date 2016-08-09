/*
 * RobotAnglePIDSource.h
 *
 *  Created on: Aug 8, 2016
 *      Author: User
 */

#ifndef SRC_SUBSYSTEMS_ROBOTANGLEPIDSOURCE_H_
#define SRC_SUBSYSTEMS_ROBOTANGLEPIDSOURCE_H_

#include <PIDSource.h>

class VisionCalculation;

class RobotAnglePIDSource: public PIDSource {
public:
	RobotAnglePIDSource(VisionCalculation* visionCalculation);
	virtual ~RobotAnglePIDSource();
	virtual double 	PIDGet ();

private:
	VisionCalculation* visionCalculation;
};

#endif /* SRC_SUBSYSTEMS_ROBOTANGLEPIDSOURCE_H_ */
