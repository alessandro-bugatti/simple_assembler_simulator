#Exercise 3 from http://chronus.ing.unibs.it/didattica/eip/hardware-e-sistema-operativo/
       LOADiL R1 0x64
       LOADiH R1 0x00
       LOADiL R2 0x61
       LOADiH R2 0x00
       LOADiL R3 0x7A
       LOADiH R3 0x00
CICLO: STORE R1 R2
       ADD R2 R2 0x1
       ADD R1 R1 0x1
       BLE R2 R3 CICLO
FINE:  END