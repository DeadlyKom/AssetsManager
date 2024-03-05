
                ifndef _STRUCT_LOCATION_32_
                define _STRUCT_LOCATION_32_

                struct FPNInt32
.Low            FValue
.High           FValue
                ends

                struct FLocation32
.X              FPNInt32
.Y              FPNInt32
                ends

                endif ; ~_STRUCT_LOCATION_32_
