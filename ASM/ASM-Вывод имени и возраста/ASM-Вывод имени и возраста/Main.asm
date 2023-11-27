format PE console

entry start

include 'win32a.inc'

; ========== DATA SECTION ==========
section '.data' data readable writeable                     
    formatStr db '%s', 0
    formatNum db '%d', 0
                                                         
    name rd 2
    age rd 1
    
    hello db 'Hello! ', 0
    wiyn db 'What is your name? ', 0
    hoay db 'How old are you? ', 0
    hi db 'Hello, %s, your age is %d! ', 0
    
    NULL = 0

; ========== CODE SECTION ==========
section '.code' code readable executable

    start:
    
        push hello
        call [printf]
        
        push wiyn
        call [printf]
        
        push name
        push formatStr
        call [scanf]
        
        push hoay
        call [printf]
        
        push age
        push formatNum
        call [scanf]
        
        push [age]
        push name
        push hi
        call [printf]

        call [getch]
        
        push NULL
        call [ExitProcess]
        
; ========== IMPORT SECTION ==========
section '.idata' import data readable
    library kernel, 'kernel32.dll',\
            msvcrt, 'msvcrt.dll'
    
    import kernel,\
           ExitProcess, 'ExitProcess'
           
    import msvcrt,\
           printf,'printf',\
           getch, '_getch',\
           scanf, 'scanf'