
                ifndef _CONFIG_ZX_SPECTRUM_AY_
                define _CONFIG_ZX_SPECTRUM_AY_

                module AY
; -----------------------------------------
;  тон канала A
;
;      15     14     13     12     11     10      9      8          7      6      5      4      3      2      1      0
;   +------+------+------+------+------+------+------+------+   +------+------+------+------+------+------+------+------+ 
;   | .... | .... | .... | .... | TP11 | TP10 |  TP9 |  TP8 |   |  TP7 |  TP6 |  TP5 |  TP4 |  TP3 |  TP2 |  TP1 |  TP0 |
;   +------+------+------+------+------+------+------+------+   +------+------+------+------+------+------+------+------+ 
;
;   TP7-TP0     [7-0]   - частота тона (младший)
; -----------------------------------------
R0              EQU 0x00
; -----------------------------------------
;  тон канала A
;
;   TP11-TP8    [11-8]  - частота тона (старший)
; -----------------------------------------
R1              EQU 0x01
; -----------------------------------------
;  тон канала B
;
;      15     14     13     12     11     10      9      8          7      6      5      4      3      2      1      0
;   +------+------+------+------+------+------+------+------+   +------+------+------+------+------+------+------+------+ 
;   | .... | .... | .... | .... | TP11 | TP10 |  TP9 |  TP8 |   |  TP7 |  TP6 |  TP5 |  TP4 |  TP3 |  TP2 |  TP1 |  TP0 |
;   +------+------+------+------+------+------+------+------+   +------+------+------+------+------+------+------+------+ 
;
;   T7-T0       [7-0]   - частота тона (младший)
; -----------------------------------------
R2              EQU 0x02
; -----------------------------------------
;  тон канала B
;
;   T11-T8      [11-8]  - частота тона (старший)
; -----------------------------------------
R3              EQU 0x03
; -----------------------------------------
;  тон канала C
;
;      15     14     13     12     11     10      9      8          7      6      5      4      3      2      1      0
;   +------+------+------+------+------+------+------+------+   +------+------+------+------+------+------+------+------+ 
;   | .... | .... | .... | .... | TP11 | TP10 |  TP9 |  TP8 |   |  TP7 |  TP6 |  TP5 |  TP4 |  TP3 |  TP2 |  TP1 |  TP0 |
;   +------+------+------+------+------+------+------+------+   +------+------+------+------+------+------+------+------+ 
;
;   TP7-PT0     [7-0]   - частота тона (младший)
; -----------------------------------------
R4              EQU 0x04
; -----------------------------------------
;  тон канала C
;
;   TP11-TP8    [11-8]  - частота тона (старший)
; -----------------------------------------
R5              EQU 0x05
; -----------------------------------------
;  частота шума
;
;      7    6    5    4    3    2    1    0
;   +----+----+----+-----+-----+-----+-----+-----+
;   | .. | .. | .. | NP4 | NP3 | NP2 | NP1 | NP0 |
;   +----+----+----+-----+-----+-----+-----+-----+
;
;   N4P-NP0     [4-0]   - частота шума
; -----------------------------------------
R6              EQU 0x06
; -----------------------------------------
;   управляющие флаги
;
;      7    6    5    4    3    2    1    0
;   +----+----+----+----+----+----+----+----+
;   | IB | IA | NC | NB | NA | TC | TB | TA |
;   +----+----+----+----+----+----+----+----+
;
;   IB          [7]     - флаг направление ввода/вывода канала B    (0 - ввод, 1 - вывод)
;   IA          [6]     - флаг направление ввода/вывода канала A    (0 - ввод, 1 - вывод)
;   NC          [5]     - флаг вкл/выкл шума канала C               (0 - вкл,  1 - откл)
;   NB          [4]     - флаг вкл/выкл шума канала B               (0 - вкл,  1 - откл)
;   NA          [3]     - флаг вкл/выкл шума канала A               (0 - вкл,  1 - откл)
;   TC          [2]     - флаг вкл/выкл тона канала C               (0 - вкл,  1 - откл)
;   TB          [1]     - флаг вкл/выкл тона канала B               (0 - вкл,  1 - откл)
;   TA          [0]     - флаг вкл/выкл тона канала A               (0 - вкл,  1 - откл)
; -----------------------------------------
R7              EQU 0x07
; -----------------------------------------
;   управление уровнем канала A
;
;      7    6    5    4    3    2    1    0
;   +----+----+----+----+----+----+----+----+
;   | .. | .. | .. |  M | L3 | L2 | L1 | L0 |
;   +----+----+----+----+----+----+----+----+
;
;   M           [4]     - выбор режима
;                           0 - фиксированная выходной уровень, управляется L3-L0
;                           1 - переменный выходной уровень, управляется из огибающей E4-E0
;   L3-L0       [3-0]   - громкость
; -----------------------------------------
R8              EQU 0x08
; -----------------------------------------
;   управление уровнем канала B
;
;      7    6    5    4    3    2    1    0
;   +----+----+----+----+----+----+----+----+
;   | .. | .. | .. |  M | L3 | L2 | L1 | L0 |
;   +----+----+----+----+----+----+----+----+
;
;   M           [4]     - выбор режима
;                           0 - фиксированная выходной уровень, управляется L3-L0
;                           1 - переменный выходной уровень, управляется из огибающей E4-E0
;   L3-L0       [3-0]   - громкость
; -----------------------------------------
R9              EQU 0x09
; -----------------------------------------
;   управление уровнем канала C
;
;      7    6    5    4    3    2    1    0
;   +----+----+----+----+----+----+----+----+
;   | .. | .. | .. |  M | L3 | L2 | L1 | L0 |
;   +----+----+----+----+----+----+----+----+
;
;   M           [4]     - выбор режима
;                           0 - фиксированная выходной уровень, управляется L3-L0
;                           1 - переменный выходной уровень, управляется из огибающей EP4-EP0
;   L3-L0       [3-0]   - громкость
; -----------------------------------------
R10             EQU 0x0A
; -----------------------------------------
;   частота огибающей
;
;      15     14     13     12     11     10      9      8          7      6      5      4      3      2      1      0
;   +------+------+------+------+------+------+------+------+   +------+------+------+------+------+------+------+------+ 
;   | EP15 | EP14 | EP13 | EP12 | EP11 | EP10 |  EP9 |  EP8 |   |  EP7 |  EP6 |  EP5 |  EP4 |  EP3 |  EP2 |  EP1 |  EP0 |
;   +------+------+------+------+------+------+------+------+   +------+------+------+------+------+------+------+------+ 
;
;   EP7-EP0     [7-0]   - тонкая регулировка
; -----------------------------------------
R11             EQU 0x0B
; -----------------------------------------
;   частота огибающей
;
;      15     14     13     12     11     10      9      8          7      6      5      4      3      2      1      0
;   +------+------+------+------+------+------+------+------+   +------+------+------+------+------+------+------+------+ 
;   | EP15 | EP14 | EP13 | EP12 | EP11 | EP10 |  EP9 |  EP8 |   |  EP7 |  EP6 |  EP5 |  EP4 |  EP3 |  EP2 |  EP1 |  EP0 |
;   +------+------+------+------+------+------+------+------+   +------+------+------+------+------+------+------+------+ 
;
;   EP15-EP8    [15-8]  - грубая регулировка
; -----------------------------------------
R12             EQU 0x0C
; -----------------------------------------
;   форма огибающей
;
;      7    6    5    4    3      2      1     0
;   +----+----+----+----+------+-----+-----+------+
;   | .. | .. | .. | .. | CONT | ATT | ALT | HOLD |
;   +----+----+----+----+------+-----+-----+------+
;   | .. | .. | .. | .. |   0  |  0  |  x  |   x  |     \_______
;   +----+----+----+----+------+-----+-----+------+
;   | .. | .. | .. | .. |   0  |  1  |  x  |   x  |     /|______
;   +----+----+----+----+------+-----+-----+------+
;   | .. | .. | .. | .. |   1  |  0  |  0  |   0  |     \|\|\|\|
;   +----+----+----+----+------+-----+-----+------+
;   | .. | .. | .. | .. |   1  |  0  |  0  |   1  |     \_______
;   +----+----+----+----+------+-----+-----+------+
;   | .. | .. | .. | .. |   1  |  0  |  1  |   0  |     \/\/\/\/
;   +----+----+----+----+------+-----+-----+------+
;   | .. | .. | .. | .. |   1  |  0  |  1  |   1  |     \|""""""
;   +----+----+----+----+------+-----+-----+------+
;   | .. | .. | .. | .. |   1  |  1  |  0  |   0  |     /|/|/|/|
;   +----+----+----+----+------+-----+-----+------+
;   | .. | .. | .. | .. |   1  |  1  |  0  |   1  |     /"""""""
;   +----+----+----+----+------+-----+-----+------+
;   | .. | .. | .. | .. |   1  |  1  |  1  |   0  |     /\/\/\/\
;   +----+----+----+----+------+-----+-----+------+
;   | .. | .. | .. | .. |   1  |  1  |  1  |   1  |     /\______
;   +----+----+----+----+------+-----+-----+------+
; -----------------------------------------
R13             EQU 0x0D
; -----------------------------------------
;   порт ввода/вывода A
; -----------------------------------------
R14             EQU 0x0E
; -----------------------------------------
;   порт ввода/вывода B
; -----------------------------------------
R15             EQU 0x0F

PORT_CTRL       EQU #FFFD
PORT_DATA       EQU #BFFD
PORTS_HIGH      EQU (HIGH PORT_CTRL << 8) | HIGH PORT_DATA
PORT_LOW        EQU #FD

TONE_A_BIT      EQU 0x0
TONE_B_BIT      EQU 0x1
TONE_C_BIT      EQU 0x2
NOISE_A_BIT     EQU 0x3
NOISE_B_BIT     EQU 0x4
NOISE_C_BIT     EQU 0x5

                endmodule

                endif ; ~_CONFIG_ZX_SPECTRUM_AY_
