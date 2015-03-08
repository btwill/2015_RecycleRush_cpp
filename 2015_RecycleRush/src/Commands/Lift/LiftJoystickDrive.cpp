#include "LiftJoystickDrive.h"

LiftJoystickDrive::LiftJoystickDrive()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::lift);
}

// Called just before this Command runs the first time
void LiftJoystickDrive::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void LiftJoystickDrive::Execute()
{
	Robot::lift->SetSpeed(Robot::oi->getLiftSpeed());
}

// Make this return true when this Command no longer needs to run execute()
bool LiftJoystickDrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void LiftJoystickDrive::End()
{
	Robot::lift->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftJoystickDrive::Interrupted()
{
	End();
}
