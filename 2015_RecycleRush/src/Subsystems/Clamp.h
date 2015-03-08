#ifndef Clamp_H
#define Clamp_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Clamp: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	CANTalon *clampMotor;
	Encoder *clampEncoder;
	bool hasTote;
	bool atSpeed;

public:
	Clamp();
	void InitDefaultCommand();

	void SetSpeed(double speed);
	void Open(double speed);
	void Close(double speed);

	void Stop();

	bool IsOpen();
	bool IsClosed();

	bool IsLoaded(double rate);

	bool IsAtSpeed();
	bool IsAtSpeed(double rate);

	Encoder* GetEncoder();
};

#endif
