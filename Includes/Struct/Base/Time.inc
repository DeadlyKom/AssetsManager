
                ifndef _STRUCT_TIME_
                define _STRUCT_TIME_

                struct FTime
Interrupt       DB #00                                                          ; BCD
Seconds         DB #00                                                          ; BCD
Minutes         DB #00                                                          ; BCD
Hour            DB #00                                                          ; BCD
Day             DB #00                                                          ; BCD
Month           DB #00                                                          ; BCD
Years           DW #0000                                                        ; 16-ричное значение
                ends

                endif ; ~_STRUCT_GAME_
