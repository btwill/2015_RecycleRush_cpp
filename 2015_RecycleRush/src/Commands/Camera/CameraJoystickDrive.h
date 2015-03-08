#ifndef CameraJoystickDrive_H
#define CameraJoystickDrive_H

#include "WPILib.h"
#include "Robot.h"

class CameraJoystickDrive: public Command
{
public:
	CameraJoystickDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
