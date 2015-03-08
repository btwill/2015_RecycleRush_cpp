#ifndef ClampJoystickDrive_H
#define ClampJoystickDrive_H

#include "WPILib.h"
#include "Robot.h"

class ClampJoystickDrive: public Command
{
public:
	ClampJoystickDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
