#ifndef AutonomousMoveCan_H
#define AutonomousMoveCan_H

#include "Robot.h"
#include "WPILib.h"

class AutonomousMoveCan: public Command
{
public:
	AutonomousMoveCan();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
