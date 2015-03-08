#ifndef ClampAutoOpen_H
#define ClampAutoOpen_H

#include "WPILib.h"
#include "Robot.h"
#include "OI.h"

class ClampAutoOpen: public Command
{
public:
	ClampAutoOpen();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
