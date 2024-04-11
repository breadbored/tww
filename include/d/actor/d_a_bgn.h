#ifndef D_A_BGN_H
#define D_A_BGN_H

#include "f_op/f_op_actor.h"

struct part_s {
    /* 0x00 */ J3DModel* pModel;
};

struct move_s {
    
};

class bgn_class : public fopAc_ac_c {
public:
    /* 0x0290 */ u8 m0290[0xadb0 - 0x290];
    /* 0xADB0 */ u8 mADB0;
    /* 0xADB1 */ u8 mADB1[0xcc34 - 0xadb1];
    /* 0xCC34 */ u8 mCC34;
};

class daBgn_HIO_c {
public:
    daBgn_HIO_c();

public:
    /* Place member variables here */
};

#endif /* D_A_BGN_H */
