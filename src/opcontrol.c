#include "main.h"

bool turboMode = false;

int lMotor1 = 1;
int lMotor2 = 2;
int lMotor3 = 3;

int rMotor1 = 4;
int rMotor2 = 5;
int rMotor3 = 6;

int intake1 = 7;

int conveyor1 = 8;

int flyWheel1 = 9;
int flyWheel2 = 10;

void lDriveSet(int control) {
	motorSet(lMotor1, -control);
	motorSet(lMotor2, -control);
	motorSet(lMotor3, -control);
}
void rDriveSet(int control) {
	motorSet(rMotor1, -control);
	motorSet(rMotor2, -control);
	motorSet(rMotor3, -control);
}
void flyWheelSet(int control) {
	motorSet(flyWheel1, control);
	motorSet(flyWheel2, control);
}

void intakeSet(int control) {
	motorSet(intake1, control);
}

void conveyorSet(int control) {
	motorSet(conveyor1, control);
}

void operatorControl() {
	while (true) {
		if (!turboMode) {
			if (joystickGetAnalog(1, 3) > 2 || joystickGetAnalog(1, 3) < -2)
				lDriveSet(joystickGetAnalog(1,3)^3/16129);
			else
				lDriveSet(0);

			if (joystickGetAnalog(1, 2) > 2 || joystickGetAnalog(1, 2) < -2)
				rDriveSet(joystickGetAnalog(1,2)^3/16129);
			else
				rDriveSet(0);
		} else {
			if (joystickGetAnalog(1, 3) > 5 || joystickGetAnalog(1, 3) < -5)
				lDriveSet(joystickGetAnalog(1,3));
			else
				lDriveSet(0);

			if (joystickGetAnalog(1, 2) > 5 || joystickGetAnalog(1, 2) < -5)
				rDriveSet(joystickGetAnalog(1,2));
			else
				rDriveSet(0);
		}

		if (joystickGetDigital(1, 5, JOY_DOWN)) {
			intakeSet(127);
		} else {
			intakeSet(0);
		}

		if (joystickGetDigital(1, 5, JOY_UP)) {
			conveyorSet(127);
		} else {
			conveyorSet(0);
		}

		if (joystickGetDigital(1, 6, JOY_UP)) {
			flyWheelSet(127);
		} else {
			flyWheelSet(0);
		}

		if (joystickGetDigital(1, 6, JOY_DOWN)) {
			turboMode = true;
		} else {
			turboMode = false;
		}

		delay(25);

	}
}
