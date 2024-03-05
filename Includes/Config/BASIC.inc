
                ifndef _CONFIG_ZX_SPECTRUM_BASIC_
                define _CONFIG_ZX_SPECTRUM_BASIC_

                module BASIC
LD_BYTES        EQU #0556                                                       ; 
ERR_NR          EQU #5C3A                                                       ; рег IY
ERR_SP          EQU #5C3D                                                       ; адрес элемента в стеке машины для использования в качестве возврата ошибки
                endmodule

                endif ; ~_CONFIG_ZX_SPECTRUM_BASIC_
