#ifndef ROBOTMAP_H
#define ROBOTMAP_H


#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
//const int LEFTMOTOR = 1;
//const int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

// XBox Controller Axis Values
const int LEFT_STICK_X = 0;
const int LEFT_STICK_Y = 1;
const int LEFT_TRIGGER = 2;
const int RIGHT_TRIGGER = 3;
const int RIGHT_STICK_X = 4;
const int RIGHT_STICK_Y = 5;

// XBox Controller Button Values
const int A = 0;
const int B = 1;
const int X = 2;
const int Y = 3;
const int LEFT_BUMPER = 4;
const int RIGHT_BUMPER = 5;
const int SELECT = 6;
const int START = 7;
const int LEFT_STICK_PRESS = 8;
const int RIGHT_STICK_PRESS = 9;

#endif
