#ifndef VisionSubsystem_H
#define VisionSubsystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class VisionSubsystem: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<NetworkTable> visionTable;
	std::vector<double> xvalue = visionTable->GetNumberArray("centerX", llvm::ArrayRef<double>());
	std::vector<double> yvalue = visionTable->GetNumberArray("centerY", llvm::ArrayRef<double>());
	std::vector<double> area = visionTable->GetNumberArray("area", llvm::ArrayRef<double>());

public:
	VisionSubsystem();
	void InitDefaultCommand();
	void SendData();
};

#endif
