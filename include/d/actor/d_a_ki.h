#ifndef D_A_KI_H
#define D_A_KI_H

#include "f_op/f_op_actor.h"

class mDoExt_McaMorf;

class ki_class : public fopEn_enemy_c {
public:
    /* 0x2AC */ u8 m2AC[0x2B4 - 0x2AC];
    /* 0x2B4 */ mDoExt_McaMorf* mpMorf;
    /* 0x2B8 */ J3DPacket* mpPacket;
    /* 0x2BC */ u8 m2B8[0x2C8 - 0x2BC];
    /* 0x2C8 */ J3DModel* mpModel;
    /* 0x2CC */ u8 m2CC[0x932 - 0x2CC];
    /* 0x932 */ s16 m932;
    /* 0x934 */ u8 m934[0xF04 - 0x934];
};

#endif /* D_A_KI_H */
