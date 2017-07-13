#define NUM_MODS 3
#define NUM_POTS 12
#define NUM_BTNS 12
#define NUM_LEDS 16
#define NUM_USR 4
#define NUM_JOYPOTS 4
#define NUM_JOY_BTNS 2

const int channel = 1; // the MIDI channel number to send messages

int potPrevs[3][NUM_POTS]; //used to store previous values for pots
int potSends[NUM_POTS];


int joyPotPrevs[3][NUM_JOYPOTS]; //previous values for joysticks
int joyPotCenters[NUM_JOYPOTS]; //center value of joystick pots
int joyPotSends[NUM_JOYPOTS];

//...INPUTS...
// M = MOTOR
// S = SERVO
//JOYSTICK BUTTONS
const int M_JOY_BTN       = 0;
const int S_JOY_BTN       = 1;
//LED DRIVER PINS 1-7
const int L1              = 2;
const int L2              = 3;
const int L3              = 4;
const int L4              = 5;
const int L5              = 6;
const int L6              = 7;
const int L7              = 8;
//SERVO 1, 2 PWM PIN
const int S1              = 9;
const int S2              = 10;
//BUTTONS 1-2
const int BTN1            = 11;
const int BTN2            = 12;
// X = 13;
//TRIMPOT 1-3
const int POT1            = 14;
const int POT2            = 15;
const int POT3            = 16;
//MOTOR: JOYSTICK VERTICAL, HORIZONTAL
const int M_JOY_V         = 17;
const int M_JOY_H         = 18;
//SERVO: JOYSTICK VERTICAL, HORIZONTAL
const int S_JOY_V         = 19;
const int S_JOY_H         = 20;
//MOTOR: A, B PWM PIN
const int M_PWM_A         = 21;
const int M_PWM_B         = 22;
//LED DRIVER PIN 8
const int L8              = 23;
//BUTTONS 3-7
const int BTN3            = 24;
const int BTN4            = 25;
const int BTN5            = 26;
const int BTN6            = 27;
const int BTN7            = 28;
//LED DRIVER PIN 9-12
const int L9              = 29;
const int L10             = 30;
const int L11             = 31;
const int L12             = 32;
//TRIMPOT 4-7
const int POT4            = 33;
const int POT5            = 34;
const int POT6            = 35;
const int POT7            = 36;
//LED DRIVER PIN 10-11
//X Mistake
//const int L10 = 37;
//const int L11 = 38;
// TRIMPOT 8
const int POT8            = 39;
//MOTOR A, B DIRECTION
const int M_IN_A          = 40;
const int M_IN_B          = 41;
//BUTTONS 8-12
const int BTN8            = 42;
const int BTN9            = 43;
const int BTN10           = 44;
const int BTN11           = 45;
const int BTN12           = 46;
//I2C SCL,SDA
const int I2C_SCL         = 47;
const int I2C_SDA         = 48;
//LED DRIVER PIN 12
//X Mistake?
//const int L12 = 49;
//USER FEEDBACK 1-4
const int U1              = 51;
const int U2              = 52;
const int U3              = 53;
const int U4              = 54;
//TRIMPOT 9-12
const int POT9            = A21;
const int POT10           = A22;
const int POT11           = A10;
const int POT12           = A11;

//...ARRAYS...
const int POTS[]          = {POT1,
                             POT2,
                             POT3,
                             POT4,
                             POT5,
                             POT6,
                             POT7,
                             POT8,
                             POT9,
                             POT10,
                             POT11,
                             POT12};
//Pot MIDI CC #s
//Three layers, 1+2 = loop layers, 3 = live layer 
//Broken const into: OPACITY, THRESH, SOFT, SCALE
const int POTCCs[]        = {0,16,102,18,
                             1,17,103,19,
                             7,23,22,20};
                 
const int JOYPOTS[]       = {M_JOY_V,
                             M_JOY_H,
                             S_JOY_V,
                             S_JOY_H};
//Joystick MIDI CC #s                   
const int JOYCCs[]        = {30,31,
                             32,33};
                                      
const int BTNS[]          = {BTN1,
                             BTN2,
                             BTN3,
                             BTN4,
                             BTN5,
                             BTN6,
                             BTN7,
                             BTN8,
                             BTN9,
                             BTN10,
                             BTN11,
                             BTN12};
//Button MIDI CC #s    
const int BTNCCs[]        = {64,32,48,0,
                             65,33,49,0,
                             66,34,50,0};
             
const int JBTNS[]         = {M_JOY_BTN,
                             S_JOY_BTN};
//Joystick Button MIDI CC #s                      
const int JBTNCCs[]       = {110,
                             111};
                   
const int LEDS[]          = {L1,
                             L2,
                             L3,
                             L4,
                             L5,
                             L6,
                             L7,
                             L8,
                             L9,
                             L10,
                             L11,
                             L12,
                             U1,
                             U2,
                             U3,
                             U4};
                   
//LED MIDI CC #s                 
const int LEDCCs[]        = {60,
                             61,
                             65,
                             63,
                             64,
                             65,
                             62,
                             67,
                             68,
                             69,
                             70,
                             71,
                             72,
                             73,
                             74,
                             75};
                   
const int USR[]           = {U1,
                             U2,
                             U3,
                             U4};
//User LEDs MIDI CC #s (duplicate, also inside LEDCCs[])                     
const int USRCCs[]        = {72,
                             73,
                             74,
                             75};
