
                ifndef _CONST_ASSETS_
                define _CONST_ASSETS_
ASSETS_ARCHIVE_BIT      EQU 0x00                                                ; флаг, архивности ресурса на диске
ASSETS_LOAD_BIT         EQU 0x01                                                ; флаг, загруженности ресурса в память
ASSETS_MARKED_BIT       EQU 0x07                                                ; флаг, помечен как невостребованный (в поле страницы адреса)
ASSETS_ALLOCATION_BIT   EQU 0x06                                                ; флаг, требуется аллокация ресурса
ASSETS_ARCHIVE          EQU 1 << ASSETS_ARCHIVE_BIT
ASSETS_EMPTY_ELEMENT    EQU 0xFF

                endif ; ~_CONST_ASSETS_
