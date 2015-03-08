#include "../Commands/Lift/LiftJoystickDrive.h"
#include "Lift.h"
#include "RobotMap.h"
#include "OI.h"
#include <WPILib.h>

Lift::Lift() :
		Subsystem("Lift")
{
	liftMotor = new CANTalon(15);
}

void Lift::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new LiftJoystickDrive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Lift::SetSpeed(double speed)
{
	liftMotor->Set(speed);
}

void Lift::Raise(double speed)
{
	liftMotor->Set(speed);

}

void Lift::Lower(double speed)
{
	liftMotor->Set(-speed);
}

void Lift::Stop()
{
	liftMotor->Set(0.0);
}

bool Lift::IsAtTop()
{
	// limit switch is NC
	return liftMotor->IsFwdLimitSwitchClosed();
}

bool Lift::IsAtBottom()
{
	// limit switch is NC
	return liftMotor->IsRevLimitSwitchClosed();
}
