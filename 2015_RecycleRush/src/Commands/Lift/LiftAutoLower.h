#ifndef LiftAutoLower_H
#define LiftAutoLower_H

#include "WPILib.h"
#include "Robot.h"
#include "OI.h"

class LiftAutoLower: public Command
{
public:
	LiftAutoLower();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
