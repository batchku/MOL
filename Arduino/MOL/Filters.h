#include <Bounce2.h>

int potPrevs[3][NUM_POTS]; //used to store previous values for pots
int potSends[NUM_POTS];


int joyPotPrevs[3][NUM_JOYPOTS]; //previous values for joysticks
int joyPotCenters[NUM_JOYPOTS]; //center value of joystick pots
int joyPotSends[NUM_JOYPOTS];

Bounce * joyButtDebouncer = new Bounce[NUM_JOY_BTNS]; // Create Bounce objects for each button.
Bounce * buttDebouncer = new Bounce[NUM_BTNS]; // Create Bounce objects for each button.