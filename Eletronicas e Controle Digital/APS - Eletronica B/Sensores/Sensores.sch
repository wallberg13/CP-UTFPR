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
LIBS:Sensores-cache
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
Text Label 1700 1850 0    60   ~ 0
-15V
Text Label 1700 1750 0    60   ~ 0
GND
Text Label 1700 1650 0    60   ~ 0
+15V
Text Label 1700 1150 0    60   ~ 0
5V
Text Label 1700 1050 0    60   ~ 0
OUT
Wire Wire Line
	1550 1050 1700 1050
Wire Wire Line
	1550 1150 1700 1150
Wire Wire Line
	1550 1650 1700 1650
Wire Wire Line
	1550 1750 1700 1750
Wire Wire Line
	1550 1850 1700 1850
$Comp
L TL082 U1
U 1 1 5922E037
P 3300 2400
F 0 "U1" H 3300 2600 50  0000 L CNN
F 1 "TL082" H 3300 2200 50  0000 L CNN
F 2 "Housings_DIP:DIP-8_W7.62mm_Socket_LongPads" H 3300 2400 50  0001 C CNN
F 3 "" H 3300 2400 50  0001 C CNN
	1    3300 2400
	1    0    0    -1  
$EndComp
$Comp
L TL082 U1
U 2 1 5922E076
P 5050 2500
F 0 "U1" H 5050 2700 50  0000 L CNN
F 1 "TL082" H 5050 2300 50  0000 L CNN
F 2 "Housings_DIP:DIP-8_W7.62mm_Socket_LongPads" H 5050 2500 50  0001 C CNN
F 3 "" H 5050 2500 50  0001 C CNN
	2    5050 2500
	1    0    0    -1  
$EndComp
$Comp
L LDR03 R1
U 1 1 5922E10B
P 2250 2100
F 0 "R1" V 2050 2100 50  0000 C CNN
F 1 "LDR03" V 2325 2100 50  0000 C TNN
F 2 "Opto-Devices:Resistor_LDR_10x8.5_RM7.6" V 2425 2100 50  0001 C CNN
F 3 "" H 2250 2050 50  0000 C CNN
	1    2250 2100
	1    0    0    -1  
$EndComp
$Comp
L R R1K1
U 1 1 5922E1DE
P 2250 2550
F 0 "R1K1" V 2330 2550 50  0000 C CNN
F 1 "R" V 2250 2550 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 2180 2550 50  0001 C CNN
F 3 "" H 2250 2550 50  0001 C CNN
	1    2250 2550
	1    0    0    -1  
$EndComp
$Comp
L POT_TRIM 100kTrip1
U 1 1 5922E366
P 5050 3450
F 0 "100kTrip1" V 4850 3350 50  0000 C CNN
F 1 "POT_TRIM" V 4950 3350 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Trimmer_Suntan_TSR-3386P_Horizontal" H 5050 3450 50  0001 C CNN
F 3 "" H 5050 3450 50  0001 C CNN
	1    5050 3450
	1    0    0    -1  
$EndComp
$Comp
L R R10k2
U 1 1 5922E466
P 4600 3450
F 0 "R10k2" V 4680 3450 50  0000 C CNN
F 1 "R" V 4600 3450 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 4530 3450 50  0001 C CNN
F 3 "" H 4600 3450 50  0001 C CNN
	1    4600 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 2500 2850 2500
Wire Wire Line
	2850 2500 2850 2900
Wire Wire Line
	2850 2900 3700 2900
Wire Wire Line
	3700 2900 3700 2400
Wire Wire Line
	3600 2400 3950 2400
Wire Wire Line
	2250 2250 2250 2400
Wire Wire Line
	3000 2300 2250 2300
Connection ~ 2250 2300
Text Label 2250 1850 0    60   ~ 0
5V
Wire Wire Line
	2250 1950 2250 1850
Text Label 2250 2800 0    60   ~ 0
GND
Wire Wire Line
	2250 2700 2250 2800
$Comp
L C C100n1
U 1 1 5922E78E
P 3350 1950
F 0 "C100n1" H 3375 2050 50  0000 L CNN
F 1 "C" H 3375 1850 50  0000 L CNN
F 2 "Capacitors_THT:C_Rect_L10.3mm_W5.0mm_P7.50mm_MKS4" H 3388 1800 50  0001 C CNN
F 3 "" H 3350 1950 50  0001 C CNN
	1    3350 1950
	0    1    1    0   
$EndComp
Wire Wire Line
	3200 1700 3200 2100
Wire Wire Line
	3500 1950 3600 1950
Text Label 3600 1950 0    60   ~ 0
GND
Connection ~ 3200 1950
Text Label 3200 1700 0    60   ~ 0
+15V
Wire Wire Line
	3200 2700 3200 3250
$Comp
L C C100n2
U 1 1 5922E970
P 3350 3050
F 0 "C100n2" H 3375 3150 50  0000 L CNN
F 1 "C" H 3375 2950 50  0000 L CNN
F 2 "Capacitors_THT:C_Rect_L10.3mm_W5.0mm_P7.50mm_MKS4" H 3388 2900 50  0001 C CNN
F 3 "" H 3350 3050 50  0001 C CNN
	1    3350 3050
	0    1    1    0   
$EndComp
Text Label 3600 3050 0    60   ~ 0
GND
Text Label 3200 3250 0    60   ~ 0
-15V
Connection ~ 3200 3050
Wire Wire Line
	3500 3050 3600 3050
$Comp
L R R10k1
U 1 1 5922EAAB
P 4100 2400
F 0 "R10k1" V 4180 2400 50  0000 C CNN
F 1 "R" V 4100 2400 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 4030 2400 50  0001 C CNN
F 3 "" H 4100 2400 50  0001 C CNN
	1    4100 2400
	0    1    1    0   
$EndComp
Connection ~ 3700 2400
Wire Wire Line
	4250 2400 4750 2400
Wire Wire Line
	4750 2600 4600 2600
Wire Wire Line
	4600 2600 4600 3300
Wire Wire Line
	5050 3300 5050 3200
Wire Wire Line
	5050 3200 4600 3200
Connection ~ 4600 3200
Wire Wire Line
	4600 3600 4600 3850
Wire Wire Line
	5050 3600 5050 3850
Wire Wire Line
	5050 3850 4600 3850
Wire Wire Line
	5200 3450 5550 3450
Wire Wire Line
	5550 3450 5550 2500
Wire Wire Line
	5350 2500 5750 2500
Connection ~ 5550 2500
Text Label 5750 2500 0    60   ~ 0
OUT
Text Label 4850 4050 0    60   ~ 0
GND
Wire Wire Line
	4850 3850 4850 4050
Connection ~ 4850 3850
$Comp
L PWR_FLAG #FLG01
U 1 1 592300DD
P 3150 1800
F 0 "#FLG01" H 3150 1875 50  0001 C CNN
F 1 "PWR_FLAG" H 3150 1950 50  0000 C CNN
F 2 "" H 3150 1800 50  0001 C CNN
F 3 "" H 3150 1800 50  0001 C CNN
	1    3150 1800
	0    -1   -1   0   
$EndComp
$Comp
L PWR_FLAG #FLG02
U 1 1 59230169
P 3100 3200
F 0 "#FLG02" H 3100 3275 50  0001 C CNN
F 1 "PWR_FLAG" H 3100 3350 50  0000 C CNN
F 2 "" H 3100 3200 50  0001 C CNN
F 3 "" H 3100 3200 50  0001 C CNN
	1    3100 3200
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3050 3200 3200 3200
Connection ~ 3200 3200
Connection ~ 3100 3200
Wire Wire Line
	3150 1800 3200 1800
Connection ~ 3200 1800
$Comp
L CONN_01X02 J1
U 1 1 592303FA
P 1350 1100
F 0 "J1" H 1350 1250 50  0000 C CNN
F 1 "CONN_01X02" V 1450 1100 50  0000 C CNN
F 2 "Connectors01:bornier2" H 1350 1100 50  0001 C CNN
F 3 "" H 1350 1100 50  0001 C CNN
	1    1350 1100
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X03 J2
U 1 1 5923046B
P 1350 1750
F 0 "J2" H 1350 1950 50  0000 C CNN
F 1 "CONN_01X03" V 1450 1750 50  0000 C CNN
F 2 "Connectors:bornier3" H 1350 1750 50  0001 C CNN
F 3 "" H 1350 1750 50  0001 C CNN
	1    1350 1750
	-1   0    0    1   
$EndComp
NoConn ~ 4950 2200
NoConn ~ 4950 2800
NoConn ~ 4500 1300
$EndSCHEMATC
