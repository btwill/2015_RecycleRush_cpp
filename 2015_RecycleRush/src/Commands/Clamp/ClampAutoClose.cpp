#include "ClampAutoClose.h"
#include "Robot.h"

ClampAutoClose::ClampAutoClose()
{
	// Use Requires() here to declare subsystem dependencies

	Requires(Robot::clamp);

}

// Called just before this Command runs the first time
void ClampAutoClose::Initialize()
{
	Robot::clamp->Close(1.0);

}

// Called repeatedly when this Command is scheduled to run
void ClampAutoClose::Execute()
{
	Robot::clamp->IsAtSpeed(300);
}

// Make this return true when this Command no longer needs to run execute()
bool ClampAutoClose::IsFinished()
{
	return Robot::clamp->IsClosed() || Robot::clamp->IsLoaded(300.0);
}

// Called once after isFinished returns true
void ClampAutoClose::End()
{
	Robot::clamp->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClampAutoClose::Interrupted()
{
	End();
}
