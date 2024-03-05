
                ifndef _CONST_MEMORY_MAP_PAGE_5_
                define _CONST_MEMORY_MAP_PAGE_5_

                ;   +-------+----------------------------+-------+
                ;   | #4000 |                     Screen | #1B00 |
                ;   +-------+----------------------------+-------+
                ;   | #5B00 |   Basic & TR-DOS variables | #033C |
                ;   +-------+----------------------------+-------+
                ;   | #5E3C |                      Stack | #00C4 |              ; стека
                ;   +-------+----------------------------+-------+
                ;   | #7380 |                 EntryPoint | #0080 |              ; точка входа
                ;   +-------+----------------------------+-------+
                
                module Page
                endmodule

                module Size
Stack           EQU #00C4                                                       ; размер стека
EntryPoint      EQU #0080                                                       ; размер точки входа
                endmodule

                module Adr
StackTop        EQU #5E3C + Size.Stack                                          ; расположение стека
EntryPoint      EQU #7380                                                       ; адрес точки входа

Booloader
.StackTop       EQU MemBank_03-2                                                ; расположение стека

Initialize:
.Memory         EQU #7E00                                                       ; место расположения блока кода, имнициализации памяти (временный код, для инициализации)
                endmodule

                endif ; ~_CONST_MEMORY_MAP_PAGE_5_
