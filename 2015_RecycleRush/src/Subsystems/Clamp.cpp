#include "../Commands/Clamp/ClampJoystickDrive.h"
#include "Clamp.h"
#include "RobotMap.h"

Clamp::Clamp() :
		Subsystem("Clamp")

{
	clampMotor = new CANTalon(0);
	clampEncoder = new Encoder(1, 2, false, Encoder::k4X);
	hasTote = false;
	atSpeed = false;

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
	if (speed < -0.1)
		hasTote = false;

	clampMotor->Set(speed);
}

void Clamp::Open(double speed)
{
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
	return clampMotor->IsFwdLimitSwitchClosed();
}

bool Clamp::IsClosed()
{
	return clampMotor->IsRevLimitSwitchClosed();
}

bool Clamp::IsLoaded(double rate)
{
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


bool Clamp::IsAtSpeed(double rate)
{
	if ((clampEncoder->GetRate() > rate))
		atSpeed = true;
	else
		atSpeed = false;

	return atSpeed;
}
