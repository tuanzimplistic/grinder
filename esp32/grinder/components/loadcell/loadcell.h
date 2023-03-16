#ifndef __LOADCELL_H__
#define __LOADCELL_H__

typedef enum {
    LOADCELL_1,
    LOADCELL_2,
    LOADCELL_3
} loadcell_id_t;

void init_loadcell(loadcell_id_t id);

#endif