
                ifndef _ENTRY_POINT_
                define _ENTRY_POINT_
; -----------------------------------------
; точка входа
; In:
; Out:
; Corrupt:
; Note:
;   #7380
; -----------------------------------------
EntryPoint:     EI
                HALT
    
                ; инициализация
                JR$

                endif ; ~_ENTRY_POINT_
