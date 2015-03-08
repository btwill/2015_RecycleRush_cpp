#include "../Commands/Chassis/ChassisJoystickDrive.h"
#include "Chassis.h"
#include "RobotMap.h"
#include "OI.h"
#include <WPILib.h>

Chassis::Chassis() : Subsystem("Chassis")
{

	frontLeft = new CANTalon(2);
	frontRight = new CANTalon(13);
	rearLeft = new CANTalon(3);
	rearRight = new CANTalon(12);

	drive = new RobotDrive(frontLeft, frontRight, rearLeft, rearRight);

	drive->SetSafetyEnabled(false);

	drive->SetExpiration(0.1);
	drive->SetSensitivity(0.5);
	drive->SetMaxOutput(1.0);

/*  Invert Motors if Needed
	drive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
	drive->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
	drive->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
	drive->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
*/

	gyro = new Gyro(2);

	/* Configure gyro

    #ifdef REAL
		gyro->SetSensitivity(0.007); // TODO: Handle more gracefully?
    #endif
	LiveWindow::GetInstance()->AddSensor("DriveTrain", "Gyro", gyro);
*/

}

void Chassis::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
//	SetDefaultCommand(new joystickDrive());
	SetDefaultCommand(new ChassisJoystickDrive());

}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Chassis::joystickDrive(Joystick* stick)
{
//myDrive.MecanumDrive_Cartesian(driverController.GetX(), driverController.GetY(), driverController.GetZ());
	drive->MecanumDrive_Cartesian(stick->GetX(), stick->GetY(), stick->GetZ(), 0.0);
			//OI*stick->GetX(), *stick->GetY(), *stick->GetZ(), 0.0);

}

void Chassis::Stop()
{
	drive->MecanumDrive_Cartesian(0.0, 0.0, 0.0, 0.0);
}

