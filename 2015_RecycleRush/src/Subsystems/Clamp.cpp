#include "../Commands/Clamp/ClampJoystickDrive.h"
#include "Clamp.h"
#include "RobotMap.h"

Clamp::Clamp() :
		Subsystem("Clamp")

{
	clampMotor = new CANTalon(0);
	clampEncoder = new Encoder(1, 2, false, Encoder::k4X);
	hasTote = false;			// Has the clamp detected it has a tote
	atSpeed = false;			// Is the motor up to speed for tote detection

}

void Clamp::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ClampJoystickDrive());

}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Clamp::SetSpeed(double speed)
{
	// If the clamp opens it is assumed the tote has been released
	if (speed < 0.1)
		hasTote = false;

	clampMotor->Set(speed);
}

void Clamp::Open(double speed)
{
	// If the clamp opens it is assumed the tote has been released
	hasTote = false;
	clampMotor->Set(speed);
}

void Clamp::Close(double speed)
{
	clampMotor->Set(-speed);
}

void Clamp::Stop()
{
	clampMotor->Set(0.0);
}

Encoder* Clamp::GetEncoder()
{
	return clampEncoder;
}

bool Clamp::IsOpen()
{
	// limit switch is NC
	return clampMotor->IsFwdLimitSwitchClosed();
}

bool Clamp::IsClosed()
{
	// limit switch is NC
	return clampMotor->IsRevLimitSwitchClosed();
}


/*
 * IsLoaded() will check to see the motor has reached speed, and has slowed down due to an obstruction
 *
 */
bool Clamp::IsLoaded(double rate)
{
	// reset at speed for the next close command
	if(((clampEncoder->GetRate() < rate) && (atSpeed == true)) || (hasTote))
	{
		atSpeed = false;
		hasTote = true;
	}
	else
		hasTote = false;

	return hasTote;
}

/*
 * IsAtSpeed() will try and estimate the rate based off motor setpoint
 *
 */

bool Clamp::IsAtSpeed()
{
	if ((clampEncoder->GetRate() > (clampMotor->Get() * 100)))
		atSpeed = true;
	else
		atSpeed = false;

	return atSpeed;
}

/*
 * IsAtSpeed(double) will check to see if the motor has reached a certain speed
 *
 */

bool Clamp::IsAtSpeed(double rate)
{
	if ((clampEncoder->GetRate() > rate))
		atSpeed = true;
	else
		atSpeed = false;

	return atSpeed;
}
