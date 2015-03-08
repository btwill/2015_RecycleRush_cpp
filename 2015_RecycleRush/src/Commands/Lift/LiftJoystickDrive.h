#ifndef LiftJoystickDrive_H
#define LiftJoystickDrive_H

#include "WPILib.h"
#include "Robot.h"
#include "OI.h"

class LiftJoystickDrive: public Command
{
public:
	LiftJoystickDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
