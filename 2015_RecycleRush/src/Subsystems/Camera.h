#ifndef Camera_H
#define Camera_H

#include "Commands/Subsystem.h"
#include "Robot.h"
#include "WPILib.h"
#include "OI.h"

class Camera: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	Servo *pan;
	Servo *tilt;


public:
	Camera();
	void InitDefaultCommand();

	void SetPan(double panValue);
	void SetTilt(double tiltValue);

	void ResetCameraLoc();
};

#endif
