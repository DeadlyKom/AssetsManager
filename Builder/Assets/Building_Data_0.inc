
                ifndef _BUILDING_ASSETS_DATA_0_
                define _BUILDING_ASSETS_DATA_0_

                if PASS = 2
                ; ASSETS_ID_KERNEL
                MMU 2, Page.Kernel
                ORG Adr.Kernel
                incbin "Builder/Assets/Code/Compressed/Kernel/Kernel.pack.ar"
                savetrd TRD_FILENAME, "Data-0.#", Adr.Kernel, $-Adr.Kernel

                ; ASSETS_ID_PAGE_0
                MMU 2, PAGE_0
                ORG Adr.Code.Page0
                incbin "Builder/Assets/Code/Compressed/Pages/Page0.pack.ar"
                savetrd TRD_FILENAME, &"Data-0.#", Adr.Code.Page0, $-Adr.Code.Page0

                endif
                endif ; ~_BUILDING_ASSETS_DATA_0_
