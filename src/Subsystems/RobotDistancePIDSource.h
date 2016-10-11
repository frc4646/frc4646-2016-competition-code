/*
 * RobotDistancePIDSource.h
 *
 *  Created on: Oct 3, 2016
 *      Author: User
 */

#ifndef SRC_SUBSYSTEMS_ROBOTDISTANCEPIDSOURCE_H_
#define SRC_SUBSYSTEMS_ROBOTDISTANCEPIDSOURCE_H_

#include <PIDSource.h>

class VisionCalculation;

class RobotDistancePIDSource: public PIDSource {
	public:
		RobotDistancePIDSource(VisionCalculation* visionCalculation);
		virtual ~RobotDistancePIDSource();
		virtual double 	PIDGet ();

	private:
		VisionCalculation* visionCalculation;
};

#endif /* SRC_SUBSYSTEMS_ROBOTDISTANCEPIDSOURCE_H_ */
