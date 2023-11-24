#ifndef D_A_OBJ_GRYW00_H
#define D_A_OBJ_GRYW00_H

#include "f_op/f_op_actor.h"

class daObjGryw00_c : public fopAc_ac_c {
public:
    void get_draw_water_lv(void*);
    void setup_high_water_level_btk_anm();
    void particle_set();
    void particle_move();
    void particle_delete();
    void set_se();
    void CreateHeap();
    void Create();
    void Mthd_Create();
    void Delete();
    void Mthd_Delete();
    void switch_wait_act_proc();
    void spread_water_face_act_proc();
    void water_level_move_wait_act_proc();
    void anime_loop_start_wait_act_proc();
    void high_water_level_act_proc();
    void Execute(float(**)[3][4]);
    void Draw();

public:
    /* Place member variables here */
};

#endif /* D_A_OBJ_GRYW00_H */
