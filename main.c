//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Title: Robot Control Code
//	Team: Gondor
//	Authors: Jacob Wardell, Nathanael Neil, Patrick Walton, John Lyman
//	Revision: 0.0
//	Date: 3/21/2016
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <p24F16KA301.h>

/////////////////////////////////////////////////////////////////////
//        GLOBAL CONFIGURATION
/////////////////////////////////////////////////////////////////////

_FOSCSEL (FNOSC_FRC) 		  // Configure Oscillator

/////////////////////////////////////////////////////////////////////
//	GLOBAL VARIABLES
/////////////////////////////////////////////////////////////////////

int orientation = 0; 			// Orientation 
// 0 - None Specified
// 1 - Left
// 2 - Forward
// 3 - Right
// 4 - Backward

double x_location = 0;		// X Location and change in location
double old_delta_x = 0;		// Double for tracking distance measured by distance finder. Used only during part 1 of initial location calibration routine.
double new_delta_x = 0; 

double y_location = 0;		// Y Location and change in location
double old_delta_y = 0;		// Double for tracking distance measured by distance finder. Used only during part 2 of initial location calibration routine.
double new_delta_y = 0;

int num_balls = 0;		  	// Number of balls currently in the hopper.

int active_goal = 0;			// Active goal tracker.
			                    // 0 - None Specified
                          // 1 - Left
                          // 2 - Forward
                          // 3 - Right

/////////////////////////////////////////////////////////////////////
//       FUNCTION DECLARATIONS
/////////////////////////////////////////////////////////////////////

void config_IO(void) { 				                         // Configure Input and Output Pins

//////John, you’ve been keeping track of the pinout. Can you place all of the pin configurations in this function?/////

}

void config_ad(void) {			                          // Configure Analog to Digital
//////Nathanael, Jacob, or John, can you configure the necessary AD pins in this function?//////
}

void config_timer(void) {			                      	// Configure timers.
//////Nathanael, Jacob, or John, can you configure the necessary timers in this function?//////
}

void config_pwm(void) {	                          		// Configure Pulse Width Modulation
//////Nathanael, Jacob, or John, can you configure the necessary pwm in this function?//////
}

double distance(void) {			                        	// Distance function. Checks the AD pin reading the voltage and outputs the distance in inches.
	double cm_to_in = 0.393701;
  //V = (ADC1BUF0 /4095 ) * 3.3				                // Read in voltage from AD1.
  //return  cm_to_in * (27.297 * V ^ (-1.214))	      // 27.297 * V ^ (-1.214) is the conversion function determined by finding an exponential fit for the data from figures 4-5 in the GP2Y0A21YK data sheet.
}

void stop_wheels(void) {
//////Nathanael can you fill out this function?/////
{

void rotate_CW(double degrees) {
//////Nathanael can you fill out this function?/////
}

void rotate_CCW(double degrees) {
//////Nathanael can you fill out this function?/////
}

void find_x_center(void) {
//////Patrick will do this//////
}

void find_y_center(void) {
/////Patrick will do this///////
}

/////////////////////////////////////////////////////////////////////
//  INTERRUPT SERVICE ROUTINES
/////////////////////////////////////////////////////////////////////

//Balls Run Out
void __attribute__((interrupt, no_auto_psv)) _CNInterrupt(void) {

}

//Active Goal Changes
void __attribute__((interrupt, no_auto_psv)) _CNInterrupt(void) {

}

//Wheels Stop
void __attribute__((interrupt, no_auto_psv)) _CNInterrupt(void) {

}

/////////////////////////////////////////////////////////////////////
//      	            MAIN 
/////////////////////////////////////////////////////////////////////

int main() {

config_IO();
	config_ad();
	config_timer();
	config_pwm();

	while(1) {	
 }

	return 0;

}

