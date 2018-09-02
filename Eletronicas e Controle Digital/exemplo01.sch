EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:exemplo01-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CONN_01X02 J1
U 1 1 59222B22
P 5000 4450
F 0 "J1" H 5000 4600 50  0000 C CNN
F 1 "CONN_01X02" V 5100 4450 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_1x02_Pitch2.54mm" H 5000 4450 50  0001 C CNN
F 3 "" H 5000 4450 50  0001 C CNN
	1    5000 4450
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 59222B60
P 5950 4750
F 0 "C1" H 5975 4850 50  0000 L CNN
F 1 "C" H 5975 4650 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D5.0mm_W2.5mm_P2.50mm" H 5988 4600 50  0001 C CNN
F 3 "" H 5950 4750 50  0001 C CNN
	1    5950 4750
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 59222BB1
P 5950 4000
F 0 "R1" V 6030 4000 50  0000 C CNN
F 1 "R" V 5950 4000 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 5880 4000 50  0001 C CNN
F 3 "" H 5950 4000 50  0001 C CNN
	1    5950 4000
	1    0    0    -1  
$EndComp
$Comp
L LM741 U1
U 1 1 59222C10
P 6950 4550
F 0 "U1" H 6950 4800 50  0000 L CNN
F 1 "LM741" H 6950 4700 50  0000 L CNN
F 2 "Housings_DIP:DIP-8_W7.62mm_LongPads" H 7000 4600 50  0001 C CNN
F 3 "" H 7100 4700 50  0001 C CNN
	1    6950 4550
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 59222D0D
P 6150 4000
F 0 "R2" V 6230 4000 50  0000 C CNN
F 1 "R" V 6150 4000 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 6080 4000 50  0001 C CNN
F 3 "" H 6150 4000 50  0001 C CNN
	1    6150 4000
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 59222D81
P 6150 4750
F 0 "R3" V 6230 4750 50  0000 C CNN
F 1 "R" V 6150 4750 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 6080 4750 50  0001 C CNN
F 3 "" H 6150 4750 50  0001 C CNN
	1    6150 4750
	1    0    0    -1  
$EndComp
$Comp
L D D1
U 1 1 59222E1B
P 7550 4550
F 0 "D1" H 7550 4650 50  0000 C CNN
F 1 "D" H 7550 4450 50  0000 C CNN
F 2 "Diodes_THT:D_DO-15_P10.16mm_Horizontal" H 7550 4550 50  0001 C CNN
F 3 "" H 7550 4550 50  0001 C CNN
	1    7550 4550
	-1   0    0    1   
$EndComp
$Comp
L R R4
U 1 1 59222E56
P 7950 4750
F 0 "R4" V 8030 4750 50  0000 C CNN
F 1 "R" V 7950 4750 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 7880 4750 50  0001 C CNN
F 3 "" H 7950 4750 50  0001 C CNN
	1    7950 4750
	-1   0    0    1   
$EndComp
$Comp
L LED D2
U 1 1 59222E99
P 7950 5200
F 0 "D2" H 7950 5300 50  0000 C CNN
F 1 "LED" H 7950 5100 50  0000 C CNN
F 2 "LEDs:LED_D5.0mm" H 7950 5200 50  0001 C CNN
F 3 "" H 7950 5200 50  0001 C CNN
	1    7950 5200
	0    -1   -1   0   
$EndComp
NoConn ~ 6950 4850
NoConn ~ 7050 4850
Wire Wire Line
	5950 4150 5950 4600
Wire Wire Line
	6650 4450 5950 4450
Connection ~ 5950 4450
Wire Wire Line
	6150 4600 6150 4150
Wire Wire Line
	6150 4550 6650 4550
Wire Wire Line
	6650 4550 6650 4650
Connection ~ 6150 4550
Connection ~ 5950 3850
Wire Wire Line
	7250 4550 7400 4550
Wire Wire Line
	7700 4550 7950 4550
Wire Wire Line
	7950 4550 7950 4600
Wire Wire Line
	7950 4900 7950 5050
Wire Wire Line
	6850 3850 6850 4250
Connection ~ 6150 3850
Wire Wire Line
	7950 5350 7950 5750
Wire Wire Line
	6150 4900 6150 5100
Wire Wire Line
	5950 4900 5950 5100
Wire Wire Line
	4800 3850 6850 3850
Wire Wire Line
	4800 4400 4800 3850
$Comp
L PWR_FLAG #FLG01
U 1 1 59223CC7
P 4800 3850
F 0 "#FLG01" H 4800 3925 50  0001 C CNN
F 1 "PWR_FLAG" H 4800 4000 50  0000 C CNN
F 2 "" H 4800 3850 50  0001 C CNN
F 3 "" H 4800 3850 50  0001 C CNN
	1    4800 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 4500 4800 5100
Wire Wire Line
	4800 5100 7550 5100
Wire Wire Line
	7550 5100 7550 5750
Wire Wire Line
	7550 5750 7950 5750
Connection ~ 6150 5100
Connection ~ 5950 5100
$Comp
L PWR_FLAG #FLG02
U 1 1 5922416C
P 6850 4900
F 0 "#FLG02" H 6850 4975 50  0001 C CNN
F 1 "PWR_FLAG" H 6850 5050 50  0000 C CNN
F 2 "" H 6850 4900 50  0001 C CNN
F 3 "" H 6850 4900 50  0001 C CNN
	1    6850 4900
	-1   0    0    1   
$EndComp
Wire Wire Line
	6850 4850 6850 4900
$EndSCHEMATC
