/*******************************************************
 * Filename: pong.h
 * Author: James Dunn
 * Date: Oct 14, 2013
 * Description: Implements a subset of the pong game
*******************************************************/

#ifndef _PONG_H
#define _PONG_H

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 500

//Pong Structures
typedef struct
{
    int x;
    int y;
} vector2d_t;

typedef struct
{
    vector2d_t position;
    vector2d_t velocity;
    unsigned char radius;
} pongBall_t;


// Pong Functions
pongBall_t createBall(int xPos, int yPos, int xVel, int yVel, unsigned char radius);
pongBall_t moveBall(pongBall_t movingBall);
//char collisionDetectionLeft (int xPosition, unsigned char radius);
//char collisionDetectionRight (int xPosition, unsigned char radius);
//char collisionDetectionTop (int yPosition, unsigned char radius);
//char collisionDetectionBottom (int yPosition, unsigned char radius);

#endif
