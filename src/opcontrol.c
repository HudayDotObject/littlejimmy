#include "main.h"

bool turboMode = false;

int lMotor1 = 1;
int lMotor2 = 2;

int rMotor1 = 3;
int rMotor2 = 4;

int flyWheel1 = 6;
int flyWheel2 = 7;

int intake1 = 5;

int conveyor1 = 8;

void lDriveSet(int control) {
	motorSet(lMotor1, -control);
	motorSet(lMotor2, -control);
}
void rDriveSet(int control) {
	motorSet(rMotor1, -control);
	motorSet(rMotor2, -control);
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
				lDriveSet(joystickGetAnalog(1,3)/5);
			else
				lDriveSet(0);

			if (joystickGetAnalog(1, 2) > 2 || joystickGetAnalog(1, 2) < -2)
				rDriveSet(joystickGetAnalog(1,2)/5);
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

		if (joystickGetDigital(1, 5, JOY_UP)) {
			intakeSet(127);
		} else {
			intakeSet(0);
		}

		if (joystickGetDigital(1, 5, JOY_DOWN)) {
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
