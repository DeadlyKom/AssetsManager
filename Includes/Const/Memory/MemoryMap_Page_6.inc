
                ifndef _CONST_MEMORY_MAP_PAGE_6_
                define _CONST_MEMORY_MAP_PAGE_6_

                ;   +-------+------------------------------------------+-------+
                ;   | #С000 |                                          | #0000 |
                ;   +-------+------------------------------------------+-------+
                ;   | #С800 |                              AssetsTable | #0800 |
                ;   +-------+------------------------------------------+-------+
                ;   | #D000 |                             AvailableMem | #0100 |
                ;   +-------+------------------------------------------+-------+
                
                module Page
                endmodule

                module Size
AssetsTable     EQU FAssets * 256                                               ; размер таблицы ресурсов
AvailableMem    EQU MAX_PAGE * (BankSize >> 11)                                 ; размер битового массива доступного ОЗУ
                endmodule

                module Adr
AssetsTable     EQU #C800                                                       ; адрес таблицы ресурсов
AvailableMem    EQU AssetsTable + Size.AssetsTable                              ; адрес битового массива доступного ОЗУ
                endmodule

                endif ; ~_CONST_MEMORY_MAP_PAGE_6_
