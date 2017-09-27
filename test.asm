#Exercise 2 from http://chronus.ing.unibs.it/didattica/eip/hardware-e-sistema-operativo/

#Preload
LOADiH R1 0x00 
LOADiL R1 0x64 
LOADiH R2 0x03 
LOADiL R2 0xE6 
LOADiH R3 0x00 
LOADiL R3 0x01 
CARICA: STORE R1 R3
ADD R3 R3 0x1
ADD R1 R1 0x2
BLE R1 R2 CARICA

#The exercise begins here
LOADiL R1 0x64
       LOADiH R1 0x00
       LOADiL R2 0xE6
       LOADiH R2 0x03
       LOADiL R3 0xE8
       LOADiH R3 0x03
CICLO: LOAD R4 R1       
       STORE R3 R4
       ADD R1 R1 0x2
       ADD R3 R3 0x2
       PRINT R2
       BLE R1 R2 CICLO
       PRINT 0x490
FINE:  END