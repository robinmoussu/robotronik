#include "common.h"


///! Les trames qui servent d'identificateur unique pour chacune des tourelles
    BIT_STOP = 0,
    BIT_START = 1,
    BIT_1 = 1,
    BIT_0 = 0
const Trame trame1 = {BIT_START,BIT_0,BIT_0,BIT_1,BIT_1,BIT_1,BIT_0,BIT_1,BIT_1,BIT_STOP};
const Trame trame2 = {BIT_START,BIT_0,BIT_0,BIT_0,BIT_1,BIT_1,BIT_1,BIT_0,BIT_1,BIT_STOP};
const Trame trame3 = {BIT_START,BIT_0,BIT_1,BIT_1,BIT_1,BIT_0,BIT_1,BIT_1,BIT_0,BIT_STOP};