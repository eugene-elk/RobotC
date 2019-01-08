
task main()
{
	int num = 1;
	nxtDisplayCenteredBigTextLine(3, "%d", num);
	while(nNxtButtonPressed != 3)
	{
		if(nNxtButtonPressed == 2)
		{
			num -= 1;
			while(nNxtButtonPressed != -1) wait1Msec(1);
			nxtDisplayCenteredBigTextLine(3, "%d", num);
		}
		if(nNxtButtonPressed == 1)
		{
			num += 1;
			while(nNxtButtonPressed != -1) wait1Msec(1);
			nxtDisplayCenteredBigTextLine(3, "%d", num);
		}
		wait1Msec(1);
	}
	PlaySound(soundBeepBeep);
	string filename = "";
	string filename2 = "f_";
	string filename3 = ".txt";
	while (num > 0)
	{
		filename = filename + (char)((num % 10)  + 48);
		num = num / 10;
	}
	reverseChars(filename);
	filename = filename + filename3;
	filename2 = filename2 + filename;
	nxtDisplayCenteredBigTextLine(3, "%s", filename2);
	wait1Msec(4000);
}
