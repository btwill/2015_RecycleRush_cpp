#include "LiftAutoRaise.h"

LiftAutoRaise::LiftAutoRaise()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::lift);
}

// Called just before this Command runs the first time
void LiftAutoRaise::Initialize()
{
	Robot::lift->Raise(1.0);

}

// Called repeatedly when this Command is scheduled to run
void LiftAutoRaise::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool LiftAutoRaise::IsFinished()
{
	return Robot::lift->IsAtTop();
}

// Called once after isFinished returns true
void LiftAutoRaise::End()
{
	Robot::lift->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftAutoRaise::Interrupted()
{
	End();
}
