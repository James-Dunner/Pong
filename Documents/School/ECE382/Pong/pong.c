/************************************************************
 * Filename: pong.c
 * Author: James Dunn
 * Created: Oct 14, 2013
 * Description: Source code for functions used in pong game
************************************************************/

#include "pong.h"

// Function Declarations
char collisionDetectionLeft (int xPosition, unsigned char radius);
char collisionDetectionRight (int xPosition, unsigned char radius);
char collisionDetectionTop (int yPosition, unsigned char radius);
char collisionDetectionBottom (int yPosition, unsigned char radius);

/************************************************************
 * Function Name: createBall
 * Author: James Dunn
 * Created: Oct 14, 2013
 * Description: Creates pong ball according to given parameters
************************************************************/
pongBall_t createBall(int xPos, int yPos, int xVel, int yVel, unsigned char radius)
{
	pongBall_t pongBall;

	pongBall.radius = radius;
	pongBall.position.x = xPos;
	pongBall.position.y = yPos;
	pongBall.velocity.x = xVel;
	pongBall.velocity.y = yVel;

	return pongBall;
}

/************************************************************
 * Function Name: moveBall
 * Author: James Dunn
 * Created: Oct 14, 2013
 * Description: Moves ball around the screen according to set parameters
************************************************************/
pongBall_t moveBall(pongBall_t movingBall)
{
	unsigned char volatile leftCollision, rightCollision, topCollision, bottomCollision;

	leftCollision = 0;
	rightCollision = 0;
	topCollision = 0;
	bottomCollision = 0;

	movingBall.position.x += movingBall.velocity.x;
	movingBall.position.y += movingBall.velocity.y;

	leftCollision = collisionDetectionLeft(movingBall.position.x, movingBall.radius);
	rightCollision = collisionDetectionRight(movingBall.position.x, movingBall.radius);
	topCollision = collisionDetectionTop(movingBall.position.y, movingBall.radius);
	bottomCollision = collisionDetectionBottom(movingBall.position.y, movingBall.radius);

	if (leftCollision || rightCollision)
	{
		movingBall.velocity.x = 0-movingBall.velocity.x;
	}

	if (topCollision || bottomCollision)
	{
		movingBall.velocity.y = 0-movingBall.velocity.y;
	}

	return movingBall;
}

/************************************************************
 * Function Name: collisionDetectionLeft
 * Author: James Dunn
 * Created: Oct 14, 2013
 * Description: Determines if ball collides with left wall
************************************************************/
char collisionDetectionLeft (int xPosition, unsigned char radius)
{
	char collisionDetector = 0;

	if (xPosition+radius <= 0)
	{
		collisionDetector = 1;
	}

	return collisionDetector;
}

/************************************************************
 * Function Name: collisionDetectionRight
 * Author: James Dunn
 * Created: Oct 14, 2013
 * Description: Determines if ball collides with right wall
************************************************************/
char collisionDetectionRight (int xPosition, unsigned char radius)
{
	char collisionDetector = 0;

	if (xPosition+radius >= SCREEN_WIDTH)
	{
		collisionDetector = 1;
	}

	return collisionDetector;
}

/************************************************************
 * Function Name: collisionDetectionTop
 * Author: James Dunn
 * Created: Oct 14, 2013
 * Description: Determines if ball collides with top wall
************************************************************/
char collisionDetectionTop (int yPosition, unsigned char radius)
{
	char collisionDetector = 0;

	if (yPosition+radius <= 0)
	{
		collisionDetector = 1;
	}

	return collisionDetector;
}

/************************************************************
 * Function Name: collisionDetectionBottom
 * Author: James Dunn
 * Created: Oct 14, 2013
 * Description: Determines if ball collides with bottom wall
************************************************************/
char collisionDetectionBottom (int yPosition, unsigned char radius)
{
	char collisionDetector = 0;

	if (yPosition+radius >= SCREEN_HEIGHT)
	{
		collisionDetector = 1;
	}

	return collisionDetector;
}
