
                ifndef _BUILDER_BOOTLOADER_
                define _BUILDER_BOOTLOADER_

                display "Basic :\t\t\t\t\t\t", /A, Begin, " = busy [ ", /D, Size, " byte(s)  ]"
; -----------------------------------------
; boot загрузчик
; In:
; Out:
; Corrupt:
; Note:
;   #5D40
; -----------------------------------------
Basic:          DB #00, #0A                                                     ; номер строки 10
                DW EndBoot-StartBoot+2                                          ; длина строки
                DB #EA                                                          ; команда REM
StartBoot:      DI
                Disable_128k_Basic                                              ; отключение 128 бейсика
                LD SP, Adr.Booloader.StackTop

                ; определение текущего адреса
                LD HL, #E9E1	                                                ; POP HL : JP (HL)
                EX (SP), HL	                                                    ; размещение 2х команд
                CALL Adr.Booloader.StackTop                                     ; в стек помещается адрес следующей команды,
                                                                                ; где выполняется POP HL : JP (HL)
                                                                                ; регистр HL хранит адрес следующей команды
                ; расчёт адреса хранения точки входа
                LD 	DE, Data.EntryPoint-$
                ADD	HL, DE
                LD 	DE, Adr.EntryPoint
                LD 	BC, Size.EntryPoint
                LDIR

                ; копирование блока инициализации памяти
                LD 	DE, Adr.Initialize.Memory
                LD 	BC, Memory.Size
                LDIR

                ; копирование минимального блока кернеля
                LD 	DE, Adr.Interrupt
                LD 	BC, KernelMinimal.Size
                LDIR

                CALL Adr.Initialize.Memory

                ; инициализация прерывания
                include "Source/Interrupt/Initialize.asm"

                ; инициализация ресурс менеджера
                include "Source/AssetsManager/Initialize.asm"

                ; отметить занятую область данными в доступной ОЗУ (принудительно)
                MARK_RAM Page.Kernel, Int.Table, Int.TableSize + \
                                                 Size.KernelMinimal             ; отметить минимальный кернель
                MARK_RAM PAGE_6, Adr.AssetsTable, Size.AssetsTable + \
                                                  Size.AvailableMem             ; отметить системные данные хранения ресурсов
                MARK_RAM PAGE_7, MemBank_03, BankSize                           ; отметить страницу памяти 7 занятой

                ; подготовка и загрузка кернеля
                SET_LOAD_ASSETS ASSETS_ID_KERNEL, Page.Kernel, Adr.Kernel
                LOAD_ASSETS ASSETS_ID_KERNEL

                ; вызов главной функции
                LD SP, Adr.StackTop
                JP Adr.EntryPoint
Data:
.EntryPoint     include "Source/EntryPoint/Include.inc"                         ; точка входа
.MemoryInit     include "Source/Memory/Initialize.asm"                          ; инициализация работы с памятью
.KernelMinimal  include "Builder/Assets/Code/Original/Kernel/Pack_KernelMinimal.inc" ; минимальный блок кода (не упакованный)
EndBoot:        DB #0D                                                          ; конец строки
                DB #00, #14                                                     ; номер строки 20
                DB #2A, #00                                                     ; длина строки 42 байта
                DB #F9                                                          ; RANDOMIZE
                DB #C0                                                          ; USE
                DB #28                                                          ; (
                DB #BE                                                          ; PEEK
                DB #B0                                                          ; VAL
                DB #22                                                          ; "
                DB #32, #33, #36, #33, #36                                      ; 23636
                DB #22                                                          ; "
                DB #2A                                                          ; *
                DB #32, #35, #36                                                ; 256
                DB #0E, #00, #00, #00, #01, #00                                 ; значение 256
                DB #2B                                                          ; +
                DB #BE                                                          ; PEEK
                DB #B0                                                          ; VAL
                DB #22                                                          ; "
                DB #32, #33, #36, #33, #35                                      ; 23635
                DB #22                                                          ; "
                DB #2B                                                          ; +
                DB #35                                                          ; 5
                DB #0E, #00, #00, #05, #00, #00                                 ; значение 5
                DB #29                                                          ; )
                DB #0D                                                          ; конец строки

                endif ; ~_BUILDER_BOOTLOADER_
