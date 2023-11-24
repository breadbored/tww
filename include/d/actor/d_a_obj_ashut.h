#ifndef D_A_OBJ_ASHUT_H
#define D_A_OBJ_ASHUT_H

#include "f_op/f_op_actor.h"

namespace daObjAshut {
    class Act_c : public fopAc_ac_c {
    public:
        void CreateHeap();
        void Create();
        void Mthd_Create();
        void Delete();
        void Mthd_Delete();
        void set_mtx();
        void init_mtx();
        void chk_safe_area() const;
        void mode_upper_init();
        void mode_upper();
        void mode_u_l_init();
        void mode_u_l();
        void mode_lower_init();
        void mode_lower();
        void mode_l_u_init();
        void mode_l_u();
        void mode_demoreq_init(daObjAshut::Act_c::Mode_e);
        void mode_demoreq();
        void Execute(float(**)[3][4]);
        void Draw();
    
    public:
        /* Place member variables here */
    };
};

#endif /* D_A_OBJ_ASHUT_H */
