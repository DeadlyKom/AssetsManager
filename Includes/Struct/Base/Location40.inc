
                ifndef _STRUCT_LOCATION_40_
                define _STRUCT_LOCATION_40_

                struct FPNInt40
.Byte           DB #00
.Int            FPNInt32
                ends

                struct FLocation40
.X              FPNInt40
.Y              FPNInt40
                ends

                endif ; ~_STRUCT_LOCATION_40_
