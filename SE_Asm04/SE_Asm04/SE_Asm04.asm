.586P
.MODEL FLAT, STDCALL
includelib kernel32.lib

ExitProcess PROTO : DWORD
.STACK 4096

.CONST

.DATA

TEXT	DB "YAG AFGAGH", 0
INTEGER	DD 161
.CODE

main PROC

START: 
	push 0
	call ExitProcess
main ENDP
end main
