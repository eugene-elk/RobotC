#pragma config(Sensor, S1,     SLeft,               sensorReflection)
#pragma config(Sensor, S3,     SRight,              sensorReflection)
#pragma config(Motor,  motorA,          mA,            tmotorNormal, openLoop)
#pragma config(Motor,  motorC,          mC,            tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//*koeff for small wheels

task main()
{
  int err, errold, left, right, u, v;
  int motA, motB;
  v = 100;
  float k1 = 16; //P
  float k2 = 70.00;//D
  float k3 = 0.004;//K
  left = SensorValue[SLeft];
  right = SensorValue[SRight];
  errold = 0;
  while(true)
  {
    err = (SensorValue[SLeft]-left) - (SensorValue[SRight]-right);
    u = k1*err + k2*(err-errold)+k3*(err*err*err);
    motA = v + u;
    motB = v - u;
    if(motA > 100) motA = 100;
    if(motB > 100) motB = 100;
    if(motA < -100) motA = -100;
    if(motB < -100) motB = -100;
    motor[mA] = motA;
    motor[mC] = motB;

    wait1Msec(1);
    errold = err;
  }
}
