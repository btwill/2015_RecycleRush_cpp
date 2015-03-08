#ifndef LiftAutoRaise_H
#define LiftAutoRaise_H

#include "WPILib.h"
#include "Robot.h"
#include "OI.h"

class LiftAutoRaise: public Command
{
public:
	LiftAutoRaise();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
