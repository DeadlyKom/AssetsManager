                ifndef _MACRO_BASIC_
                define _MACRO_BASIC_
; -----------------------------------------
; отключение 128 Basic
; In:
; Out:
; Corrupt:
;   BC, AF
; -----------------------------------------
Disable_128k_Basic macro
                LD SP, (BASIC.ERR_SP)                                           ; ERR_SP
                LD HL, #1303                                                    ; MAIN_4
                EX (SP), HL
                RES 4, (IY + 1)                                                 ; FLAGS
                                                                                ; бит 4, используется только в 128К = 1 при новом ПЗУ, иначе 0
                LD BC, Adr.Port_7FFD
                LD A, ROM
                LD (BC), A
                OUT (C), A
                endm

                endif ; ~_MACRO_BASIC_
