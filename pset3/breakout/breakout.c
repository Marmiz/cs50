//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// space between briks
#define XSPACE  5
# define YSPACE 5

// briks dimensions
#define BH  15
#define BW  75

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;
    
    // click to start
    waitForClick();
        
    // ball speed
    double xspeed = drand48();
    double yspeed = 1.5;

    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        
        //scoreboard
        updateScoreboard(window, label, points);
        
        //move the ball
        move(ball, xspeed, yspeed);
        
        pause (10); 
        
        // collisions
        GObject object = detectCollision(window, ball);
        
        if (object != NULL)
        {
           // collision w paddle
           if (object == paddle)
           {
               yspeed = -yspeed;
           } 
           
           // collision w bricks
           else if (strcmp(getType(object), "GRect") == 0)
           {
               removeGWindow(window, object);
               yspeed = -yspeed;
               points = points +1;
 
           }
        
        }
        
        
        // when ball hit left wall
        if (getX(ball) <=0)
        {
            xspeed = -xspeed;
        }
        
        // when ball hit top wall
        if (getY(ball) <=0)
        {
            yspeed = -yspeed;
        }
        
        // when ball hit right wall
        if (getX(ball) + getWidth(ball) >=400)
        {
            xspeed = -xspeed;
        }
        
        // when ball hit bottom wall
        if (getY(ball) + getHeight(ball) >=600)
        {
            //loose a life
            lives = lives -1;
            //reset ball
            setLocation(ball, WIDTH /2 - RADIUS , HEIGHT / 2 + RADIUS);
            setLocation(paddle, 160, 500);
            waitForClick();
        }
        
        // check for mouse event
        GEvent event = getNextEvent(MOUSE_EVENT);
        // if we heard one
        if (event != NULL)
        {
            // if the event was movement
            if (getEventType(event) == MOUSE_MOVED)
            {
                // ensure circle follows top cursor
                double x = getX(event) - getWidth(paddle) / 2;
                double y = HEIGHT -100;
                setLocation(paddle, x, y);
            }
        }
        
        //if winning
        if(points ==25)
        {
            GLabel win = newGLabel ("You Win");
            setLocation(win, 15, 300);
            add(window, win);
           
        }
        
       
    }
    
    //if loosing
        if(lives ==0)
        {
            GLabel lose = newGLabel ("You Lose");
            setLocation(lose, 15, 300);
            add(window, lose);
        }

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    // create an array for rows and cols to loop over
    GRect rect[COLS][ROWS]; 
   
    // loop over the columns
    for (int i = 0; i < COLS; i++)
    {
       // loop over the rows
        for (int j = 0; j < ROWS; j++)
        {
            rect[i][j] = newGRect(BW * i + XSPACE * i + 1, 
            BH * j + YSPACE * j + 6 * BH, BW, BH);
          
            switch (i)
            {
                case 0:
                    setColor(rect[i][j], "BLUE");
                    break; 
            
                case 1:
                    setColor(rect[i][j], "RED");
                    break; 
              
                case 2:
                    setColor(rect[i][j], "ORANGE");
                    break; 
              
                case 3:
                    setColor(rect[i][j], "YELLOW");
                    break; 
               
                case 4: 
                    setColor(rect[i][j], "GREEN");
                    break; 
                
                default:
                    return; 
           }
         
            // add colors 
            setFilled((rect[i][j]), true);
            
            // show it in the canvas
            add(window, (rect[i][j])); 
          
       }
   }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    GOval ball = newGOval( WIDTH / 2 - RADIUS, HEIGHT / 2 + RADIUS, RADIUS * 2, RADIUS * 2 );
    setColor( ball, "black");
    setFilled (ball, true );
    add (window, ball);
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    // New GRect utilize paddle width(80) and height(12)
    GRect paddle = newGRect ((WIDTH / 2) - (80 / 2 ) , 500, 80, 12);
    setColor (paddle, "BLACK");
    setFilled (paddle, true);
    add (window, paddle);
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    GLabel label = newGLabel(" ");
    setColor(label, "GRAY");
    setFont(label, "SansSerif-40");
    add(window, label);
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
