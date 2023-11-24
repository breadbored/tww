#ifndef D_A_OBJ_MKIE_H
#define D_A_OBJ_MKIE_H

#include "f_op/f_op_actor.h"

namespace daObjMkie {
    class Act_c : public fopAc_ac_c {
    public:
        void prm_make(unsigned char, int) {}
        void setup(const cXyz*) {}
    
        void CreateHeap();
        void init_cc();
        void set_cc_pos();
        void Create();
        void Mthd_Create();
        void Delete();
        void Mthd_Delete();
        void set_mtx();
        void init_mtx();
        void chk_light();
        void eff_break();
        void sound_melt();
        void sound_break();
        void vib_break();
        void mode_wait();
        void mode_demoWait_init();
        void mode_demoWait();
        void mode_demo_init();
        void mode_demo();
        void mode_proc_call();
        void Execute(float(**)[3][4]);
        void Draw();
    
    public:
        /* 0x290 */ u8 m290[0xF58 - 0x290];
        /* 0xF58 */ u8 mF58;
        /* 0xF59 */ u8 mF59[0xF64 - 0xF59];
    };
};

#endif /* D_A_OBJ_MKIE_H */
