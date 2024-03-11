#ifndef D_A_ATT_H
#define D_A_ATT_H

#include "f_op/f_op_actor.h"
#include "SSystem/SComponent/c_phase.h"
#include "d/d_cc_d.h"

class att_class : public fopAc_ac_c {
public:
    /* 0x0290 */ request_of_phase_process_class mPhs;
    /* 0x0298 */ u8 m0298[0x02B8 - 0x0298];
    /* 0x02B8 */ dCcD_Stts mStts;
    /* 0x02F4 */ dCcD_Cyl mCyl;
    /* 0x0424 */ dCcD_Sph mSph;
    /* 0x0550 */ u8 m0550[4];
    // /* 0x0550 */ u32 m0550;
};

#endif /* D_A_ATT_H */
