#include "ClampAutoOpen.h"
#include "Robot.h"

ClampAutoOpen::ClampAutoOpen()
{
	// Use Requires() here to declare subsystem dependencies

	Requires(Robot::clamp);
}

// Called just before this Command runs the first time
void ClampAutoOpen::Initialize()
{
	Robot::clamp->Open(1.0);
}

// Called repeatedly when this Command is scheduled to run
void ClampAutoOpen::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ClampAutoOpen::IsFinished()
{
	return Robot::clamp->IsOpen();
}

// Called once after isFinished returns true
void ClampAutoOpen::End()
{
	Robot::clamp->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClampAutoOpen::Interrupted()
{
	End();
}
