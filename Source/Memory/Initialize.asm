
                ifndef _MEMORY_INITIALIZE_
                define _MEMORY_INITIALIZE_

                module Memory
                DISP Adr.Initialize.Memory
; -----------------------------------------
; инициализация работы с памятью
; In:
; Out:
; Corrupt:
; Note:
; -----------------------------------------
Initialize:     ; инициализация битового массива доступного ОЗУ (не доступно)
                LD HL, Adr.ExtraBuffer
                LD DE, Adr.ExtraBuffer+1
                LD BC, Size.AvailableMem-1
                LD (HL), #FF
                LDIR

                ; проверка порта 0x1FFD
                CALL _1FFD
                CP #09
                JR NC, _1FFD.Copy

                ; проверка порта 0x7FFD
                CALL _7FFD
                CP #09
                JR NC, .Continue                                                ; переход, если количество страниц больше 8

                ; проверка порта 0xDFFD
                CALL _DFFD
                CP #09
                JR NC, _DFFD.Copy
                
                ; проверка порта 0xFDFD
                CALL _FDFD
                CP #09
                JR NC, _FDFD.Copy

.Continue       ; ToDo добавить сохранение количество страниц в FGameConfig
                ; A - количество доступных страниц

                ; копирование битового массива доступного ОЗУ
                SET_PAGE_6                                                      ; включить страницу
                LD HL, Adr.ExtraBuffer
                LD DE, Adr.AvailableMem
                LD BC, Size.AvailableMem
                LDIR

                RET

.Address        EQU #FFFF
; -----------------------------------------
; проверка порта 0x1FFD
; In:
;   HL - адрес ячейки, для проверки переключения страниц
; Out:
;   A  - количество страниц
; Corrupt:
; Note:
; -----------------------------------------
_1FFD:          ; проверка порта 0x1FFD
                LD HL, SetPage_1FFD
                LD (CheckPort.Func_A), HL
                LD (CheckPort.Func_B), HL
                JP CheckPort
.Copy           LD HL, .Extended
                LD DE, SetPage.Extended+3                                       ; пропуск 2х байт (LD и OUT)
                LD BC, .Size
                LDIR
                JR Initialize.Continue
.Extended       ;   порт 1FFD           (4, 6)
                RRCA
                LD C, A
                RRCA
                XOR C
                AND %00010000
                XOR C
                LD B, #1D
                OUT (C), A
                RET
.Size           EQU $-.Extended
; -----------------------------------------
; проверка порта 0x7FFD
; In:
;   HL - адрес ячейки, для проверки переключения страниц
; Out:
;   A  - количество страниц
; Corrupt:
; Note:
; -----------------------------------------
_7FFD:          ; проверка порта 0x7FFD
                LD HL, SetPage_7FFD
                LD B, #7F
                LD (CheckPort.Func_A), HL
                LD (CheckPort.Func_B), HL
                JP CheckPort
; -----------------------------------------
; проверка порта 0xDFFD
; In:
;   HL - адрес ячейки, для проверки переключения страниц
; Out:
;   A  - количество страниц
; Corrupt:
; Note:
; -----------------------------------------
_DFFD:          ; проверка порта 0xDFFD
                LD HL, SetPage_DFFD
                LD (CheckPort.Func_A), HL
                LD (CheckPort.Func_B), HL
                JP CheckPort
.Copy           LD HL, .Extended
                LD DE, SetPage.Extended+3                                       ; пропуск 2х байт (LD и OUT)
                LD BC, .Size
                LDIR
                JR Initialize.Continue
.Extended       ; порт 0xDFFD           (0, 1)
                RLCA
                RLCA
                AND %00000011
                LD B, #DF
                OUT (C), A
                RET
.Size           EQU $-.Extended
; -----------------------------------------
; проверка порта 0xFDFD
; In:
;   HL - адрес ячейки, для проверки переключения страниц
; Out:
;   A  - количество страниц
; Corrupt:
; Note:
; -----------------------------------------
_FDFD:          ; проверка порта 0xFDFD
                LD HL, SetPage_FDFD
                LD (CheckPort.Func_A), HL
                LD (CheckPort.Func_B), HL
                JP CheckPort
.Copy           LD HL, .Extended
                LD DE, SetPage.Extended+3                                       ; пропуск 2х байт (LD и OUT)
                LD BC, .Size
                LDIR
                JR Initialize.Continue
.Extended       ; порт 0xFDFD           (0, 1)
                RLCA
                RLCA
                AND %00000011
                LD B, #FD
                OUT (C), A
                RET
.Size           EQU $-.Extended
; -----------------------------------------
; проверка порта 0xXXFD
; In:
;   HL - адрес ячейки, для проверки переключения страниц
; Out:
;   A  - количество страниц
; Corrupt:
; Note:
; -----------------------------------------
CheckPort       ; проверка порта
                LD HL, Initialize.Address
                LD C, #FD

                ; нумерация страниц
                LD D, MAX_PAGE

.Func_A         EQU $+1
.SetPage_Loop   CALL $

                DEC D
                LD (HL), D
                JR NZ, .SetPage_Loop

                ; проверка нумерации страниц
                XOR A
                EX AF, AF'
                LD D, MAX_PAGE

.Func_B         EQU $+1         
.CheckPage_Loop CALL $
                
                ; проверка разности значений номеров страниц
                LD A, (HL)
                INC A
                JR Z, .NextPage
                DEC A

                ; отметить свободные ячейки соответствующее странице ОЗУ
                PUSH HL
                LD H, HIGH Adr.ExtraBuffer
                ADD A, A    ; x2
                ADD A, A    ; x4
                ADD A, A    ; x8
                LD L, A
                XOR A
                LD (HL), A
                INC L
                LD (HL), A
                INC L
                LD (HL), A
                INC L
                LD (HL), A
                INC L
                LD (HL), A
                INC L
                LD (HL), A
                INC L
                LD (HL), A
                INC L
                LD (HL), A
                POP HL

                EX AF, AF'
                INC A
                LD (HL), #FF
                EX AF, AF'

.NextPage       DEC D
                JR NZ, .CheckPage_Loop
                EX AF, AF'

                RET
; -----------------------------------------
; установка страницы через порт 0x1FFD
; In:
;   D - обратный номер страницы (33-N)
;   C - младший номер порта FD
; Out:
; Corrupt:
;   AF
; Note:
;   256К/1024K Scorpion/KAY - используются 4, 6 биты порта #1FFD
; -----------------------------------------
SetPage_1FFD    LD A, MAX_PAGE
                SUB D
                LD E, A
                ADD A, A    ; x2
                XOR E
                AND %00110000
                XOR E
                ADD A, A    ; x4
                AND %01010000
                LD B, #1F
                OUT (C), A
                LD B, #7F
                JR SetPort_7FFD
; -----------------------------------------
; установка страницы через порт 0x7FFD
; In:
;   D  - обратный номер страницы (33-N)
;   BC - номер порта 7FFD
; Out:
; Corrupt:
;   AF
; Note:
;   512K - используются 6, 7 биты порта #7FFD
; -----------------------------------------
SetPage_7FFD    LD A, MAX_PAGE
                SUB D
                LD E, A
                ADD A, A    ; x2
                ADD A, A    ; x4
                ADD A, A    ; x8
                XOR E
                AND %11000000
                XOR E
                LD E, A
                JR SetPort_7FFD
; -----------------------------------------
; установка страницы через порт 0xDFFD
; In:
;   D - обратный номер страницы (33-N)
;   C - младший номер порта FD
; Out:
; Corrupt:
;   AF
; Note:
;   256К-1024К - используются 0, 1 биты порта #DFFD
; -----------------------------------------
SetPage_DFFD    LD A, MAX_PAGE
                SUB D
                LD E, A
                RRA
                RRA
                RRA
                AND %00000111
                LD B, #DF
                OUT (C), A
                LD B, #7F
                JR SetPort_7FFD
; -----------------------------------------
; установка страницы через порт 0xFDFD
; In:
;   D - обратный номер страницы (33-N)
;   C - младший номер порта FD
; Out:
; Corrupt:
;   AF
; Note:
;   512K - используются 0, 1 биты порта #FDFD
; -----------------------------------------
SetPage_FDFD    LD A, MAX_PAGE
                SUB D
                LD E, A
                RRA
                RRA
                RRA
                AND %00000111
                LD B, C
                OUT (C), A
                LD B, #7F
SetPort_7FFD    LD A, (BC)
                XOR E
                AND %00111000
                XOR E
                OUT (C), A
                RET
Size            EQU $-Initialize
                display " - Memory initialize:\t\t\t\t\t", /A, Initialize, " = busy [ ", /D, Size, " byte(s)  ]"
                ENT
                endmodule

                endif ; ~ _MEMORY_INITIALIZE_
