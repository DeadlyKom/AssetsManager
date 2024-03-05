
                ifndef _CONST_MEMORY_MAP_PAGE_2_
                define _CONST_MEMORY_MAP_PAGE_2_

                ;   +-------+----------------------------+-------+
                ;   | #8000 |                  Int.Table | #0101 |
                ;   +-------+----------------------------+-------+
                ;   | #8101 |                 Init.Stack | #0080 |
                ;   +-------+----------------------------+-------+
                ;   | #8181 |                 Initerrupt |       |
                ;   +-------+----------------------------+-------+
                ;   |       |                     Kernel |       |
                ;   +-------+----------------------------+-------+
                ;   ....
                ;   +-------+----------------------------+-------+
                ;   | #BF00 |                ExtraBuffer | #0100 |
                ;   +-------+----------------------------+-------+

                module Page
KernelMinimal   EQU PAGE_2                                                      ; модуль "кернель" (минимальный)
Kernel          EQU PAGE_2                                                      ; модуль "кернель"
                endmodule

                module Size
Int.Table       EQU #0101                                                       ; размер таблицы прерываний
Int.Stack       EQU #0080                                                       ; размер стека прерывания
ExtraBuffer     EQU #0100                                                       ; размер дополнительного буфера
KernelMinimal   EQU Bootloader.KernelMinimal.Size                               ; размер блока кернела (минимальный)
                endmodule

                module Adr
Interrupt       EQU #8181                                                       ; адрес вектора прерывания
KernelMinimal   EQU Adr.Interrupt                                               ; адрес блока кернела (минимальный)
Kernel          EQU KernelMinimal + Size.KernelMinimal                          ; адрес блока кернела (основной)
ExtraBuffer     EQU #BF00                                                       ; адрес дополнительного буфера
Port_7FFD       EQU PORT_7FFD                                                   ; адрес хранения номера странички
AY.R7_Settings  EQU #7FFE                                                       ; адрес хранения настроек микшера AY
                endmodule

                endif ; ~_CONST_MEMORY_MAP_PAGE_2_
