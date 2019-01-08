#pragma config(Sensor, S1,     ,               sensorLightActive)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,          mB,            tmotorNXT, PIDControl, reversed, encoder)
#pragma config(Motor,  motorC,          mC,            tmotorNXT, PIDControl, reversed, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

const int MaxEnc = 9570;

ubyte data[100];
int time_to_run = 0;

int finish = 0;

int speed;

float x;
float t;

task bt()
{
	while(true)
	{
		while (cCmdMessageGetSize(mailbox1) < 1) wait1Msec(1);
		cCmdMessageRead(data, 2, mailbox1);
		time_to_run = (data[0] - 1) * 90;
		finish = data[1];
		wait1Msec(30);
	}
}

task preg()
{
	float k1 = 10;

	int u;

	ClearTimer(T1);
	while(true)
	{
		t = time100[T1]/10;
		x = MaxEnc*(t/time_to_run);

		if (t > time_to_run)
			break;

		speed = (x - nMotorEncoder[mB]);
		u = k1*(SensorValue[S1] - 45);
		motor[mB] = speed + u;
		motor[mC] = speed - u;
		wait1Msec(1);
	}

	speed = 100;

	while(true)
	{
		u = k1*(SensorValue[S1] - 45);
		motor[mB] = speed + u;
		motor[mC] = speed - u;
		wait1Msec(1);
	}
}

void end()
{
	nMotorEncoder[mB] = 0;
	motor[mB] = 100;
	motor[mC] = 100;
	while(nMotorEncoder[mB] < 3300) wait1Msec(10);
	motor[mB] = 0;
	motor[mC] = 0;
	PlaySound(soundBeepBeep);

	motor[mB] = 100;
	motor[mC] = -100;
	wait1Msec(10000);
}



task main()
{
	nMotorEncoder[mB] = 0;
	nMotorEncoder[mC] = 0;
	StartTask(bt);
	while (finish == 0) wait1Msec(1);
	StartTask(preg);
	while(true)
	{
		if ((finish == 2) || (nMotorEncoder[mB] > MaxEnc))
		{
			StopTask(preg);
			StopTask(bt);
			end();
			break;
		}
		nxtDisplayTextLine(1, "S: %d", speed);
		nxtDisplayTextLine(2, "B: %d", nMotorEncoder[mB]);
		nxtDisplayTextLine(3, "t: %d", time_to_run);
		nxtDisplayTextLine(4, "x: %f", x);
		nxtDisplayTextLine(5, "t: %f", t);
		wait1Msec(30);
	}
}
