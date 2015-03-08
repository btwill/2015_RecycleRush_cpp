#include <Commands/Chassis/ChassisJoystickDrive.h>
#include "Robot.h"

ChassisJoystickDrive::ChassisJoystickDrive()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::chassis);
}

// Called just before this Command runs the first time
void ChassisJoystickDrive::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ChassisJoystickDrive::Execute()
{
	Robot::chassis->joystickDrive(Robot::oi->getDriveJoystick());

}

// Make this return true when this Command no longer needs to run execute()
bool ChassisJoystickDrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ChassisJoystickDrive::End()
{
	Robot::chassis->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ChassisJoystickDrive::Interrupted()
{

}

