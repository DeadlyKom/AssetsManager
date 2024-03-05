
                ifndef _MACRO_FUNCTIONS_
                define _MACRO_FUNCTIONS_
; -----------------------------------------
; дальний вызов функции
; -----------------------------------------
CALL_FAR        macro Page?, Function?
                LD A, Page?
                LD HL, Function?
                CALL Func.CallFar
                endm

                endif ; ~_MACRO_FUNCTIONS_
