#include "AutonomousMoveCan.h"
#include "Robot.h"

AutonomousMoveCan::AutonomousMoveCan()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::chassis);
}

// Called just before this Command runs the first time
void AutonomousMoveCan::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutonomousMoveCan::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousMoveCan::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutonomousMoveCan::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousMoveCan::Interrupted()
{

}
