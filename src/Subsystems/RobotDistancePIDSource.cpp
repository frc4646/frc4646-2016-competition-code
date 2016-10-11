/*
 * RobotDistancePIDSource.cpp
 *
 *  Created on: Oct 3, 2016
 *      Author: User
 */

#include <Subsystems/RobotDistancePIDSource.h>
#include "Subsystems/VisionCalculation.h"

RobotDistancePIDSource::RobotDistancePIDSource(VisionCalculation* vC)
:visionCalculation(vC)
{
	// TODO Auto-generated constructor stub

}

RobotDistancePIDSource::~RobotDistancePIDSource() {
	// TODO Auto-generated destructor stub
}

double RobotDistancePIDSource::PIDGet()
{
	double result = -visionCalculation->GetGoalDistance()/160;
	SmartDashboard::PutNumber("DistancePIDGet", result);
	return result;
}
