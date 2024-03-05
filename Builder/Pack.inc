
                ifndef _BUILDER_PACK_
                define _BUILDER_PACK_

                if PASS = 2
                emptytrd TRD_FILENAME
                endif

                display "Packing..."

                include "Bootloader/Pack.inc"
                include "Assets/Packing.inc"

                display "-------------------------------------------------------------------------------------------------------------------------------"

                labelslist "D:/Work/spectrum/unreal/user.l"

                endif ; ~_BUILDER_PACK_
