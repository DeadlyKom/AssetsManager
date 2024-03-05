
                ifndef _MEMORY_SWITCH_
                define _MEMORY_SWITCH_

                module Memory
Begin:          EQU $
; -----------------------------------------
; установка страницы в 3 банк памяти (#C000-#FFFF)
; In:
;   A - номер страницы памяти (0-31)
; Out:
; Corrupt:
;   BC, AF, AF'
; Note:
;
;   порт 0xDFFD/0xFDFD  (0, 1)
;       RLCA
;       RLCA
;       AND %00000011
;       LD B, #DF/FD
;       OUT (C), A
;       RET
;
;   порт 1FFD           (4, 6)
;       RRCA
;       LD C, A
;       RRCA
;       XOR C
;       AND %00010000
;       XOR C
;       LD B, #1D
;       OUT (C), A
;       RET
; -----------------------------------------
SetPage:        ; порт 7FFD (0-2, 6,7)
                LD C, A
                ADD A, A    ; x2
                ADD A, A    ; x4
                ADD A, A    ; x8
                XOR C
                AND %11000000
                XOR C
                EX AF, AF'
                LD BC, Adr.Port_7FFD
                LD A, (BC)
                LD B, A
                EX AF, AF'
                XOR B
                AND PAGE_MASK
                XOR B
                LD B, HIGH Adr.Port_7FFD
Extended        LD (BC), A
                OUT (C), A
                RET
                DS 11, 0
SetPage0:       LD BC, Adr.Port_7FFD
                LD A, (BC)
                AND PAGE_MASK_INV
                JR Extended
SetPage1:       LD BC, Adr.Port_7FFD
                LD A, (BC)
                AND PAGE_MASK_INV
                INC A
                JR Extended
SetPage3:       LD BC, Adr.Port_7FFD
                LD A, (BC)
                AND PAGE_MASK_INV
                OR PAGE_3
                JR Extended
SetPage4:       LD BC, Adr.Port_7FFD
                LD A, (BC)
                AND PAGE_MASK_INV
                OR PAGE_4
                JR Extended
SetPage5:       LD BC, Adr.Port_7FFD
                LD A, (BC)
                AND PAGE_MASK_INV
.OR             OR PAGE_5
                JR Extended
SetPage6:       LD BC, Adr.Port_7FFD
                LD A, (BC)
                AND PAGE_MASK_INV
                OR PAGE_6
                JR Extended
SetPage7:       LD BC, Adr.Port_7FFD
                LD A, (BC)
                AND PAGE_MASK_INV
                OR PAGE_7
                JR Extended
; -----------------------------------------
; установка страницы видимого экрана
; In:
; Out:
; Corrupt:
;   BC, AF
; Note:
; -----------------------------------------
ScrPageToC000:  LD BC, Adr.Port_7FFD
                LD A, (BC)
                AND PAGE_MASK_INV
                BIT SCREEN_BIT, A
                JR Z, SetPage5.OR
                OR PAGE_7
                JR Extended
; -----------------------------------------
; установка страницы невидимого экрана
; In:
; Out:
; Corrupt:
;   BC, AF
; Note:
; -----------------------------------------
ScrPageToC000_: LD BC, Adr.Port_7FFD
                LD A, (BC)
                AND PAGE_MASK_INV
                BIT SCREEN_BIT, A
                JR NZ, SetPage5.OR
                OR PAGE_7
                JR Extended
; -----------------------------------------
; установка экрана расположенного в #C000
; In:
; Out:
; Corrupt:
;   BC, AF
; Note:
;   проверяется 1 бит, 
;   для 5 страницы равен 0
;   для 7 страницы равен 1
;   если будут другие страницы, ну сам дурак!
; -----------------------------------------
ScrFromPageC000 LD BC, Adr.Port_7FFD
                LD A, (BC)
                BIT 1, A
                RES SCREEN_BIT, A
                JR Z, Extended
                SET SCREEN_BIT, A
                JR Extended
; -----------------------------------------
; переключение экранов
; In:
; Out:
; Corrupt:
;   BC, AF
; Note:
; -----------------------------------------
SwapScreens:    LD BC, Adr.Port_7FFD
                LD A, (BC)
                XOR SCREEN
                LD (BC), A
                OUT (C), A
                RET
; -----------------------------------------
; отображение базового экрана
; In:
; Out:
; Corrupt:
;   BC, AF
; Note:
; -----------------------------------------
ShowBaseScreen: LD BC, Adr.Port_7FFD
                LD A, (BC)
                AND SCREEN_INV
                LD (BC), A
                OUT (C), A
                RET
; -----------------------------------------
; отображение теневого экрана
; In:
; Out:
; Corrupt:
;   BC, AF
; Note:
; -----------------------------------------
ShowShadowScreen: LD BC, Adr.Port_7FFD
                LD A, (BC)
                OR SCREEN
                LD (BC), A
                OUT (C), A
                RET
; -----------------------------------------
; получение текущего номера страницы
; In:
; Out:
;   A - номер страницы памяти (0-31)
; Corrupt:
;   AF
; Note:
; -----------------------------------------
GetPage:        PUSH HL
                LD HL, Adr.Port_7FFD
                LD A, (HL)
                RRA
                RRA
                RRA
                XOR (HL)
                AND %00011000
                XOR (HL)
                POP HL
                RET

                display " - Memory switch: \t\t\t\t\t", /A, Begin, " = busy [ ", /D, $ - Begin, " byte(s)  ]"
                endmodule

                endif ; ~_MEMORY_SWITCH_
