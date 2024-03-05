
                ifndef _TR_DOS_SHUTDOWN_
                define _TR_DOS_SHUTDOWN_
; -----------------------------------------
; завершение работы с TR-DOS
; In:
; Out:
; Corrupt:
; Note:
; -----------------------------------------
Shutdown:       DI
                IM 2
                EI

.ContainerIY    EQU $+2
                LD IY, #0000
                RET

                endif ; ~ _TR_DOS_SHUTDOWN_
