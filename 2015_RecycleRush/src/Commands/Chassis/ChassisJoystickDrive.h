#ifndef joystickDrive_H
#define joystickDrive_H

#include "WPILib.h"
#include "Robot.h"

class ChassisJoystickDrive: public Command
{
public:
	ChassisJoystickDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
