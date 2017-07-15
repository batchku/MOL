// the MIDI channel number to send messages
const int channel = 1; 

//Pot MIDI CC #s
//Three layers, 1+2 = loop layers, 3 = live layer 
//Broken const into: OPACITY, THRESH, SOFT, SCALE
const int POTCCs[]        = {0,16,102,18,
                             1,17,103,19,
                             7,23,22,20};

//Joystick MIDI CC #s                   
const int JOYCCs[]        = {30,31,
                             32,33};
 
//Button MIDI CC #s    
const int BTNCCs[]        = {64,32,48,0,
                             65,33,49,0,
                             66,34,50,0};
 
//Joystick Button MIDI CC #s                      
const int JBTNCCs[]       = {110,
                             111};
                   
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
//User LEDs MIDI CC #s (duplicate, also inside LEDCCs[])                     
const int USRCCs[]        = {72,
                             73,
                             74,
                             75};
