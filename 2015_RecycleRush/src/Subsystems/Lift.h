#ifndef Lift_H
#define Lift_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Lift: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	CANTalon *liftMotor;

public:
	Lift();
	void InitDefaultCommand();

	void SetSpeed(double speed);
	void Raise(double speed);
	void Lower(double speed);
	void Stop();

	bool IsAtTop();
	bool IsAtBottom();
};

#endif
