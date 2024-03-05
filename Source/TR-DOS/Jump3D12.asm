
                ifndef _TR_DOS_JUMP_3D13_
                define _TR_DOS_JUMP_3D13_
; -----------------------------------------
; переход в TR-DOS
; In:
; Out:
; Corrupt:
; Note:
; -----------------------------------------
Jump3D13:       CALL Startup
                CALL TRDOS.EXE_CMD                                              ; переход в TR-DOS
                JP Shutdown

                endif ; ~ _TR_DOS_JUMP_3D13_
