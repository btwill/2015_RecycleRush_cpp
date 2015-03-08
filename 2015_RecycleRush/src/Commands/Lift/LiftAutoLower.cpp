#include "LiftAutoLower.h"

LiftAutoLower::LiftAutoLower()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::lift);
}

// Called just before this Command runs the first time
void LiftAutoLower::Initialize()
{
	Robot::lift->Lower(1.0);
}

// Called repeatedly when this Command is scheduled to run
void LiftAutoLower::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool LiftAutoLower::IsFinished()
{
	return Robot::lift->IsAtBottom();
}

// Called once after isFinished returns true
void LiftAutoLower::End()
{
	Robot::lift->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftAutoLower::Interrupted()
{
	End();
}
