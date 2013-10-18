/****************************************************************
  * Author: James Dunn
  * Created: Oct 10, 2013
  * Description: This C program will simulate a game of pong
  * given parameters for a ball and screen size
****************************************************************/

#include "msp430.h"
#include "pong.h"

void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	unsigned char volatile radius;
	int volatile xPosition, yPosition, xVelocity, yVelocity;
	pongBall_t pongBall;

	radius = 5;
	xPosition = 445;
	yPosition = 455;
	xVelocity = 10;
	yVelocity = 10;

	pongBall = createBall(xPosition, yPosition, xVelocity, yVelocity, radius);

	while(1)
	{
		pongBall = moveBall(pongBall);
	}
}
