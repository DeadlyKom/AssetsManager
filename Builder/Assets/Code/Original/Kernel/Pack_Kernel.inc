
                ifndef _CODE_KERNEL_PACK_
                define _CODE_KERNEL_PACK_

                ; - компиляция модуля

                MMU 2, Page.Kernel
                ORG Bootloader.KernelMinimal.End                                ; непонятно по какой причине компилятор меняет адреса Adr.Kernel
                module Kernel

                display "\'Kernel\':\t\t\t\t\t\t-------------------- [ ", /D, Size, "/", /D, Size + BufferSize/*размер кода и буферов*/, " byte(s) ]\t[", /D, Page.Kernel, "]\t ------------------------"
Begin:          EQU $

                ; memory
                include "Source/Memory/MemSet.asm"
                include "Source/Memory/MemcpyPages.asm"
                include "Source/Memory/MemcpyFastLDIR.asm"
Size:           EQU $-Begin                                                     ; размер кода

BufferSize:     EQU Size.ExtraBuffer + 0
                
                ifdef _REBUILD
                savebin "Builder/Assets/Code/Original/Kernel/Kernel.pack", Begin, Size
                shellexec "Tools\Compressor\salvador.exe -v Builder/Assets/Code/Original/Kernel/Kernel.pack Builder/Assets/Code/Compressed/Kernel/Kernel.pack.ar"
                ; shellexec "Tools\Compressor\zx0.exe -f Builder/Assets/Code/Original/Kernel/Kernel.pack Builder/Assets/Code/Compressed/Kernel/Kernel.pack.ar"
                endif

                ORG 0x0000
Begin.ar        incbin "Builder/Assets/Code/Compressed/Kernel/Kernel.pack.ar"
Size.ar         EQU $-Begin.ar
Size.Sector.ar  EQU ((Size.ar % TRDOS.SECTOR_SIZE > 0) & 0x01) + (Size.ar >> 8)

                endmodule

                endif ; ~ _CODE_KERNEL_PACK_
