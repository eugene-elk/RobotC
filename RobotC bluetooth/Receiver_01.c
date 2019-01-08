task main()
{
  int message_first;
  int message_second;
  int message_third;

  while(true)
  {
    //Read the messages to variables
      message_first = messageParm[0];
      message_second = messageParm[1];
      message_third = messageParm[2];

      //Something got through if the signals are not all zero
      if(message_first != 0 || message_second  != 0 || message_third != 0)
      {
          //display the values as stored in the variables
          nxtDisplayBigTextLine(2,"1: %d",message_first);
          nxtDisplayBigTextLine(4,"2: %d",message_second);
          nxtDisplayBigTextLine(6,"3: %d",message_third);

          //Clear the messages, set them to 0
          ClearMessage();
      }
      //Checking for a message every half a second is
      //fine for this simple test
      wait1Msec(500);

    }

}
