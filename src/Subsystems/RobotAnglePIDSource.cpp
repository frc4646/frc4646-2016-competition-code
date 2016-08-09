/*
 * RobotAnglePIDSource.cpp
 *
 *  Created on: Aug 8, 2016
 *      Author: User
 */

#include <Subsystems/RobotAnglePIDSource.h>
#include "Subsystems/VisionCalculation.h"

RobotAnglePIDSource::RobotAnglePIDSource(VisionCalculation* vC)
:visionCalculation(vC)
{
	// TODO Auto-generated constructor stub

}

RobotAnglePIDSource::~RobotAnglePIDSource() {
	// TODO Auto-generated destructor stub
}

double RobotAnglePIDSource::PIDGet()
{
	return visionCalculation->RobotToGoalAngle()/320.0;

}
