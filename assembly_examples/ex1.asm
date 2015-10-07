#Exercise 1 from http://chronus.ing.unibs.it/didattica/eip/hardware-e-sistema-operativo/      
       LOADiL R1 0x64
       LOADiH R1 0x00
       LOADiL R2 0xC6
       LOADiH R2 0x00
       LOADiL R3 0x00
       LOADiH R3 0x00
CICLO: ADD R3 R3 0x5       
       STORE R1 R3
       ADD R1 R1 0x2
       BLE R1 R2 CICLO
FINE:  END