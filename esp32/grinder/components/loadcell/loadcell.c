#include "loadcell.h"
#include "hx711.h"

void init_loadcell(loadcell_id_t id)
{
    int dout_pin;
    int sck_pin;
    if(id == LOADCELL_1){
        dout_pin = 1;
        sck_pin = 2;
        init_hx711(dout_pin, sck_pin);
    }
}