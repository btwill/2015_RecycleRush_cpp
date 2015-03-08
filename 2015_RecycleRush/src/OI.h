#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{

private:
	Joystick *driverController;
	Joystick *manipulatorController;
	JoystickButton *open;
	JoystickButton *close;
	JoystickButton *up;
	JoystickButton *down;



public:
	OI();
	Joystick* getDriveJoystick();
	Joystick* getManipulatorJoystick();

	double getClampSpeed();
	double getLiftSpeed();
	double getPanLoc();
	double getTiltLoc();
};

#endif
