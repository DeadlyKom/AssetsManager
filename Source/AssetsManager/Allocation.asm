
                ifndef _ASSETS_MANAGER_ALLOCATION_
                define _ASSETS_MANAGER_ALLOCATION_
; -----------------------------------------
; распределение ресурса
; In:
;   IX - адрес структуры FAssets
; Out:
;   A  - номер страницы (0-31)
;   HL - адрес непрерывной области ОЗУ (#C000-#FF00)
;   флаг переполнения установлен, если не удалось найти необходимого размера непрерывную область ОЗУ
; Corrupt:
;   HL, DE, BC, AF
; Note:
;   - необходимо включить страницу с данными о доступной ОЗУ
;   - если ресурс имеет флаг архива, выделить дополнительные временные 256 байт ОЗУ
; -----------------------------------------
Allocation:     ; -----------------------------------------
                ; преобразование размера ресурса в блоки по 256 байт
                ; In:
                ;   IX - адрес структуры FAssets
                ; Out:
                ;   A  - количество блоков по 256 байт
                ;   BC - реальный размер блока до 16кб
                ; Corrupt:
                ;   BC, AF
                ; -----------------------------------------
                CALL CalcSizeToBlock

                ; проверить флаг архивности ресурса (если ресурс имеет флаг архива, выделить дополнительные временные 256 байт ОЗУ)
                BIT ASSETS_ARCHIVE_BIT, (IX + FAssets.Flags)
                JR Z, $+3
                INC A
                EX AF, AF'                                                      ; сохранение результата количества блоков
                
                ; поиск свободной непрерывной области ОЗУ
                LD HL, Adr.AvailableMem
                LD C, #20                                                       ; количество страниц 16кб (максимум 512кб)

.RAM_All_Loop   LD D, #08                                                       ; D - количество байт для хранения 16кб
                EX AF, AF'
                LD E, A                                                         ; E - обнуление счётчика непрерывной области ОЗУ
                EX AF, AF'

.RAM_16_Loop    LD B, #08                                                       ; количество бит в байте
                LD A, (HL)

.RAM_Loop       ADD A, A
                JR NC, .IsFree                                                  ; переход, если область 256 байт свободна

                ; обнуление счётчика непрерывной области ОЗУ
                EX AF, AF'
                LD E, A
                EX AF, AF'
                JR .NextBit

.IsFree         ; проверка достаточности непрерывной области ОЗУ
                DEC E
                JR Z, .Found                                                    ; переход, если найден необходимый блок непрерывной области ОЗУ
.NextBit        DJNZ .RAM_Loop

                ; переход к следующим 2кб ОЗУ
                LD B, #08                                                       ; количество бит в байте
                INC L                                                           ; следующие 2кб
                DEC D                                                           ; уменьшение счётчика просматриваемой области ОЗУ (-2кб)
                JR NZ, .RAM_16_Loop

                ; переход к следующим 16кб ОЗУ
                DEC C                                                           ; уменьшение счётчика просматриваемой области ОЗУ (-16кб)
                JR NZ, .RAM_All_Loop

                SCF                                                             ; установка флага переполнения, не удалось найти подходящую область ОЗУ
                RET

.Found          ; найден необходимый блок непрерывной области ОЗУ

                ; преобразование счётчика к номеру бита
                EX AF, AF'
                DEC A
                ADD A, B
                DEC A
                CPL
                LD B, A

                ; расчёт первоночального адреса отсчёта свободных битов
                RRA
                RRA
                RRA
                CPL
                AND %00011111
                NEG
                ADD A, L

                ; расчёт адреса свободного блока
                ADD A, A    ; x2
                ADD A, A    ; x4
                ADD A, A    ; x8
                XOR B
                AND %11111000
                XOR B
                OR #C0
                LD H, A
                LD A, L
                RRA
                RRA
                RRA
                AND %00011111
                LD L, #00

                ; A - номер страницы
                ;
                ;      7    6    5    4    3    2    1    0
                ;   +----+----+----+----+----+----+----+----+
                ;   | 0  | 0  | 0  | A7 | A6 | A5 | A4 | A3 |
                ;   +----+----+----+----+----+----+----+----+
                ;
                ;   A7-A3   [4..0]      - страница памяти 16кб
                ;                         часть адреса хранения битовой маски
                ;   
                ; HL - адрес
                ;
                ;   +----+----+----+----+----+----+----+----+   +----+----+----+----+----+----+----+----+
                ;  | 15 | 14 | 13 | 12 | 11 | 10 |  9 |  8 |   |  7 |  6 |  5 |  4 |  3 |  2 |  1 |  0 |
                ;  +----+----+----+----+----+----+----+----+   +----+----+----+----+----+----+----+----+
                ;  | 1  | 1  | A2 | A1 | A0 | B2 | B1 | B0 |   | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 0  |
                ;  +----+----+----+----+----+----+----+----+   +----+----+----+----+----+----+----+----+
                ;
                ;   A2-A0   [13..11]    - адрес
                ;                         часть адреса хранения битовой маски
                ;   B2-B0   [10..8]     - адрес
                ;                         номер бита в байте (обратный)

                ; сохранение линейного адреса размещения ресурса
                LD (IX + FAssets.Address.Page), A
                LD (IX + FAssets.Address.Adr), HL

                RET

                endif ; ~ _ASSETS_MANAGER_ALLOCATION_
