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

_FOSCSEL (FNOSC_FRC) 		// Configure 8 MHz Oscillator
// (FNOSC_LPRC) 		// Configure 31 KHz Oscillator
//_FOSCSEL (FNOSC_FRCDIV) 	// Configure 8 MHz Oscillator w/ Postscaler
//_FOSCSEL (FNOSC_LPFRCDIV) 	// Configure 31 KHz Oscillator w/ Postscaler

/////////////////////////////////////////////////////////////////////
//	GLOBAL VARIABLES
/////////////////////////////////////////////////////////////////////

int orientation = 0; 		// Orientation 
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

int num_balls = 0;		// Number of balls currently in the hopper.

int active_goal = 0;		// Active goal tracker.
			        // 0 - None Specified
                          	// 1 - Left
                          	// 2 - Forward
                          	// 3 - Right
                          	
double L = 47.0;			//Arena length in x and y. Measured in inches.

double centering_tolerance = 0.25;	//Tolerance on centering routine. Measured in inches.

/////////////////////////////////////////////////////////////////////
//       FUNCTION DECLARATIONS
/////////////////////////////////////////////////////////////////////

void config_IO(void) { 				                         // Configure Input and Output Pins
	//////John, you’ve been keeping track of the pinout. Can you place all of the pin configurations in this function?/////
}

void config_ad(void);		                			// Configure Analog to Digital
	//Pins: 2, 3, 4, 5, 6, 7, 8, 9, 15, 16, 17, and 18
	const int ANALOG_PINS[] = {16};
	const int NUM_AN_PINS = 1;
	float read_ad(int pin); //returns voltage between 0V - 3.3V
	const float AD_SCALE = 4095.0; // 2^(Number of ADC bits) - 1


void config_timer(int timer, int prescale);			    	// Configure timers
//Timers: 1, 2, 3, 4, and 5
//Prescaler Values: 256, 64, 9, and 1

void config_timer_interrupt(int timer, int priority);			// Configure timer interrupt

void config_pwm(int pin, int timer, int period);			// Configure Pulse Width Modulation
//Pins: 4, 5, 14
//PWM Period = [Value + 1]*Tcy*(Prescaler Value)
//Tcy = 2/Fosc

void set_duty_cycle(int pin, float period, float duty_cycle);		// Duty cycle
//Use to set the duty cycle after config_pwm() has already been called

double distance(void) {			                        	// Distance function. Checks the AD pin reading the voltage and outputs the distance in inches.
	double cm_to_in = 0.393701;
  //V = (ADC1BUF0 /4095 ) * 3.3				                // Read in voltage from AD1.
  //return  cm_to_in * (27.297 * V ^ (-1.214))	      // 27.297 * V ^ (-1.214) is the conversion function determined by finding an exponential fit for the data from figures 4-5 in the GP2Y0A21YK data sheet.
}

void stop_wheels(void) {
	duty_cycle = 0;
{

void rotate_CW(double degrees) {
	//////Nathanael or John can you fill out this function?/////
}

void rotate_CCW(double degrees) {
	//////Nathanael or John can you fill out this function?/////
}

void drive_forward(double distance) {
	//////Nathanael or John can you fill out this function?/////
}

void drive_backward(double distance) {
	//////Nathanael or John can you fill out this function?/////
}

void shoot(void);	

void find_x_center(void) {
	//////Patrick will do this//////
}

void find_y_center(void) {
	/////Patrick will do this///////
}

double IR_magnitude(void) {
	V = (ADC1BUF3 /4095 ) * 3.3					//Returns the current IR diode magnitude in volts
}

void delay_s(double s);							//Uses timer1

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
	
//////////////////////////////////
//      Power-on Sequence
//////////////////////////////////

	//Find Ball Dispenser

	double new_IR_magnitude = 0;		//Variables for tracking IR magnitude when finding ball dispenser at beginning.
	double old_IR_magnitude1 = 0;
	double old_IR_magnitude2 = 0;

	while(new_IR_magnitude > old_IR_magnitude1 || old_IR_magnitude1 < old_IR_magnitude2) {
		//IR magnitudeing finding routine - Patrick will write this using IR magnitude function.
	}
	
	//Run Centering Routine
	
	while(y_location < L - centering_tolerance || L + centering tolerance < y_location) {
		//Centering Routine - Patrick will write this using drive functions.
	}

	while(1) {	
 }

	return 0;

}

float read_ad(int pin){
    switch(pin){
        case 2:
            return ADC1BUF0/AD_SCALE;
        case 3:
            return ADC1BUF1/AD_SCALE;
        case 4:
            return ADC1BUF2/AD_SCALE;
        case 5:
            return ADC1BUF3/AD_SCALE;
        case 6:
            return ADC1BUF4/AD_SCALE;
        case 7:
            return ADC1BUF13/AD_SCALE;
        case 8:
            return ADC1BUF14/AD_SCALE;
        case 9:
            return ADC1BUF15/AD_SCALE;
        case 15:
            return ADC1BUF12/AD_SCALE;
        case 16:
            return ADC1BUF11/AD_SCALE;
        case 17:
            return ADC1BUF10/AD_SCALE;
        case 18:
            return ADC1BUF9/AD_SCALE;
        default:
            return 0;                 
    }
}

void config_ad(void){
    _ADON = 0;    // AD1CON1<15> -- Turn off A/D
    // AD1CON1 register
    _MODE12 = 1;  // AD1CON1<10> -- 12-bit A/D operation
    _FORM = 0;    // AD1CON1<9:8> -- Unsigned integer output
    _SSRC = 7;    // AD1CON1<7:4> -- Auto conversion
    _ASAM = 1;    // AD1CON1<2> -- Auto sampling
    _ADSIDL = 0;  // AD1CON1<13> -- A/D continues in idle mode
    // AD1CON2 register
    _PVCFG = 0;   // AD1CON2<15:14> -- Use VDD as positive
    _NVCFG = 0;   // AD1CON2<13> -- Use VSS as negative
    _BUFREGEN = 1;// AD1CON2<11> -- Result appears in buffer
    _CSCNA = 1;   // AD1CON2<10> -- Scans inputs specified
    _SMPI = 3;	  // AD1CON2<6:2> -- Every 4th conversion sent
    _ALTS = 0;    // AD1CON2<0> -- Sample MUXA only
    // AD1CON3 register
    _ADRC = 0;    // AD1CON3<15> -- Use system clock
    _SAMC = 0;    // AD1CON3<12:8> -- Auto sample every A/D
    _ADCS = 0x3F; // AD1CON3<7:0> -- A/D period TAD = 64*TCY

    // AD1CSS registers
    int i;
    for(i = 0; i < NUM_AN_PINS; i++){
        switch(ANALOG_PINS[i]){
            case 2:
                _CSS0 = 1;
                break;
            case 3:
                _CSS1 = 1;
                break;
            case 4:
                _CSS2 = 1;
                break;
            case 5:
                _CSS3 = 1;
                break;
            case 6:
                _CSS4 = 1;
                break;
            case 7:
                _CSS13 = 1;
                break;
            case 8:
                _CSS14 = 1;
                break;
            case 9:
                _CSS15 = 1;
                break;
            case 15:
                _CSS12 = 1;
                break;
            case 16:
                _CSS11 = 1;
                break;
            case 17:
                _CSS10 = 1;
                break;
            case 18:
                _CSS9 = 1;                
        }
    }         
    _ADON = 1;    // AD1CON1<15> -- Turn on A/D
}

void config_timer(int timer, int prescale){
    switch(timer){
        case 1:
            if (prescale == 256)
                T1CON = 0b1000000000110000; 
            else if (prescale == 64)
                T1CON = 0b1000000000100000; 
            else if (prescale == 9)
                T1CON = 0b1000000000010000; 
            else
                T1CON = 0b1000000000000000;
            break;
        case 2:
            if (prescale == 256)
                T2CON = 0b1000000000110000; 
            else if (prescale == 64)
                T2CON = 0b1000000000100000; 
            else if (prescale == 9)
                T2CON = 0b1000000000010000; 
            else
                T2CON = 0b1000000000000000;
            break;
        case 3:
            if (prescale == 256)
                T3CON = 0b1000000000110000; 
            else if (prescale == 64)
                T3CON = 0b1000000000100000; 
            else if (prescale == 9)
                T3CON = 0b1000000000010000; 
            else
                T3CON = 0b1000000000000000;
            break;
        case 4:
            if (prescale == 256)
                T4CON = 0b1000000000110000; 
            else if (prescale == 64)
                T4CON = 0b1000000000100000; 
            else if (prescale == 9)
                T4CON = 0b1000000000010000; 
            else
                T4CON = 0b1000000000000000;
            break;
        case 5:
            if (prescale == 256)
                T5CON = 0b1000000000110000; 
            else if (prescale == 64)
                T5CON = 0b1000000000100000; 
            else if (prescale == 9)
                T5CON = 0b1000000000010000; 
            else
                T5CON = 0b1000000000000000;
            break;
    }
}

void config_timer_interrupt(int timer, int priority){
    switch(timer){
        case 1:
            _T1IP = priority;
            _T1IE = 1;
            _T1IF = 0;
        case 2:
            _T2IP = priority;
            _T2IE = 1;
            _T2IF = 0;
        case 3:
            _T3IP = priority;
            _T3IE = 1;
            _T3IF = 0;
        case 4:
            _T4IP = priority;
            _T4IE = 1;
            _T4IF = 0;
        case 5:
            _T5IP = priority;
            _T5IE = 1;
            _T5IF = 0;    
    }
}

void config_pwm(int pin, int timer, int period){
    switch(pin){
        case 4:
            OC2CON1bits.OCTSEL = 0b000;
            
            switch(timer){
                case 1:
                    OC2CON2bits.SYNCSEL = 0b01011;
                    PR1 = period;
                    break;
                case 2:
                    OC2CON2bits.SYNCSEL = 0b01100;
                    PR2 = period;
                    break;
                case 3:
                    OC2CON2bits.SYNCSEL = 0b01101;
                    PR3 = period;
                    break;
                case 4:
                    OC2CON2bits.SYNCSEL = 0b01110;
                    PR4 = period;
                    break;
                case 5:
                    OC2CON2bits.SYNCSEL = 0b01111;
                    PR5 = period;      
            }
            OC2CON1bits.OCM = 0b110;
            break;
        case 5:
            OC3CON1bits.OCTSEL = 0b000;
            switch(timer){
                case 1:
                    OC3CON2bits.SYNCSEL = 0b01011;
                    PR1 = period;
                    break;
                case 2:
                    OC3CON2bits.SYNCSEL = 0b01100;
                    PR2 = period;
                    break;
                case 3:
                    OC3CON2bits.SYNCSEL = 0b01101;
                    PR3 = period;
                    break;
                case 4:
                    OC3CON2bits.SYNCSEL = 0b01110;
                    PR4 = period;
                    break;
                case 5:
                    OC3CON2bits.SYNCSEL = 0b01111;
                    PR5 = period;       
            }
            OC3CON1bits.OCM = 0b110;
            break;
        case 14:
            OC1CON1bits.OCTSEL = 0b000;           
            switch(timer){
                case 1:
                    OC1CON2bits.SYNCSEL = 0b01011;
                    PR1 = period;
                    break;
                case 2:
                    OC1CON2bits.SYNCSEL = 0b01100;
                    PR2 = period;
                    break;
                case 3:
                    OC1CON2bits.SYNCSEL = 0b01101;
                    PR3 = period;
                    break;
                case 4:
                    OC1CON2bits.SYNCSEL = 0b01110;
                    PR4 = period;
                    break;
                case 5:
                    OC1CON2bits.SYNCSEL = 0b01111;                 
            }
            OC1CON1bits.OCM = 0b110;  
    }
}

void set_duty_cycle(int pin, float period, float duty_cycle){
    switch(pin){
        case 4:
            OC2R = period*duty_cycle/100.0;
            break;
        case 5:
            OC3R = period*duty_cycle/100.0;
            break;
        case 14:
            OC1R = period*duty_cycle/100.0;
    }
}

void delay_s(double s)
{
    int delay = (int)(100*s); //0.01 second res.
    COUNTS = 0;
    TMR1 = 0; //Clear timer 1
    T1CONbits.TON = 1; //Turn on timer
    while(COUNTS < delay);
    T1CONbits.TON = 0;
}

void __attribute__((interrupt, no_auto_psv)) _T1Interrupt(void)
{
	_T1IF = 0;
    	COUNTS++;
}

void shoot(void){
	_TRISB7 = 0;        	//Set pin 11 as output
    	_TRISB8 = 0;        	//Set pin 12 as output
	config_timer();
  	_RB7 = 0; 		//Set pin 11 low - Solenoid
	_RB8 = 0; 		//Set pin 12 low - DC Motor
	_RB8 = 1;
	delay_s(1);
	_RB7 = 1;
	delay_s(.25);
	_RB7 = 0;
	delay_s(.5);
	_RB7 = 1;
	delay_s(.25);
	_RB7 = 0;
	delay_s(.5);
	_RB7 = 1;
	delay_s(.25);
	_RB7 = 0;
	delay_s(.5);
	_RB7 = 1;
	delay_s(.25);
	_RB7 = 0;
	delay_s(.5);
	_RB7 = 1;
	delay_s(.25);
	_RB7 = 0;
	delay_s(.5);
	_RB7 = 1;
	delay_s(.25);
	_RB7 = 0;
	 delay_s(1);
	_RB8 = 0;
}

