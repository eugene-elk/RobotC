
task main()
{
	TFileHandle hHandle;
 	TFileIOResult nResult = 0;
 	int iSize = 1000;
 	int mssg_out = 0;
 	hHandle = 0;
 	OpenRead(hHandle, nResult, "number.txt", iSize);
  ReadShort(hHandle, nResult, mssg_out);
  nxtDisplayTextLine(2, "%d", mssg_out);
  wait1Msec(2000);
}
