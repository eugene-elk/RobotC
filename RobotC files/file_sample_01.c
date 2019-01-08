task main()
{
	TFileHandle hHandle;
	TFileIOResult nResult = 0;
	int iSize = 1000;

	Delete("number.txt", nResult);
	hHandle = 0;
	OpenWrite(hHandle, nResult, "number.txt", iSize);

	WriteShort(hHandle, nResult, 0);
}
