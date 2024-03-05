
                ifndef _TR_DOS_INCLUDE_
                define _TR_DOS_INCLUDE_

                module TRDOS
Begin:          EQU $
                include "Startup.asm"
                include "Shutdown.asm"
                include "Jump3D12.asm"
Size            EQU $-Begin
                display " - TR-DOS:\t\t\t\t\t\t", /A, Begin, " = busy [ ", /D, Size, " byte(s)  ]"
                endmodule

                endif ; ~ _TR_DOS_INCLUDE_
