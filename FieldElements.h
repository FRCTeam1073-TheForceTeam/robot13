#ifndef FIELD_ELEMENTS_H
#define FIELD_ELEMENTS_H

#define DISC_DIAMETER_FEET 1
#define DISC_DIAMETER_INCHES (12 * DISC_DIAMETER_FEET)

//field
#define LENGTH = (54 * 12)
#define WIDTH =  (27 * 12)

#define TOP_L_PYR_Y 122 //in
#define TOP_R_PYR_Y 122 //in
#define TOP_L_PYR_X 61
#define BOTTOM_PYR 216//in

#define BLUE_AUTO_LINE 216

#define CENTER_LINE 324

//Points of Feeder Zone
#define FEEDER_BOTTOM_X 0
#define FEEDER_BOTTOM_Y 87.94 //in Mandy did trig, assuming it's a 45-45-90

#define FEEDER_TOP_X (20 + FEEDER_BOTTOM_Y)
#define FEEDER_TOP_Y 0

#define TAPE_WIDTH 4

//left backboards are the saqme as the right backboard
#define LEFT_BACKBOARD_WIDTH 62


#define LEFT_BACKBOARD_BASE_POINT (84.625 + TAPE_WIDTH)

#define LEFT_BACK_BOARD_X (FEEDER_BOTTOM_X + 7.5 - TAPEWIDTH)	

#define TOP_GOAL_X 138.72

#define LINE_WIDTH 2 //thin lines

#endif
