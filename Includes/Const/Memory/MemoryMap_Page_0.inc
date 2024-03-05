
                ifndef _CONST_MEMORY_MAP_PAGE_0_
                define _CONST_MEMORY_MAP_PAGE_0_

                ;   +-------+----------------------------+-------+
                ;   | #C000 |                            | #0000 |
                ;   +-------+----------------------------+-------+

                module Page
                endmodule

                module Size
                endmodule

                module Adr
Code.Page0      EQU MemBank_03                                                  ; адрес блока кода
                endmodule

                endif ; ~_CONST_MEMORY_MAP_PAGE_0_
