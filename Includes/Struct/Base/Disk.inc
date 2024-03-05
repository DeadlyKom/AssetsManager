
                ifndef _STRUCT_DISK_
                define _STRUCT_DISK_

                struct FDisk                                                    ; информация о данных на диске              [3 байта]
Sector          FValue                                                          ; начальный сектор
Size            DB #00                                                          ; размер на диске (в секторах)

                ends

                endif ; ~_STRUCT_DISK_
