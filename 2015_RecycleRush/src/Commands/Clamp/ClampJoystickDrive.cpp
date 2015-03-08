#include "ClampJoystickDrive.h"
#include "Robot.h"

ClampJoystickDrive::ClampJoystickDrive()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::clamp);
}

// Called just before this Command runs the first time
void ClampJoystickDrive::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ClampJoystickDrive::Execute()
{
	Robot::clamp->SetSpeed(Robot::oi->getClampSpeed());
}

// Make this return true when this Command no longer needs to run execute()
bool ClampJoystickDrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ClampJoystickDrive::End()
{
	Robot::clamp->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClampJoystickDrive::Interrupted()
{
	End();
}
