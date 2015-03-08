#include "OI.h"
#include "RobotMap.h"
#include "Commands\Clamp\ClampAutoOpen.h"
#include "Commands\Clamp\ClampAutoClose.h"
#include "Commands\Lift\LiftAutoRaise.h"
#include "Commands\Lift\LiftAutoLower.h"

OI::OI()
{
	// Process operator interface input here.
	driverController = new Joystick(1);
	manipulatorController = new Joystick(2);

	open = new JoystickButton(manipulatorController, A);
	open->WhenPressed(new ClampAutoOpen());
	close = new JoystickButton(manipulatorController, B);
	close->WhenPressed(new ClampAutoClose());

	up = new JoystickButton(manipulatorController, X);
	up->WhenPressed(new LiftAutoRaise());
	down = new JoystickButton(manipulatorController, Y);
	down->WhenPressed(new LiftAutoLower());
}

Joystick* OI::getDriveJoystick()
{
	return driverController;
}

Joystick* OI::getManipulatorJoystick()
{
	return manipulatorController;
}

/*
 *   getClampSpeed()
 *   Combines the output of the left and right trigger into a single speed for the clamp motor
 */
double OI::getClampSpeed()
{
	return manipulatorController->GetRawAxis(RIGHT_TRIGGER) - manipulatorController->GetRawAxis(LEFT_TRIGGER);
}


double OI::getLiftSpeed()
{
	return manipulatorController->GetY();
}

double OI::getPanLoc()
{
	return manipulatorController->GetRawAxis(RIGHT_STICK_X);
}

double OI::getTiltLoc()
{
	return manipulatorController->GetRawAxis(RIGHT_STICK_Y);

}
