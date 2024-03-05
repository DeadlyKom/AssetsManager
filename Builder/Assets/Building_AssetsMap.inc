
                ifndef _BUILDING_ASSETS_MAP_
                define _BUILDING_ASSETS_MAP_

                ORG 0x0000

                ; ASSETS_ID_KERNEL
                DB (Kernel.Size.Sector.ar << 1) | ASSETS_ARCHIVE                ; размер блока          (в секторах)
                DW Kernel.Size << 2                                             ; реальный размер блока (в байтах)
                display /D, ASSETS_ID_KERNEL,"  - Kernel\t\t\t\t[ original size: ", /D, Kernel.Size, " byte(s),\tdisk space: ", /D, Kernel.Size.Sector.ar, " sector(s) ]"

                ; ASSETS_ID_PAGE_0
                DB (Page0.Size.Sector.ar << 1) | ASSETS_ARCHIVE                ; размер блока          (в секторах)
                DW Page0.Size << 2                                             ; реальный размер блока (в байтах)
                display /D, ASSETS_ID_PAGE_0,"  - Page 0\t\t\t\t[ original size: ", /D, Page0.Size, " byte(s),\tdisk space: ", /D, Page0.Size.Sector.ar, " sector(s) ]"
                
Num             EQU $ / 3                                                       ; количество ресурсов а карте
Size            EQU (((Num % TRDOS.SECTOR_SIZE > 0) & 0x01) + (Num >> 8)) << 8  ; размер карты ресурсов (кратный 256)
Sector          EQU ((Size % TRDOS.SECTOR_SIZE > 0) & 0x01) + (Size >> 8)       ; размер карты ресурсов (в секторах)

                if PASS = 2
                savetrd TRD_FILENAME, "Resource.#", 0, Num*3
                endif

                endif ; ~_BUILDING_ASSETS_MAP_
