
                ifndef _KERNEL_INCLUDE_MEMORY_
                define _KERNEL_INCLUDE_MEMORY_
Memcpy:
.FromPage       EQU Kernel.Memcpy.FromPage                                      ; копирование данных из страницы находясь в иной страничке
.BetweenPages   EQU Kernel.Memcpy.BetweenPages                                  ; копирование большого блока между страничками, через буфер
.FastLDIR       EQU Kernel.Memcpy.FastLDIR                                      ; копирование данных

SafeFill:                                                                       ; заполнение блока памяти
.Screen         EQU Kernel.Memset.SafeFill_Screen
.b4096          EQU Kernel.Memset.SafeFill_4096
.b2048          EQU Kernel.Memset.SafeFill_2048
.b1024          EQU Kernel.Memset.SafeFill_1024
.b768           EQU Kernel.Memset.SafeFill_768
.b512           EQU Kernel.Memset.SafeFill_512
.b256           EQU Kernel.Memset.SafeFill_256
.b192           EQU Kernel.Memset.SafeFill_192
.b128           EQU Kernel.Memset.SafeFill_128
.b64            EQU Kernel.Memset.SafeFill_64
.b32            EQU Kernel.Memset.SafeFill_32

                endif ; ~_KERNEL_INCLUDE_MEMORY_
