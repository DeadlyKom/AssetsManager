
                ifndef _CODE_KERNEL_MINIMAL_PACK_
                define _CODE_KERNEL_MINIMAL_PACK_

                MMU 2, Page.KernelMinimal
                module KernelMinimal
                DISP Adr.Interrupt

                display "\'Kernel minimal\':\t\t\t\t\t-------------------- [ ", /D, Size, " byte(s) ]\t\t[", /D, Page.KernelMinimal, "]\t ------------------------"
Begin:          EQU $

                ; interrupt
                include "Source/Interrupt/Include.inc"
                include "Source/Memory/Switch.asm"

                ; decompressor
                include "Source/Decompressor/Forward.asm"
                include "Source/Decompressor/Backward.asm"

                ; TR-DOS
                include "Source/TR-DOS/Include.inc"

                ; assets manager
                include "Source/AssetsManager/Include.inc"
End:            EQU $
Size:           EQU End-Begin
                ENT


                endmodule

                endif ; ~ _CODE_KERNEL_MINIMAL_PACK_
