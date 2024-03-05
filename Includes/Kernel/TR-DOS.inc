
                ifndef _KERNEL_INCLUDE_TR_DOS_
                define _KERNEL_INCLUDE_TR_DOS_
TRDOS:
.Startup        EQU Bootloader.KernelMinimal.TRDOS.Startup
.Shutdown       EQU Bootloader.KernelMinimal.TRDOS.Shutdown
.Jump3D13       EQU Bootloader.KernelMinimal.TRDOS.Jump3D13

                endif ; ~_KERNEL_INCLUDE_TR_DOS_
