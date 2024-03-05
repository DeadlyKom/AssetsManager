
                ifndef _TR_DOS_STARTUP_
                define _TR_DOS_STARTUP_
; -----------------------------------------
; настройка перед запуском TR-DOS
; In:
; Out:
; Corrupt:
; Note:
; -----------------------------------------
Startup:        ; сохранение IY
                LD (Shutdown.ContainerIY), IY
                
                ; настройка дефолтных переменных TR-DOS
                LD IY, BASIC.ERR_NR
                LD A, #FF
                LD (BASIC.ERR_NR), A                                            ; отсутствие ошибок BASIC
                LD (TRDOS.BUFF_FLAG), A                                         ; отключение выделения буфера ввода/вывода
                LD (TRDOS.DRIVE_A), A                                           ; 80 дорожечный, двухсторонний дисковод
                LD A, #C9
                LD (TRDOS.WITH_RET), A                                          ; востановление RET

                DI
                IM 1
                RET

                endif ; ~ _TR_DOS_STARTUP_
