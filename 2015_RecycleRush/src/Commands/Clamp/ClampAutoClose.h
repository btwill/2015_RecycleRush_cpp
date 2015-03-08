#ifndef ClampAutoClose_H
#define ClampAutoClose_H

#include "WPILib.h"
#include "Robot.h"
#include "OI.h"

class ClampAutoClose: public Command
{
public:
	ClampAutoClose();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
