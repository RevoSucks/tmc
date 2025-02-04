#include "global.h"
#include "entity.h"
#include "screen.h"
#include "functions.h"

extern void sub_08056250(void);
extern void sub_080570B8(Entity*);
void sub_080570F8(void);

extern void (*const gUnk_08107C5C[])(Entity*);
extern void (*const gUnk_08107C48[])(Entity*);

extern u8 gUnk_08107C40[];

void Manager1_Main(Entity* this) {
    u8 bVar1;
    u8* pbVar2;

    gUnk_08107C5C[this->action](this);
    gUnk_08107C48[((u8*)&this->field_0x20)[1]](this);
    bVar1 = gUnk_08107C40[((u8*)&this->field_0x20)[1]];
    if ((bVar1 != 0) && (*(u8*)&this->field_0x20 != bVar1)) {
        ((u8*)&this->field_0x20)[0] = bVar1;
        LoadGfxGroup(bVar1);
    }
}

void sub_080570B8(Entity* this) {
    u8* pbVar1;

    LoadGfxGroup(((u8*)&this->field_0x20)[0]);
    this->height.WORD = 0;
    pbVar1 = ((u8*)&this->field_0x20 + 1);
    if (*pbVar1 == 3) {
        gScreen.affine.bg3Updated = 1;
    } else {
        gUnk_08107C48[*pbVar1](this);
    }
}

void sub_080570F8(void) {
    gScreen.lcd.displayControl &= 0xf7ff;
    gScreen.controls.layerFXControl = 0;
    sub_08056250();
}

void sub_08057118(Entity* this) {
    this->actionDelay = 0;
    *(u8*)&this->field_0x20 = 0;
    ((u8*)&this->field_0x20)[1] = 0;
    ((u8*)&this->field_0x20)[2] = 0;
    this->action = 1;
    gScreen.affine.bg3Control = 0x1e04;
    gScreen.lcd.displayControl |= 0x800;
    gScreen.controls.layerFXControl = 0x3648;
    gScreen.controls.alphaBlend = 0x1000;
    sub_08052D74(this, sub_080570B8, sub_080570F8);
}

ASM_FUNC("asm/non_matching/manager1/sub_08057174.inc", void sub_08057174())

ASM_FUNC("asm/non_matching/manager1/sub_0805728C.inc", void sub_0805728C())

ASM_FUNC("asm/non_matching/manager1/sub_080572D4.inc", void sub_080572D4())

ASM_FUNC("asm/non_matching/manager1/sub_0805732C.inc", void sub_0805732C())

ASM_FUNC("asm/non_matching/manager1/nullsub_494.inc", void nullsub_494())

ASM_FUNC("asm/non_matching/manager1/sub_080573AC.inc", void sub_080573AC())

ASM_FUNC("asm/non_matching/manager1/sub_08057450.inc", void sub_08057450())
