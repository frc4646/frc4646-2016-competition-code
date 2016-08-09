/*
 * NullPIDOutput.h
 *
 *  Created on: Aug 8, 2016
 *      Author: User
 */

#ifndef SRC_SUBSYSTEMS_NULLPIDOUTPUT_H_
#define SRC_SUBSYSTEMS_NULLPIDOUTPUT_H_

#include <PIDOutput.h>

class NullPIDOutput: public PIDOutput {
public:
	NullPIDOutput();
	virtual ~NullPIDOutput();
	virtual void 	PIDWrite (float output);
};

#endif /* SRC_SUBSYSTEMS_NULLPIDOUTPUT_H_ */
