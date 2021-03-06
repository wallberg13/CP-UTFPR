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
L 6N136 U1
U 1 1 592F652B
P 2600 4100
F 0 "U1" H 2400 4400 50  0000 L CNN
F 1 "6N136" H 2600 4400 50  0000 L CNN
F 2 "Housings_DIP:DIP-8_W7.62mm_Socket_LongPads" H 2400 3800 50  0001 L CIN
F 3 "" H 2600 4100 50  0001 L CNN
	1    2600 4100
	1    0    0    -1  
$EndComp
$Comp
L R R2.2k1
U 1 1 592F669B
P 3150 3850
F 0 "R2.2k1" V 3230 3850 50  0000 C CNN
F 1 "R" V 3150 3850 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 3080 3850 50  0001 C CNN
F 3 "" H 3150 3850 50  0001 C CNN
	1    3150 3850
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X02 J1
U 1 1 592F679A
P 1450 4050
F 0 "J1" H 1450 4200 50  0000 C CNN
F 1 "CONN_01X02" V 1550 4050 50  0000 C CNN
F 2 "Connectors01:bornier2" H 1450 4050 50  0001 C CNN
F 3 "" H 1450 4050 50  0001 C CNN
	1    1450 4050
	-1   0    0    1   
$EndComp
$Comp
L R R330
U 1 1 592F6815
P 2050 4200
F 0 "R330" V 2130 4200 50  0000 C CNN
F 1 "R" V 2050 4200 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 1980 4200 50  0001 C CNN
F 3 "" H 2050 4200 50  0001 C CNN
	1    2050 4200
	0    1    1    0   
$EndComp
Wire Wire Line
	2200 4200 2300 4200
Wire Wire Line
	1900 4200 1650 4200
Wire Wire Line
	1650 4200 1650 4100
Wire Wire Line
	1650 4000 2300 4000
Text Label 1700 4000 0    60   ~ 0
PWM
Text Label 1650 4200 3    60   ~ 0
GND_PWM
Wire Wire Line
	3150 3700 3150 3650
Wire Wire Line
	3150 3650 2950 3650
Wire Wire Line
	3150 4000 3150 4200
Wire Wire Line
	2900 4200 3300 4200
NoConn ~ 2900 4000
$Comp
L CONN_01X02 J2
U 1 1 592F6B0C
P 3050 3050
F 0 "J2" H 3050 3200 50  0000 C CNN
F 1 "CONN_01X02" V 3150 3050 50  0000 C CNN
F 2 "Connectors01:bornier2" H 3050 3050 50  0001 C CNN
F 3 "" H 3050 3050 50  0001 C CNN
	1    3050 3050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3000 3250 3000 3300
Wire Wire Line
	3000 3300 2950 3300
Wire Wire Line
	2950 3300 2950 3900
Wire Wire Line
	2950 3900 2900 3900
Connection ~ 2950 3650
Wire Wire Line
	3100 3250 3100 3550
Wire Wire Line
	3100 3550 3050 3550
Wire Wire Line
	3050 3550 3050 4450
Wire Wire Line
	3050 4300 2900 4300
$Comp
L R R10k1
U 1 1 592F7004
P 3450 4200
F 0 "R10k1" V 3530 4200 50  0000 C CNN
F 1 "R" V 3450 4200 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 3380 4200 50  0001 C CNN
F 3 "" H 3450 4200 50  0001 C CNN
	1    3450 4200
	0    1    1    0   
$EndComp
Connection ~ 3150 4200
$Comp
L BC547 Q1
U 1 1 592F7057
P 3900 4200
F 0 "Q1" H 4100 4275 50  0000 L CNN
F 1 "BC547" H 4100 4200 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 4100 4125 50  0001 L CIN
F 3 "" H 3900 4200 50  0001 L CNN
	1    3900 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 4200 3600 4200
Wire Wire Line
	3050 4450 4700 4450
Wire Wire Line
	4000 4450 4000 4400
Connection ~ 3050 4300
$Comp
L R R2.7k1
U 1 1 592F71D9
P 4000 3600
F 0 "R2.7k1" V 4080 3600 50  0000 C CNN
F 1 "R" V 4000 3600 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 3930 3600 50  0001 C CNN
F 3 "" H 4000 3600 50  0001 C CNN
	1    4000 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 3750 4000 4000
Text Label 2950 3400 0    60   ~ 0
5V
Text Label 3100 3350 0    60   ~ 0
GND_DRIVER
$Comp
L CONN_01X02 J3
U 1 1 592F7788
P 4350 2950
F 0 "J3" H 4350 3100 50  0000 C CNN
F 1 "CONN_01X02" V 4450 2950 50  0000 C CNN
F 2 "Connectors01:bornier2" H 4350 2950 50  0001 C CNN
F 3 "" H 4350 2950 50  0001 C CNN
	1    4350 2950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4000 3150 4300 3150
Text Label 4000 3400 0    60   ~ 0
12V
Wire Wire Line
	4000 3150 4000 3450
Wire Wire Line
	4400 3850 4000 3850
Connection ~ 4000 3850
Wire Wire Line
	4700 3650 4700 3150
Wire Wire Line
	4700 3150 4400 3150
Wire Wire Line
	4700 4450 4700 4050
Connection ~ 4000 4450
Text Label 4700 3400 0    60   ~ 0
IN_Lamp
$Comp
L PWR_FLAG #FLG01
U 1 1 592F7F64
P 2850 3500
F 0 "#FLG01" H 2850 3575 50  0001 C CNN
F 1 "PWR_FLAG" H 2850 3650 50  0000 C CNN
F 2 "" H 2850 3500 50  0001 C CNN
F 3 "" H 2850 3500 50  0001 C CNN
	1    2850 3500
	0    -1   -1   0   
$EndComp
$Comp
L PWR_FLAG #FLG02
U 1 1 592F803E
P 3900 3300
F 0 "#FLG02" H 3900 3375 50  0001 C CNN
F 1 "PWR_FLAG" H 3900 3450 50  0000 C CNN
F 2 "" H 3900 3300 50  0001 C CNN
F 3 "" H 3900 3300 50  0001 C CNN
	1    3900 3300
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3900 3300 4000 3300
Connection ~ 4000 3300
Wire Wire Line
	2850 3500 2950 3500
Connection ~ 2950 3500
$Comp
L Q_NMOS_DGS Q2
U 1 1 592F859E
P 4600 3850
F 0 "Q2" H 4800 3900 50  0000 L CNN
F 1 "Q_NMOS_DGS" H 4800 3800 50  0000 L CNN
F 2 "Connectors01:Wafer_Vertical10x5.8x7RM2.5-3" H 4800 3950 50  0001 C CNN
F 3 "" H 4600 3850 50  0001 C CNN
	1    4600 3850
	1    0    0    -1  
$EndComp
$EndSCHEMATC
