#include "VisionSubsystem.h"
#include "../RobotMap.h"

VisionSubsystem::VisionSubsystem() :
		Subsystem("VisionSubsystem")
{
	visionTable = NetworkTable::GetTable("GRIP/Contours");
}

void VisionSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void VisionSubsystem::SendData()
{
	std::stringstream xarray;
	for(size_t i = 0; i < xvalue.size(); ++i)
	{
	  if(i != 0)
	    xarray << ",";
	  xarray << xvalue[i];
	}
	std::string xString = xarray.str();
	SmartDashboard::PutString("X-Value", xString);
	std::stringstream yarray;
	for(size_t i = 0; i < yvalue.size(); ++i)
	{
	  if(i != 0)
	    yarray << ",";
	  yarray << yvalue[i];
	}
	std::string yString = yarray.str();
	SmartDashboard::PutString("Y-Value", yString);
	std::stringstream areaarray;
	for(size_t i = 0; i < area.size(); ++i)
	{
	  if(i != 0)
	    areaarray << ",";
	  areaarray << area[i];
	}
	std::string areaString = areaarray.str();
	SmartDashboard::PutString("Area", areaString);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
