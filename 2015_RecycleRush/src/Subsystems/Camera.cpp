#include "../Commands/Camera/CameraJoystickDrive.h"
#include "Camera.h"
#include "RobotMap.h"

Camera::Camera() :
		Subsystem("Camera")
{
	pan = new Servo(0);
	tilt = new Servo(1);

}

void Camera::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new CameraJoystickDrive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.


void Camera::SetPan(double panValue)
{
	// Add the current value of the pan servo to the joystick input
	pan->Set(pan->Get() + panValue);
}

void Camera::SetTilt(double tiltValue)
{
	// Add the current value of the tilt servo to the joystick input
	tilt->Set(tilt->Get() + tiltValue);
}
void Camera::ResetCameraLoc()
{
	// Set the pan and tilt servos back to 0.0, may need changed based on where driver wants reset to be
	pan->Set(0.0);
	tilt->Set(0.0);

}
