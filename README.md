# Simple Assembler Simulator
Simple Assembler Simulator has been developed to help the students of the "Elementi di Informatica e Programmazione" at the University of Brescia.

## The Assembly language

The Assembly language used is not a real language (e.g. as Intel ASM), its aim is to teach the fondamental concepts about the processor and its structure (memory, registers, etc.).

The table below can be used as reference to the language.

Instruction|How it works|Addressing mode
---|---|---|
LOADiL RX Val|RX<sub>1-8</sub> &#8592; Val|Register/Immediate with hex coding
LOADiH RX Val|RX<sub>9-16</sub> &#8592; Val|Register/Immediate with hex coding
ADD RX RY Val|RX &#8592; RY + Val|Register/Register/Immediate with hex coding
ADD RX RY RZ|RX &#8592; RY + RZ|Register/Register/Register with hex coding
SUB RX RY Val|RX &#8592; RY - Val|Register/Register/Immediate with hex coding
SUB RX RY RZ|RX &#8592; RY - RZ|Register/Register/Register with hex coding
MUL RX RY Val|RX &#8592; RY * Val|Register/Register/Immediate with hex coding
MUL RX RY RZ|RX &#8592; RY * RZ|Register/Register/Register with hex coding
MOVE RX RY|RX &#8592; RY|Register/Register
LOAD RX RY|RX &#8592; M[RY]|Register/Memory indirect through a register
STORE RX RY|M[RX] &#8592; RY|Memory indirect through a register/Register
BLT RX RY label|PC &#8592; label if RX < RY|Register/Register/Label
BLE RX RY label|PC &#8592; label if RX &le; RY|Register/Register/Label
BGT RX RY label|PC &#8592; label if RX > RY|Register/Register/Label
BGE RX RY label|PC &#8592; label if RX &ge; RY|Register/Register/Label
BEQ RX RY label|PC &#8592; label if RX = RY|Register/Register/Label
BNE RX RY label|PC &#8592; label if RX &ne; RY|Register/Register/Label
B label|PC &#8592; label |
END||
