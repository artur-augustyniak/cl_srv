MinGW z g++ i msys.
Uruchomienie
console.exe path\to\endpoint.exe 127.0.0.1 11200

PROTO ---------------------------------------
1 byte type + payload
C: console
E: endpoint
--------------------
#send txt msg
C -> E
'M' n * byte(ascii char)

#end game ('zamknij')
C -> E terminate()
'T'

#random number ('losuj')
C - > E draw_random_number
'R'


