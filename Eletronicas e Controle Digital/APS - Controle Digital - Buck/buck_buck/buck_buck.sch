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
LIBS:buck_buck-cache
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
L L L1
U 1 1 59EF7035
P 5850 1800
F 0 "L1" V 5800 1800 50  0000 C CNN
F 1 "6m" V 5925 1800 50  0000 C CNN
F 2 "Inductors_THT:L_Toroid_Horizontal_D35.1mm_P31.00mm_Vishay_TJ6" H 5850 1800 50  0001 C CNN
F 3 "" H 5850 1800 50  0001 C CNN
	1    5850 1800
	0    -1   -1   0   
$EndComp
$Comp
L CONN_01X02 J1
U 1 1 59EF7141
P 4400 2400
F 0 "J1" H 4400 2550 50  0000 C CNN
F 1 "24V" V 4500 2400 50  0000 C CNN
F 2 "Connectors:bornier2" H 4400 2400 50  0001 C CNN
F 3 "" H 4400 2400 50  0001 C CNN
	1    4400 2400
	-1   0    0    1   
$EndComp
$Comp
L D D1
U 1 1 59EF732A
P 5550 2300
F 0 "D1" H 5550 2400 50  0000 C CNN
F 1 "D" H 5550 2200 50  0000 C CNN
F 2 "Diodes_THT:D_DO-15_P10.16mm_Horizontal" H 5550 2300 50  0001 C CNN
F 3 "" H 5550 2300 50  0001 C CNN
	1    5550 2300
	0    1    1    0   
$EndComp
$Comp
L C C1
U 1 1 59EF74A3
P 6300 2250
F 0 "C1" H 6325 2350 50  0000 L CNN
F 1 "100u" H 6325 2150 50  0000 L CNN
F 2 "Capacitors_THT:C_Rect_L9.0mm_W4.9mm_P7.50mm_MKT" H 6338 2100 50  0001 C CNN
F 3 "" H 6300 2250 50  0001 C CNN
	1    6300 2250
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 59EF74D1
P 6550 2250
F 0 "C2" H 6575 2350 50  0000 L CNN
F 1 "10u" H 6575 2150 50  0000 L CNN
F 2 "Capacitors_THT:C_Rect_L9.0mm_W4.9mm_P7.50mm_MKT" H 6588 2100 50  0001 C CNN
F 3 "" H 6550 2250 50  0001 C CNN
	1    6550 2250
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 59EF7511
P 6800 2250
F 0 "C3" H 6825 2350 50  0000 L CNN
F 1 "22u" H 6825 2150 50  0000 L CNN
F 2 "Capacitors_THT:C_Rect_L9.0mm_W4.9mm_P7.50mm_MKT" H 6838 2100 50  0001 C CNN
F 3 "" H 6800 2250 50  0001 C CNN
	1    6800 2250
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 59EF7617
P 7200 2250
F 0 "R1" V 7280 2250 50  0000 C CNN
F 1 "33Mar" V 7200 2250 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_Power_L38.0mm_W9.0mm_P40.64mm" V 7130 2250 50  0001 C CNN
F 3 "" H 7200 2250 50  0001 C CNN
	1    7200 2250
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 59EF7648
P 7500 2250
F 0 "R2" V 7580 2250 50  0000 C CNN
F 1 "33Ver" V 7500 2250 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_Power_L48.0mm_W12.5mm_P55.88mm" V 7430 2250 50  0001 C CNN
F 3 "" H 7500 2250 50  0001 C CNN
	1    7500 2250
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 59EF78FC
P 7950 2000
F 0 "R3" V 8030 2000 50  0000 C CNN
F 1 "10k" V 7950 2000 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7880 2000 50  0001 C CNN
F 3 "" H 7950 2000 50  0001 C CNN
	1    7950 2000
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 59EF7946
P 7950 2500
F 0 "R4" V 8030 2500 50  0000 C CNN
F 1 "1k" V 7950 2500 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7880 2500 50  0001 C CNN
F 3 "" H 7950 2500 50  0001 C CNN
	1    7950 2500
	1    0    0    -1  
$EndComp
$Comp
L TL082 U1
U 1 1 59EF7989
P 8650 2300
F 0 "U1" H 8650 2500 50  0000 L CNN
F 1 "TL082" H 8650 2100 50  0000 L CNN
F 2 "Housings_DIP:DIP-8_W7.62mm_Socket_LongPads" H 8650 2300 50  0001 C CNN
F 3 "" H 8650 2300 50  0001 C CNN
	1    8650 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	8350 2400 8200 2400
Wire Wire Line
	8200 2400 8200 2750
Wire Wire Line
	8200 2750 9100 2750
Wire Wire Line
	9100 2750 9100 2300
Wire Wire Line
	8950 2300 9700 2300
Wire Wire Line
	8550 2600 8550 3050
Wire Wire Line
	8550 2000 8550 1650
Wire Wire Line
	7950 2150 7950 2350
Wire Wire Line
	7950 2650 7950 3100
Wire Wire Line
	8350 2200 7950 2200
Connection ~ 7950 2200
Wire Wire Line
	7950 1800 7950 1850
Wire Wire Line
	4600 2350 4600 1800
Wire Wire Line
	6000 1800 7950 1800
Wire Wire Line
	6300 2100 6300 1800
Connection ~ 6300 1800
Wire Wire Line
	6550 2100 6550 1800
Connection ~ 6550 1800
Wire Wire Line
	6800 2100 6800 1800
Connection ~ 6800 1800
Wire Wire Line
	7200 2100 7200 1800
Connection ~ 7200 1800
Wire Wire Line
	7500 2100 7500 1800
Connection ~ 7500 1800
Wire Wire Line
	7500 2900 7500 2400
Wire Wire Line
	7200 2400 7200 2900
Wire Wire Line
	4600 2900 7700 2900
Wire Wire Line
	6300 2900 6300 2400
Connection ~ 7200 2900
Wire Wire Line
	6550 2400 6550 2900
Connection ~ 6550 2900
Wire Wire Line
	6800 2400 6800 2900
Connection ~ 6800 2900
Wire Wire Line
	5550 1800 5550 2150
Connection ~ 5550 1800
Wire Wire Line
	5550 2450 5550 2900
Connection ~ 6300 2900
Wire Wire Line
	4600 2450 4600 2900
Connection ~ 5550 2900
$Comp
L CONN_01X02 J2
U 1 1 59EF88A9
P 5350 1050
F 0 "J2" H 5350 1200 50  0000 C CNN
F 1 "OUT_Driver" V 5450 1050 50  0000 C CNN
F 2 "Connectors:bornier2" H 5350 1050 50  0001 C CNN
F 3 "" H 5350 1050 50  0001 C CNN
	1    5350 1050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5100 2200 5350 2200
Wire Wire Line
	5350 2200 5350 1500
Wire Wire Line
	5350 1500 5300 1500
Wire Wire Line
	5300 1500 5300 1250
Wire Wire Line
	5400 1250 5400 1300
Wire Wire Line
	5400 1300 5500 1300
Wire Wire Line
	5500 1300 5500 1800
Connection ~ 5500 1800
Text Label 5300 1350 2    60   ~ 0
Gate
Text Label 5500 1350 0    60   ~ 0
Source
Text Label 4600 2000 0    60   ~ 0
24V
Text Label 4600 2750 0    60   ~ 0
GND
Connection ~ 9100 2300
$Comp
L CONN_01X03 J4
U 1 1 59EF93EF
P 8250 1100
F 0 "J4" H 8250 1300 50  0000 C CNN
F 1 "Alimentacao_TL" V 8350 1100 50  0000 C CNN
F 2 "Connectors:bornier3" H 8250 1100 50  0001 C CNN
F 3 "" H 8250 1100 50  0001 C CNN
	1    8250 1100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8250 1300 8250 1650
Wire Wire Line
	8250 1650 8550 1650
Wire Wire Line
	8150 1300 8150 1750
Wire Wire Line
	8150 1750 8300 1750
Wire Wire Line
	8300 1750 8300 3050
Wire Wire Line
	8300 3050 8550 3050
Wire Wire Line
	8350 1300 8350 1550
Wire Wire Line
	8350 1550 9000 1550
Wire Wire Line
	9000 1550 9000 3100
Wire Wire Line
	7700 3100 9700 3100
Text Label 8150 1500 2    60   ~ 0
-15V
Text Label 8550 1800 0    60   ~ 0
15V
Text Label 9000 1750 0    60   ~ 0
GND
Wire Wire Line
	7350 1200 7350 1800
Connection ~ 7350 1800
Wire Wire Line
	7450 1300 7700 1300
Wire Wire Line
	7700 1300 7700 3100
Connection ~ 7500 2900
Text Label 7350 1500 2    60   ~ 0
OUT
Text Label 7700 1500 0    60   ~ 0
GND
$Comp
L CONN_01X02 J5
U 1 1 59EFA122
P 9900 2500
F 0 "J5" H 9900 2650 50  0000 C CNN
F 1 "IN_Filtro" V 10000 2500 50  0000 C CNN
F 2 "Connectors:bornier2" H 9900 2500 50  0001 C CNN
F 3 "" H 9900 2500 50  0001 C CNN
	1    9900 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	9700 2300 9700 2450
Wire Wire Line
	9700 3100 9700 2550
Connection ~ 9000 3100
Connection ~ 7700 2900
Connection ~ 7950 3100
Text Label 9550 2300 1    60   ~ 0
OUT_Filtro
Text Label 9700 3050 0    60   ~ 0
GND
$Comp
L PWR_FLAG #FLG01
U 1 1 59EFAB7D
P 8100 1650
F 0 "#FLG01" H 8100 1725 50  0001 C CNN
F 1 "PWR_FLAG" H 8100 1800 50  0000 C CNN
F 2 "" H 8100 1650 50  0001 C CNN
F 3 "" H 8100 1650 50  0001 C CNN
	1    8100 1650
	0    -1   -1   0   
$EndComp
$Comp
L PWR_FLAG #FLG02
U 1 1 59EFABB1
P 8700 1900
F 0 "#FLG02" H 8700 1975 50  0001 C CNN
F 1 "PWR_FLAG" H 8700 2050 50  0000 C CNN
F 2 "" H 8700 1900 50  0001 C CNN
F 3 "" H 8700 1900 50  0001 C CNN
	1    8700 1900
	0    1    1    0   
$EndComp
Wire Wire Line
	8700 1900 8550 1900
Connection ~ 8550 1900
Wire Wire Line
	8100 1650 8150 1650
Connection ~ 8150 1650
$Comp
L Q_NMOS_GDS Q1
U 1 1 59EFCF4F
P 5100 1900
F 0 "Q1" H 5300 1950 50  0000 L CNN
F 1 "Q_NMOS_GDS" H 5300 1850 50  0000 L CNN
F 2 "Connectors:Wafer_Vertical10x5.8x7RM2.5-3" H 5300 2000 50  0001 C CNN
F 3 "" H 5100 1900 50  0001 C CNN
	1    5100 1900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5100 2200 5100 2100
Wire Wire Line
	4600 1800 4900 1800
Wire Wire Line
	5300 1800 5700 1800
$Comp
L CONN_01X02 J3
U 1 1 59EFD4F1
P 7400 1000
F 0 "J3" H 7400 1150 50  0000 C CNN
F 1 "CONN_01X02" V 7500 1000 50  0000 C CNN
F 2 "Connectors:bornier2" H 7400 1000 50  0001 C CNN
F 3 "" H 7400 1000 50  0001 C CNN
	1    7400 1000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7450 1200 7450 1300
$EndSCHEMATC
