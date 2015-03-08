/*
 * Robot.h
 *
 *  Created on: March 1, 2015
 *      Author: Ben Williams
 */

#ifndef MY_ROBOT_H_
#define MY_ROBOT_H_

#include "WPILib.h"
#include "Commands/Command.h"

#include "Subsystems/Chassis.h"
#include "Subsystems/Clamp.h"
#include "Subsystems/Lift.h"
#include "Subsystems/Camera.h"
#include "OI.h"

class Robot: public IterativeRobot {
public:
	static Chassis *chassis;
	static Clamp *clamp;
	static Lift *lift;
	static Camera *camera;
	static OI *oi;


private:
	Command *autonomousCommand;
	LiveWindow *lw;
	SendableChooser* autoChooser;

	void RobotInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestPeriodic();
	void DisabledInit();
	void DisabledPeriodic();

	void Log();
};


#endif /* ROBOT_H_ */
