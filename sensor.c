/*-----------------------------------------------------------------------| 
|  This C program polls the pin to indicate if an obstacle is present    |
|  or not, prints out ("Clear" or "Obstacle") in an infinite loop.       |
|                                                                        |
|  To Compile the program use the command below                          |
|  gcc  -Wall  -o sensor  sensor.c  -lwiringPi                           |
|                                                                        |
|  To Run the program use the below command :                            |
|   ./sensor                                                             |
|                                                                        |
|   OR                                                                   |
|                                                                        |
|   sudo  ./sensor                                                       |
|                                                                        |
|   Author : Avinash Sahoo                                               |
|------------------------------------------------------------------------*/

#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define LedPin    1  //output led signal to wiringPi pin#1(BCM#18)
#define SenPin    0  //input  sensor signal from wiringPi pin#0(BCM#17)

/* Signal Handler for SIGINT */
void sigintHandler(int sig_num) 
{ 
    signal(SIGINT, sigintHandler); 
    printf("\n Clean up and clearly terminating program using Ctrl+C \n"); 
    exit(0);
} 

int main(void)
{

  //Set the SIGINT (Ctrl-C) signal handler to sigintHandler
  signal(SIGINT, sigintHandler); 

  //We will check if the wiringPi setup is correctly or not
  if(wiringPiSetup() == -1)
  {
	printf("*** setup of wiringPi is not correct ****");
	exit(1);
  }

pinMode(LedPin,OUTPUT);
pinMode(SenPin,INPUT);

printf("\n");
printf("========================================\n");
printf("|        Ledpin is connected to wPi#1  |\n");
printf("|                                      |\n");
printf("|                                      |\n");
printf("|        SenPin is connected to wPi#0  |\n");
printf("========================================\n");
printf("\n");

while (1)
{
	if(!(digitalRead(SenPin)))
        {
		digitalWrite(LedPin, 1);
        	printf("\n");
		printf("*************** Clear *************** \n");
		printf("\n");
		delay(1000);
	}
	else
        {
		digitalWrite(LedPin, 0);
		delay(500);
		printf("\n");
		printf("*************** Obstacle *************** \n");
		printf("\n");
        }
}

return 0;

}

