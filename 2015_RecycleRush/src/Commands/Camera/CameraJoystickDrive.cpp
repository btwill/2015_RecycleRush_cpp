#include "CameraJoystickDrive.h"

CameraJoystickDrive::CameraJoystickDrive()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::camera);
}

// Called just before this Command runs the first time
void CameraJoystickDrive::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void CameraJoystickDrive::Execute()
{
	Robot::camera->SetPan(Robot::oi->getPanLoc());
	Robot::camera->SetTilt(Robot::oi->getTiltLoc());
}

// Make this return true when this Command no longer needs to run execute()
bool CameraJoystickDrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void CameraJoystickDrive::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CameraJoystickDrive::Interrupted()
{

}
