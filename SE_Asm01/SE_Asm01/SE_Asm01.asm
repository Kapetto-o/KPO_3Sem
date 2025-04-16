.586P                                                   ; система подкоманд (процессор Pentium)
.MODEL FLAT, STDCALL                                    ; модель памяти, соглашение о вызове
includelib kernel32.lib                                 ; компановщику: компоновать с kernel32

ExitProcess PROTO :DWORD                                ; прототип функции для завершения процесса Windows
MessageBoxA PROTO :DWORD, :DWORD, :DWORD, :DWORD        ; прототип API-функции MessageBoxA

.STACK 4096                                             ; выделение стека

.CONST                                                  ; сегмент констант

.DATA                                                   ; сегмент данных
MB_OK EQU 0                                             ; EQU определяет константу
STR1 DB "Моя первая программа", 0                       ; строка, первый элемент данные + нулевой бит
STR2 DB "Привет всем!", 0                               ; строка, первый элемент данные + нулевой бит
STR3 DB "Что у вас здесь происходит?", 0                ; строка для второго сообщения
HW DD ?                                                 ; двойное слово длиной 4 байта, неинициализировано

.CODE                                                   ; сегмент кода

main PROC                                               ; точка входа main
START:                                                  ; метка
        PUSH MB_OK
        PUSH OFFSET STR1
        PUSH OFFSET STR2
        PUSH HW
        CALL MessageBoxA                                ; вызов первой функции MessageBoxA

        INVOKE MessageBoxA, HW, OFFSET STR3, OFFSET STR1, MB_OK     ; Второе окно сообщения

        PUSH -1                                         ; код возврата процесса Windows (параметр ExitProcess)
        CALL ExitProcess                                ; конец процедуры
main ENDP

end main                                                ; конец модуля main
