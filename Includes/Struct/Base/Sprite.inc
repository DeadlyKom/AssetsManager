
                ifndef _STRUCT_SPRITE_
                define _STRUCT_SPRITE_

                struct FSpriteData
; -----------------------------------------
;      7    6    5    4    3    2    1    0
;   +----+----+----+----+----+----+----+----+
;   | GM | .. | .. | .. | .. | P2 | P1 | P0 |
;   +----+----+----+----+----+----+----+----+
;
;   GM      [7]     - общая маска для спрайта
;   P2-P0   [2..0]  - страница хранения спрайта
; -----------------------------------------
Page            DB #00                                                          ; номер страницы
Data            DW #0000                                                        ; адрес спрайта (#C000 - #FFFF)

                ends


                struct FSpriteInfo
Height          DB #00                                                          ; высота спрайта                        (в пикселях)
OffsetY         DB #00                                                          ; SOy - смещение спрайта по вертикали   (в пикселях)
Width           DB #00                                                          ; ширина спрайта                        (в пикселях)
OffsetX         DB #00                                                          ; SOx - смещение спрайта по горизонтали (в пикселях)

                ends


                struct FSprite
Info            FSpriteInfo                                                     ; информация о спрайте
; -----------------------------------------
;      7    6    5    4    3    2    1    0
;   +----+----+----+----+----+----+----+----+
;   | O7 | O6 | O5 | O4 | O3 | O2 | O1 | O0 |
;   +----+----+----+----+----+----+----+----+
;
;   O7-O0   [7-0]   - смещение
; -----------------------------------------
Offset          DB #00                                                          ; адрес маски = адрес спрайта + FSprite.Offset
Data            FSpriteData                                                     ; данные расположения спрайта

                ends

                struct FCompositeSprite
Data            FSpriteData                                                     ; данные расположения спрайта
Dummy           DB #00                                                          ; 

                ends

                struct FCompositeSpriteInfo
; -----------------------------------------
;      7    6    5    4    3    2    1    0
;   +----+----+----+----+----+----+----+----+
;   | GM | S2 | S1 | D1 | D0 | A2 | A1 | A0 |
;   +----+----+----+----+----+----+----+----+
;
;   GM      [7]     - общая маска для спрайта
;   S2-S0   [6..4]  - размер спрайта
;                    00 - 16x16         (32 байта)
;                    01 - 16x32|32x16   (64 байта)
;                    10 -               (96 байт)
;                    11 - 32x32         (128 байт)
;   D1-D0   [4,3]   - 4 бит если 0, то LD/OR иначе OR & XOR вывод спрайта
;                    00 - LD
;                    01 - OR
;                    10 - OR & XOR
;                    11 - резерв
;   A2-A0   [2-0]   - количество анимаций
;                    000 - 0 анимаций
;                    001 - 1 анимация
;                    010 - 2 анимации
;                    011 - 3 анимации
;                    100 - 4 анимаций
;                    101 - 5 анимация
;                    110 - 6 анимации
;                    111 - 7 анимации
; -----------------------------------------
Flags           DB #00
AnimIDX         DB #00                                                          ; индекс элемента анимации
Info            FSpriteInfo                                                     ; информация о спрайте

                ends

                endif ; ~_STRUCT_SPRITE_