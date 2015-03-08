#include "WPILib.h"
#include "Commands/Command.h"
#include "Robot.h"
#include "Commands/AutonomousMoveCan.h"

Chassis* Robot::chassis = NULL;
Clamp* Robot::clamp = NULL;
Lift* Robot::lift = NULL;
Camera* Robot::camera = NULL;

OI* Robot::oi = NULL;

void Robot::RobotInit()
{

	chassis = new Chassis();
	clamp = new Clamp();
	lift = new Lift();
	camera = new Camera();

	oi = new OI();

	autonomousCommand = new AutonomousMoveCan();
	lw = LiveWindow::GetInstance();
}

void Robot::DisabledPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit()
{
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	if (autonomousCommand != NULL)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic()
{
	lw->Run();
}

void Robot::DisabledInit()
{

}


START_ROBOT_CLASS(Robot);

