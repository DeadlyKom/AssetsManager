
                ifndef _MACRO_MEMORY_
                define _MACRO_MEMORY_
; -----------------------------------------
; включение страниц
; -----------------------------------------
SET_PAGE_0      macro
                CALL SetPage0
                endm
SET_PAGE_1      macro
                CALL SetPage1
                endm
SET_PAGE_2      macro
                CALL SetPage2
                endm
SET_PAGE_3      macro
                CALL SetPage3
                endm
SET_PAGE_4      macro
                CALL SetPage4
                endm
SET_PAGE_5      macro
                CALL SetPage5
                endm
SET_PAGE_6      macro
                CALL SetPage6
                endm
SET_PAGE_7      macro
                CALL SetPage7
                endm
; -----------------------------------------
; включение страницы первого экрана
; -----------------------------------------
SET_PAGE_SCREEN_BASE macro
                CALL SetPage5
                endm
JP_SCREEN_BASE  macro
                JP SetPage5
                endm
; -----------------------------------------
; отображение базового экрана
; -----------------------------------------
SHOW_BASE_SCREEN macro
                CALL Screen.ShowBase
                endm
JP_SHOW_BASE_SCREEN macro
                JP Screen.ShowBase
                endm
; -----------------------------------------
; установка страницы видимого экрана
; -----------------------------------------
SET_PAGE_BASE_SCREEN macro
                CALL Screen.SetPageBase
                endm
; -----------------------------------------
; включение страницы теневого экрана
; -----------------------------------------
SET_PAGE_SCREEN_SHADOW macro
                CALL SetPage7
                endm
JP_SET_PAGE_SCREEN_SHADOW macro
                JP SetPage7
                endm
; -----------------------------------------
; установка страницы невидимого экран
; -----------------------------------------
SET_PAGE_SHADOW_SCREEN macro
                CALL Screen.SetPageShadow
                endm
; -----------------------------------------
; включить экран находящийся в 3 банке (5 или 7 страница)
; -----------------------------------------
SHOW_SCREEN_FROM_PAGE_C000 macro
                CALL Screen.FromPageC000
                endm
; -----------------------------------------
; переключение экрана
; -----------------------------------------
SWAP_SCREEN     macro
                CALL Screen.Swap
                endm
; -----------------------------------------
; отображение теневого экрана
; -----------------------------------------
SHOW_SHADOW_SCREEN macro
                CALL Screen.ShowShadow
                endm
; -----------------------------------------
; установка страницы (0-31) и номер видимого экрана (0,1)
; -----------------------------------------
SetPort:        macro Page?, Screen?
                LD HL, Adr.Port_7FFD
                if Screen? = 0
                RES Screen?, (HL)
                else
                SET Screen?, (HL)
                endif
                LD A, Page?
                CALL SetPage
                endm
; -----------------------------------------
; сохранение номера страницы в стеке
; -----------------------------------------
PUSH_PAGE       macro
                ; -----------------------------------------
                ; получение текущего номера страницы
                ; In:
                ; Out:
                ;   A - номер страницы памяти (0-31)
                ; Corrupt:
                ;   AF
                ; Note:
                ; -----------------------------------------
                CALL GetPage                                                    ; получение текущей страницы исходника
                PUSH AF                                                         ; сохранение страницы в стеке
                endm
; -----------------------------------------
; восстановление номера страницы из стека
; -----------------------------------------
POP_PAGE        macro
                POP AF
                CALL SetPage
                endm
JP_POP_PAGE     macro
                JP Func.PopPage
                endm

                endif ; ~_MACRO_MEMORY_
