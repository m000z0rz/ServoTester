EESchema Schematic File Version 4
LIBS:ServoTester-cache
EELAYER 26 0
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
L teensy:Teensy2.0 U1
U 1 1 5D2267E6
P 2950 2350
F 0 "U1" H 2950 3387 60  0000 C CNN
F 1 "Teensy2.0" H 2950 3281 60  0000 C CNN
F 2 "Teensy:Teensy2.0" H 3050 1300 60  0001 C CNN
F 3 "" H 3050 1300 60  0000 C CNN
	1    2950 2350
	1    0    0    -1  
$EndComp
$Comp
L WiiNunchuckConnector:WiiNunchuckConnector J1
U 1 1 5D22D074
P 5200 1600
F 0 "J1" H 5477 1596 50  0000 L CNN
F 1 "WiiNunchuckConnector" H 5477 1505 50  0000 L CNN
F 2 "ServoTester:WiiNunchuckConnector" H 5050 1900 50  0001 C CNN
F 3 "" H 5050 1900 50  0001 C CNN
	1    5200 1600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5D22D0FC
P 2050 1600
F 0 "#PWR0101" H 2050 1350 50  0001 C CNN
F 1 "GND" H 2055 1427 50  0000 C CNN
F 2 "" H 2050 1600 50  0001 C CNN
F 3 "" H 2050 1600 50  0001 C CNN
	1    2050 1600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5D22D124
P 4700 1600
F 0 "#PWR0102" H 4700 1350 50  0001 C CNN
F 1 "GND" H 4705 1427 50  0000 C CNN
F 2 "" H 4700 1600 50  0001 C CNN
F 3 "" H 4700 1600 50  0001 C CNN
	1    4700 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 1600 4900 1600
Wire Wire Line
	2050 1600 2250 1600
$Comp
L power:VCC #PWR0103
U 1 1 5D22D1D6
P 4650 1450
F 0 "#PWR0103" H 4650 1300 50  0001 C CNN
F 1 "VCC" H 4667 1623 50  0000 C CNN
F 2 "" H 4650 1450 50  0001 C CNN
F 3 "" H 4650 1450 50  0001 C CNN
	1    4650 1450
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0104
U 1 1 5D22D23D
P 3800 1900
F 0 "#PWR0104" H 3800 1750 50  0001 C CNN
F 1 "VCC" H 3817 2073 50  0000 C CNN
F 2 "" H 3800 1900 50  0001 C CNN
F 3 "" H 3800 1900 50  0001 C CNN
	1    3800 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 1450 4650 1450
Wire Wire Line
	3650 1900 3800 1900
Wire Wire Line
	2000 3450 4850 3450
Wire Wire Line
	4850 3450 4850 1900
Wire Wire Line
	4850 1900 4900 1900
Wire Wire Line
	2250 2300 2050 2300
Wire Wire Line
	2050 3400 4800 3400
Wire Wire Line
	4800 3400 4800 1750
Wire Wire Line
	4800 1750 4900 1750
$Comp
L Display_Character_Custom:HD44780 U2
U 1 1 5D230169
P 3400 4800
F 0 "U2" H 4278 4882 50  0000 L CNN
F 1 "HD44780" H 4278 4791 50  0000 L CNN
F 2 "ServoTester:JHD204AO 20x4 Character LCD" H 2600 4500 50  0001 C CNN
F 3 "" H 2600 4500 50  0001 C CNN
	1    3400 4800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 5D2301F8
P 2350 4500
F 0 "#PWR0105" H 2350 4250 50  0001 C CNN
F 1 "GND" H 2355 4327 50  0000 C CNN
F 2 "" H 2350 4500 50  0001 C CNN
F 3 "" H 2350 4500 50  0001 C CNN
	1    2350 4500
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0106
U 1 1 5D23022A
P 2750 4250
F 0 "#PWR0106" H 2750 4100 50  0001 C CNN
F 1 "VCC" H 2767 4423 50  0000 C CNN
F 2 "" H 2750 4250 50  0001 C CNN
F 3 "" H 2750 4250 50  0001 C CNN
	1    2750 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 4250 2750 4450
Wire Wire Line
	2650 4450 2650 4400
Wire Wire Line
	2650 4400 2350 4400
Wire Wire Line
	2350 4400 2350 4500
$Comp
L power:GND #PWR0107
U 1 1 5D2304B9
P 4350 4450
F 0 "#PWR0107" H 4350 4200 50  0001 C CNN
F 1 "GND" H 4355 4277 50  0000 C CNN
F 2 "" H 4350 4450 50  0001 C CNN
F 3 "" H 4350 4450 50  0001 C CNN
	1    4350 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 4450 4150 4400
Wire Wire Line
	4150 4400 4350 4400
Wire Wire Line
	4350 4400 4350 4450
$Comp
L Device:R_POT_US RV1
U 1 1 5D230A33
P 2550 3850
F 0 "RV1" H 2482 3896 50  0000 R CNN
F 1 "10k" H 2482 3805 50  0000 R CNN
F 2 "ServoTester:Potentiometer" H 2550 3850 50  0001 C CNN
F 3 "~" H 2550 3850 50  0001 C CNN
	1    2550 3850
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0108
U 1 1 5D230CAC
P 2550 3650
F 0 "#PWR0108" H 2550 3500 50  0001 C CNN
F 1 "VCC" H 2567 3823 50  0000 C CNN
F 2 "" H 2550 3650 50  0001 C CNN
F 3 "" H 2550 3650 50  0001 C CNN
	1    2550 3650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0109
U 1 1 5D230CE1
P 2550 4050
F 0 "#PWR0109" H 2550 3800 50  0001 C CNN
F 1 "GND" H 2555 3877 50  0000 C CNN
F 2 "" H 2550 4050 50  0001 C CNN
F 3 "" H 2550 4050 50  0001 C CNN
	1    2550 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 3650 2550 3700
Wire Wire Line
	2550 4000 2550 4050
Wire Wire Line
	2700 3850 2850 3850
Wire Wire Line
	2850 3850 2850 4450
$Comp
L power:GND #PWR0110
U 1 1 5D23142D
P 3050 4200
F 0 "#PWR0110" H 3050 3950 50  0001 C CNN
F 1 "GND" H 3055 4027 50  0000 C CNN
F 2 "" H 3050 4200 50  0001 C CNN
F 3 "" H 3050 4200 50  0001 C CNN
	1    3050 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 4200 3050 4450
$Comp
L Device:R_US R1
U 1 1 5D231986
P 4050 4200
F 0 "R1" H 4118 4246 50  0000 L CNN
F 1 "R_US" H 4118 4155 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4090 4190 50  0001 C CNN
F 3 "~" H 4050 4200 50  0001 C CNN
	1    4050 4200
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0111
U 1 1 5D231A10
P 4050 3950
F 0 "#PWR0111" H 4050 3800 50  0001 C CNN
F 1 "VCC" H 4067 4123 50  0000 C CNN
F 2 "" H 4050 3950 50  0001 C CNN
F 3 "" H 4050 3950 50  0001 C CNN
	1    4050 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 3950 4050 4050
Wire Wire Line
	4050 4350 4050 4450
$Comp
L Jumper:Jumper_3_Bridged12 JP1
U 1 1 5D23F5A1
P 6100 3250
F 0 "JP1" V 6054 3317 50  0000 L CNN
F 1 "Jumper_3_Bridged12" V 6145 3317 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 6100 3250 50  0001 C CNN
F 3 "~" H 6100 3250 50  0001 C CNN
	1    6100 3250
	0    1    1    0   
$EndComp
$Comp
L Jumper:Jumper_3_Bridged12 JP2
U 1 1 5D23FCE9
P 6600 3250
F 0 "JP2" V 6554 3317 50  0000 L CNN
F 1 "Jumper_3_Bridged12" V 6645 3317 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 6600 3250 50  0001 C CNN
F 3 "~" H 6600 3250 50  0001 C CNN
	1    6600 3250
	0    1    1    0   
$EndComp
$Comp
L Jumper:Jumper_3_Bridged12 JP3
U 1 1 5D23FD2A
P 7100 3250
F 0 "JP3" V 7054 3317 50  0000 L CNN
F 1 "Jumper_3_Bridged12" V 7145 3317 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 7100 3250 50  0001 C CNN
F 3 "~" H 7100 3250 50  0001 C CNN
	1    7100 3250
	0    1    1    0   
$EndComp
$Comp
L Jumper:Jumper_3_Bridged12 JP4
U 1 1 5D23FD64
P 7600 3250
F 0 "JP4" V 7554 3317 50  0000 L CNN
F 1 "Jumper_3_Bridged12" V 7645 3317 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 7600 3250 50  0001 C CNN
F 3 "~" H 7600 3250 50  0001 C CNN
	1    7600 3250
	0    1    1    0   
$EndComp
$Comp
L Motor:Motor_Servo_JR M2
U 1 1 5D23FE6F
P 6450 4000
F 0 "M2" V 6399 4206 50  0000 L CNN
F 1 "Motor_Servo_JR" V 6490 4206 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 6450 3810 50  0001 C CNN
F 3 "http://forums.parallax.com/uploads/attachments/46831/74481.png" H 6450 3810 50  0001 C CNN
	1    6450 4000
	0    1    1    0   
$EndComp
$Comp
L Motor:Motor_Servo_JR M1
U 1 1 5D2408C2
P 5950 4000
F 0 "M1" V 5899 4206 50  0000 L CNN
F 1 "Motor_Servo_JR" V 5990 4206 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 5950 3810 50  0001 C CNN
F 3 "http://forums.parallax.com/uploads/attachments/46831/74481.png" H 5950 3810 50  0001 C CNN
	1    5950 4000
	0    1    1    0   
$EndComp
$Comp
L Motor:Motor_Servo_JR M3
U 1 1 5D240C73
P 6950 4000
F 0 "M3" V 6899 4206 50  0000 L CNN
F 1 "Motor_Servo_JR" V 6990 4206 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 6950 3810 50  0001 C CNN
F 3 "http://forums.parallax.com/uploads/attachments/46831/74481.png" H 6950 3810 50  0001 C CNN
	1    6950 4000
	0    1    1    0   
$EndComp
$Comp
L Motor:Motor_Servo_JR M4
U 1 1 5D240CE3
P 7450 4000
F 0 "M4" V 7399 4206 50  0000 L CNN
F 1 "Motor_Servo_JR" V 7490 4206 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 7450 3810 50  0001 C CNN
F 3 "http://forums.parallax.com/uploads/attachments/46831/74481.png" H 7450 3810 50  0001 C CNN
	1    7450 4000
	0    1    1    0   
$EndComp
$Comp
L power:VCC #PWR0112
U 1 1 5D241713
P 6850 2900
F 0 "#PWR0112" H 6850 2750 50  0001 C CNN
F 1 "VCC" H 6867 3073 50  0000 C CNN
F 2 "" H 6850 2900 50  0001 C CNN
F 3 "" H 6850 2900 50  0001 C CNN
	1    6850 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 2900 6850 2900
Wire Wire Line
	7100 3000 7100 2900
Wire Wire Line
	7100 2900 6850 2900
Connection ~ 6850 2900
Wire Wire Line
	7600 3000 7600 2900
Wire Wire Line
	7600 2900 7100 2900
Connection ~ 7100 2900
Wire Wire Line
	6100 3000 6100 2900
Wire Wire Line
	6100 2900 6600 2900
Connection ~ 6600 2900
Wire Wire Line
	6600 2900 6600 3000
Wire Wire Line
	5950 3250 5950 3700
Wire Wire Line
	6450 3250 6450 3700
Wire Wire Line
	6950 3250 6950 3700
Wire Wire Line
	7450 3250 7450 3700
$Comp
L power:GND #PWR0113
U 1 1 5D24519F
P 5600 3600
F 0 "#PWR0113" H 5600 3350 50  0001 C CNN
F 1 "GND" H 5605 3427 50  0000 C CNN
F 2 "" H 5600 3600 50  0001 C CNN
F 3 "" H 5600 3600 50  0001 C CNN
	1    5600 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 3600 5850 3600
Wire Wire Line
	5850 3600 5850 3700
Wire Wire Line
	6350 3700 6350 3600
Wire Wire Line
	6350 3600 5850 3600
Connection ~ 5850 3600
Wire Wire Line
	6850 3700 6850 3600
Wire Wire Line
	6850 3600 6350 3600
Connection ~ 6350 3600
Wire Wire Line
	7350 3700 7350 3600
Wire Wire Line
	7350 3600 6850 3600
Connection ~ 6850 3600
Wire Wire Line
	2250 2600 2100 2600
Wire Wire Line
	2100 2600 2100 3250
Wire Wire Line
	2100 3250 5400 3250
Wire Wire Line
	5400 3250 5400 4350
Wire Wire Line
	5400 4350 6150 4350
Wire Wire Line
	6150 4350 6150 3700
Wire Wire Line
	6150 3700 6050 3700
Wire Wire Line
	6550 3700 6650 3700
Wire Wire Line
	6650 3700 6650 4400
Wire Wire Line
	6650 4400 5350 4400
Wire Wire Line
	5350 4400 5350 3300
Wire Wire Line
	5350 3300 2150 3300
Wire Wire Line
	2150 3300 2150 2700
Wire Wire Line
	2150 2700 2250 2700
Wire Wire Line
	7050 3700 7150 3700
Wire Wire Line
	7150 3700 7150 4450
Wire Wire Line
	7150 4450 5300 4450
Wire Wire Line
	5300 4450 5300 3350
Wire Wire Line
	5300 3350 3950 3350
Wire Wire Line
	3950 3350 3950 2700
Wire Wire Line
	3950 2700 3650 2700
Wire Wire Line
	3650 2600 4000 2600
Wire Wire Line
	4000 2600 4000 3200
Wire Wire Line
	4000 3200 5250 3200
Wire Wire Line
	5250 3200 5250 4500
Wire Wire Line
	5250 4500 7650 4500
Wire Wire Line
	7650 4500 7650 3700
Wire Wire Line
	7650 3700 7550 3700
Wire Wire Line
	6100 3500 6600 3500
Wire Wire Line
	6600 3500 7100 3500
Connection ~ 6600 3500
Wire Wire Line
	7100 3500 7600 3500
Connection ~ 7100 3500
Connection ~ 7600 3500
$Comp
L power:GND #PWR0114
U 1 1 5D251524
P 8200 3650
F 0 "#PWR0114" H 8200 3400 50  0001 C CNN
F 1 "GND" H 8205 3477 50  0000 C CNN
F 2 "" H 8200 3650 50  0001 C CNN
F 3 "" H 8200 3650 50  0001 C CNN
	1    8200 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 3600 8200 3650
Wire Wire Line
	2050 2300 2050 3400
Wire Wire Line
	2000 2200 2000 3450
Wire Wire Line
	2000 2200 2250 2200
Wire Wire Line
	3650 2000 3900 2000
Wire Wire Line
	3900 2000 3900 4200
Wire Wire Line
	3900 4200 3950 4200
Wire Wire Line
	3950 4200 3950 4450
Wire Wire Line
	3650 2100 3850 2100
Wire Wire Line
	3850 2100 3850 4450
Wire Wire Line
	3650 2200 3800 2200
Wire Wire Line
	3800 2200 3800 4200
Wire Wire Line
	3800 4200 3750 4200
Wire Wire Line
	3750 4200 3750 4450
Wire Wire Line
	3650 2300 3750 2300
Wire Wire Line
	3750 2300 3750 4150
Wire Wire Line
	3750 4150 3650 4150
Wire Wire Line
	3650 4150 3650 4450
Wire Wire Line
	3700 4100 3150 4100
Wire Wire Line
	3150 4100 3150 4450
Wire Wire Line
	3600 2500 3650 2500
Wire Wire Line
	4250 3650 2950 3650
Wire Wire Line
	2950 3650 2950 4450
$Comp
L Connector:Conn_01x02_Female J2
U 1 1 5D2772B7
P 9150 3500
F 0 "J2" H 9177 3476 50  0000 L CNN
F 1 "Conn_01x02_Female" H 9177 3385 50  0000 L CNN
F 2 "ServoTester:BananaJack_2" H 9150 3500 50  0001 C CNN
F 3 "~" H 9150 3500 50  0001 C CNN
	1    9150 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 3500 8950 3500
Wire Wire Line
	8200 3600 8950 3600
$Comp
L Device:CP1 C1
U 1 1 5D2A2AFF
P 5600 3100
F 0 "C1" H 5715 3146 50  0000 L CNN
F 1 "CP1" H 5715 3055 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D8.0mm_P5.00mm" H 5600 3100 50  0001 C CNN
F 3 "~" H 5600 3100 50  0001 C CNN
	1    5600 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 2950 5600 2900
Wire Wire Line
	5600 2900 6100 2900
Connection ~ 6100 2900
Wire Wire Line
	5600 3250 5600 3600
Connection ~ 5600 3600
Wire Wire Line
	2250 1700 1950 1700
$Comp
L Device:R_US R2
U 1 1 5D2B0146
P 1950 1350
F 0 "R2" H 2018 1396 50  0000 L CNN
F 1 "R_US" H 2018 1305 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 1990 1340 50  0001 C CNN
F 3 "~" H 1950 1350 50  0001 C CNN
	1    1950 1350
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0115
U 1 1 5D2B0293
P 1950 1100
F 0 "#PWR0115" H 1950 950 50  0001 C CNN
F 1 "VCC" H 1967 1273 50  0000 C CNN
F 2 "" H 1950 1100 50  0001 C CNN
F 3 "" H 1950 1100 50  0001 C CNN
	1    1950 1100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0116
U 1 1 5D2B37F4
P 1400 1850
F 0 "#PWR0116" H 1400 1600 50  0001 C CNN
F 1 "GND" H 1405 1677 50  0000 C CNN
F 2 "" H 1400 1850 50  0001 C CNN
F 3 "" H 1400 1850 50  0001 C CNN
	1    1400 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 1500 1950 1700
Connection ~ 1950 1700
Wire Wire Line
	1950 1700 1800 1700
Wire Wire Line
	1950 1200 1950 1100
Wire Wire Line
	1400 1700 1400 1850
$Comp
L Switch:SW_Push_Open SW1
U 1 1 5D2BF127
P 1600 1700
F 0 "SW1" H 1600 1915 50  0000 C CNN
F 1 "SW_Push_Open" H 1600 1824 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H5mm" H 1600 1900 50  0001 C CNN
F 3 "" H 1600 1900 50  0001 C CNN
	1    1600 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 2400 4250 3650
Wire Wire Line
	3650 2400 4250 2400
Wire Wire Line
	3650 2500 3700 2500
Wire Wire Line
	3700 2500 3700 4100
Connection ~ 3650 2500
$EndSCHEMATC
