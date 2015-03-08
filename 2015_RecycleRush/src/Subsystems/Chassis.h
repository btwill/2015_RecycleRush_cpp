#ifndef Chassis_H
#define Chassis_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Chassis: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	CANTalon *frontLeft;
	CANTalon *frontRight;
	CANTalon *rearLeft;
	CANTalon *rearRight;

	RobotDrive *drive;

	Gyro *gyro;


public:
	Chassis();
	void InitDefaultCommand();
	void Stop();
	void joystickDrive(Joystick* driverController);
};

#endif
