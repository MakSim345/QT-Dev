// ******************************************************************
// * Datex-Ohmeda Inc.
// * Ohmeda Drive
// * PO Box 7550
// * Madison, WI 53707-7550
// *
// * Copyright 2000, Datex-Ohmeda, Inc.
// *
// * Revision Control Archive Name:
// *                            $Archive:   //omdswg59/rdpublic/Common/Iris/VcbTest.mdd  $
// * Working File Name:         $Workfile:   VcbTest.mdd  $
// *
// * Version:                   $Revision: 1.1.1.1 $
// *
// * Last Modification Time:    $Modtime:   May 29 2002 16:20:48  $
// * Author:                    $Author: aa027762 $
// *
// *******************************************************************

/*
** Enumerations used in one or more messages.
*/

Enum MODE
{
	Description "Indicates the testing mode the VCB should support on this boot-up.";

	Element HALT;
	Element EMC;
	Element UNDETECTED,
			Description "This is the state the VCB defaults to.";
}

Enum CAL_STATUS
{
	Description	"Cal Status Enumeration.";

	Element		VCB_ZERO_CAL;
    Element		VCB_AIR_VALVE_CAL;
    Element		VCB_OXYGEN_VALVE_CAL;
    Element		VCB_EXPIRATORY_VALVE_CAL;
	Element		VCB_PARACUBE_CAL;
    Element		VCB_EXPIRATORY_FLOW_CAL;
	Element		VCB_SPAN_CAL;
	Element		VCB_CHECKOUT;
	Element		VCB_PAW_CHECKOUT;
    Element		VCB_BARO_CHECKOUT;
	Element		VCB_LEAK_CHECKOUT;
	Element		VCB_SAFETY_CHECKOUT;
	Element		VCB_EXH_VALVE_CHECKOUT;
	Element		VCB_EXH_FLOW_CHECKOUT;
	Element		VCB_RESIS_CHECKOUT;
	Element		VCB_AIR_SENSOR_CHECKOUT;
	Element		VCB_OXYGEN_SENSOR_CHECKOUT;
	Element		VCB_PARACUBE_CHECKOUT;
	Element		VCB_CHECKOUT_CAL_PASSED;
    Element		VCB_CHECKOUT_CAL_FAILED;
    Element		VCB_CHECKOUT_CAL_NO_AIR;
    Element		VCB_CHECKOUT_CAL_NO_OXYGEN;
    Element		VCB_CHECKOUT_CAL_ABORTED;
    Element		VCB_CHECKOUT_CAL_NONE;
	Element		VCB_CHECKOUT_CAL_COMPLETE;
	Element		VCB_AUX_ZERO_CAL;
	Element		VCB_LOW_PRESSURE_LEAK_TEST;
    Element		VCB_OXYGEN_HIGH_PRESSURE_LEAK_TEST;
    Element		VCB_AIR_HIGH_PRESSURE_LEAK_TEST;
	Element		VCB_VALVE_SWEEP;
	Element		VCB_EXP_VALVE_SWEEP;
    Element		VCB_MEASURE_P01;
    Element		VCB_REGULATOR_STEP;
}

Enum CMX_TASK
{
    Description "CMX RTOS task number";
    Element     OFF;
    Element     TASK1;
    Element     TASK2;
    Element     TASK3;
    Element     TASK4;
    Element     TASK5;
    Element     TASK6;
    Element     TASK7;
    Element     TASK8;
    Element     TASK9;
    Element     TASK10;
	Element     TASK11;
	Element     TASK12;
    Element     AUTO_CYCLE;
}

Enum SYSTEM_STATE
{
	Description	"System State Enumeration.";
	Element		OFF;
	Element		POWERUP_SELFTEST;
	Element		STANDBY;
	Element		CHECKOUT;
	Element		THERAPY;
	Element		MONITORING;
	Element		SERVICE;
	Element		SUPER_USER;
	Element		SOFTWARE_UPDATE;
	Element		FAILED;
	Element		FAILED_WITH_VENT;
	Element		MAX;
}

Enum TRIGGER
{
    Description "Trigger to indicate inspiration and expiration periods of the patient
    		breath";
    Element     EXPIRATION_END;
    Element     EXPIRATION_BEGIN;
    Element     INSPIRATION_END;
    Element     INSPIRATION_BEGIN;
}

Enum CALIBRATION_STATUS
{
    Description "Calibration Status Enumeration.";
    Element     PASSED;
    Element     FAILED;
    Element     IN_PROGRESS;
    Element     NO_CAL_REQUESTED;
    Element     COMM_ERR;
}

Enum BOARD_TYPE
{
    Description "Board type enumeration";
    Element     VCB;
    Element     VMB;
}


/**********************************************************************************
**
** Test Fixture to VCB: Set Clocking Period
** --------------------------------
**
***********************************************************************************/

// VCB INFORMATION

/****  MESSAGE ONE ****/

Message SensorInfo
{
	Description "Provides type of Sensor, Software, Hardware, Version, Units,
				 Factor, Overflow, Sensitivity, Reference Temperature,
				 Factor temperature, Sensor Serial Number, Current Temperature value,
				 and Sensor Flow value.";

	Rate		"Set Clocking Period";

	Member		TotalFlow
				Type IRIS_INT32
				Description "Total Flow"
				Unit "Flow in mL divided by a factor of 128";

	Member		OxygenFlow
				Type IRIS_INT32
				Description "Oxygen Flow"
				Unit "Flow in mL divided by a factor of 128";

	Member		AirFlow
				Type IRIS_INT32
				Description "Air Flow"
				Unit "Flow in mL divided by a factor of 128";

	Member		TotalCurrentTemp
				Type IRIS_INT32
				Description "Current temperature for compensation"
				Unit "Celcius x 100";

	Member		OxygenCurrentTemp
				Type IRIS_INT32
				Description "Current temperature for compensation"
				Unit "Celcius x 100";

	Member		AirCurrentTemp
				Type IRIS_INT32
				Description "Current temperature for compensation"
				Unit "Celcius x 100";

}

/****  MESSAGE TWO ****/

Message SensorDetails
{
	Description "Provides type of Sensor, Software, Hardware, Version, Units,
				 Factor, Overflow, Sensitivity, Reference Temperature,
				 Factor temperature, Sensor Serial Number, Current Temperature value,
				 and Sensor Flow value.";

	Rate		"Set Clocking Period";

	Member		TotalUnits
				Type IRIS_BYTE[4]
				Description "Units of flow"
				Unit "slm";

	Member		OxygenUnits
				Type IRIS_BYTE[4]
				Description "Units of flow"
				Unit "slm";

	Member		AirUnits
				Type IRIS_BYTE[4]
				Description "Units of flow"
				Unit "slm";

	Member		TotalFactor
				Type IRIS_INT32
				Description "Divide by this factor to get in Liters"
				Unit "None";

	Member		OxygenFactor
				Type IRIS_UINT32
				Description "Divide by this factor to get in Liters"
				Unit "None";

	Member		AirFactor
				Type IRIS_UINT32
				Description "Divide by this factor to get in Liters"
				Unit "None";

	Member		TotalOverflow
				Type IRIS_UINT32
				Description ""
				Unit "None";

	Member		OxygenOverflow
				Type IRIS_UINT32
				Description ""
				Unit "None";

	Member		AirOverflow
				Type IRIS_UINT32
				Description ""
				Unit "None";

	Member		TotalSensitivity
				Type IRIS_UINT32
				Description ""
				Unit "None";

	Member		OxygenSensitivity
				Type IRIS_UINT32
				Description ""
				Unit "None";

	Member		AirSensitivity
				Type IRIS_UINT32
				Description ""
				Unit "None";

	Member		TotalRefTemp
				Type IRIS_UINT32
				Description "Reference Temperature"
				Unit "Degrees Fahrenheit";

	Member		OxygenRefTemp
				Type IRIS_UINT32
				Description "Reference Temperature"
				Unit "Degrees Fahrenheit";

	Member		AirRefTemp
				Type IRIS_UINT32
				Description "Reference Temperature"
				Unit "Degrees Fahrenheit";

	Member		TotalFactorTemp
				Type IRIS_UINT32
				Description "Factor Temperature"
				Unit "Degrees Fahrenheit";

	Member		OxygenFactorTemp
				Type IRIS_UINT32
				Description "Factor Temperature"
				Unit "Degrees Fahrenheit";

	Member		AirFactorTemp
				Type IRIS_UINT32
				Description "Factor Temperature"
				Unit "Degrees Fahrenheit";

	Member		TotalSensorType
				Type IRIS_BYTE[8]
				Description "Type of sensor"
				Unit "None";

	Member		OxygenSensorType
				Type IRIS_BYTE[8]
				Description "Type of sensor"
				Unit "None";

	Member		AirSensorType
				Type IRIS_BYTE[8]
				Description "Type of sensor"
				Unit "None";

	Member		TotalSoftwareVersion
				Type IRIS_BYTE[4]
				Description "Software version"
				Unit "None";

	Member		OxygenSoftwareVersion
				Type IRIS_BYTE[4]
				Description "Software version"
				Unit "None";

	Member		AirSoftwareVersion
				Type IRIS_BYTE[4]
				Description "Software version"
				Unit "None";

	Member		TotalHardwareVersion
				Type IRIS_BYTE[5]
				Description "Hardware version"
				Unit "None";

	Member		OxygenHardwareVersion
				Type IRIS_BYTE[5]
				Description "Hardware version"
				Unit "None";

	Member		AirHardwareVersion
				Type IRIS_BYTE[5]
				Description "Hardware version"
				Unit "None";

	Member		TotalSensorIDNumber
				Type IRIS_UINT32
				Description "Sensor ID"
				Unit "None";

	Member		OxygenSensorIDNumber
				Type IRIS_UINT32
				Description "Sensor ID"
				Unit "None";

	Member		AirSensorIDNumber
				Type IRIS_UINT32
				Description "Sensor ID"
				Unit "None";


}

/****  MESSAGE THREE ****/

Message ChannelConfigurations
{
	Description "Channel Configurations for valves and voltage values.";

	Rate		"Set Clocking Period";

	Member		InspPressureCounts
				Type IRIS_UINT16
				Description "Expiratory Pressure"
				Unit "cmH20 in Counts";

	Member		InspPressureValue
				Type IRIS_INT16
				Description "Expiratory Pressure"
				Unit "cmH20";

	Member		AuxPressureCounts
				Type IRIS_UINT16
				Description "Aux Pressure"
				Unit "cmH20 in Counts";

	Member		AuxPressureValue
				Type IRIS_INT16
				Description "Aux Pressure"
				Unit "cmH20";

	Member		ExhValveVoltageCounts
				Type IRIS_UINT16
				Description "Exhalation Valve Drive Voltage"
				Unit "Volts in Counts";

	Member		ExhValveVoltageValue
				Type IRIS_INT32
				Description "Exhalation Valve Drive Voltage"
				Unit "mV";

	Member		ExhValveCurrentCounts
				Type IRIS_UINT16
				Description "Exhalation Valve Drive Current"
				Unit "Current in Counts";

	Member		ExhValveCurrentValue
				Type IRIS_INT32
				Description "Exhalation Valve Drive Current"
				Unit "mA";

	Member		V4096refCounts
				Type IRIS_UINT16
				Description "Secondary Voltage Reference"
				Unit "Volts in Counts";

	Member		V4096refValue
				Type IRIS_INT32
				Description "Secondary Voltage Reference"
				Unit "mV";

	Member		MUXA_AGND_Counts
				Type IRIS_UINT16
				Description "Analog Ground"
				Unit "Volts in Counts";

	Member		MUXA_AGND_Value
				Type IRIS_INT32
				Description "Analog Ground"
				Unit "mV";

	Member		MUXB_AGND_Counts
				Type IRIS_UINT16
				Description "Analog Ground"
				Unit "Volts in Counts";

	Member		MUXB_AGND_Value
				Type IRIS_INT32
				Description "Analog Ground"
				Unit "mV";

	Member		ADC_AGND_Counts
				Type IRIS_UINT16
				Description "Analog Ground"
				Unit "Volts in Counts";

	Member		ADC_AGND_Value
				Type IRIS_INT32
				Description "Analog Ground"
				Unit "mV";


	Member		O2ValveCurrentCounts
				Type IRIS_UINT16
				Description "Oxygen Valve Drive Current"
				Unit "Current in Counts";

	Member		O2ValveCurrentValue
				Type IRIS_INT32
				Description "Oxygen Valve Drive Current"
				Unit "mA";

	Member		AirValveCurrentCounts
				Type IRIS_UINT16
				Description "Air Valve Current Counts"
				Unit "Current in Counts";

	Member		AirValveCurrentValue
				Type IRIS_INT32
				Description "Air Valve Current Counts"
				Unit "mA";

	Member		V9Test_C_Counts
				Type IRIS_UINT16
				Description "Nebulizer Supply Voltage"
				Unit "Volts in Counts";

	Member		V9Test_C_Value
				Type IRIS_INT32
				Description "Nebulizer Supply Voltage"
				Unit "mV";

	Member		AmbientTempCounts
				Type IRIS_UINT16
				Description "Ambient Temperature Near Valves"
				Unit "Celcius in Counts";

	Member		AmbientTempValue
				Type IRIS_INT32
				Description "Ambient Temperature Near Valves"
				Unit "Celcius";

	Member		ModPwrFailCounts
				Type IRIS_UINT16
				Description "Mod Power Fail"
				Unit "Volts in Counts";

	Member		ModPwrFailValue
				Type IRIS_INT32
				Description "Mod Power Fail"
				Unit "mV";

	Member		V12P5_Test_Counts
				Type IRIS_UINT16
				Description "12P5"
				Unit "Volts in Counts";

	Member		V12P5_Test_Value
				Type IRIS_INT32
				Description "12P5"
				Unit "mV";

	Member		V5VA_Test_Counts
				Type IRIS_UINT16
				Description "5VA"
				Unit "Volts in Counts";

	Member		V5VA_Test_Value
				Type IRIS_INT32
				Description "5VA"
				Unit "mV";

	Member		V6VA_Test_Counts
				Type IRIS_UINT16
				Description "6VA"
				Unit "Volts in Counts";

	Member		V6VA_Test_Value
				Type IRIS_INT32
				Description "6VA"
				Unit "mV";

	Member		N6VA_Test_Counts
				Type IRIS_UINT16
				Description "N6VA"
				Unit "Volts in Counts";

	Member		N6VA_Test_Value
				Type IRIS_INT32
				Description "N6VA"
				Unit "mV";

	Member		V5P5VA_Test_Counts
				Type IRIS_UINT16
				Description "5P5VA"
				Unit "Volts in Counts";

	Member		V5P5VA_Test_Value
				Type IRIS_INT32
				Description "5P5VA"
				Unit "mV";

	Member		V9_TestA_Counts
				Type IRIS_UINT16
				Description "9VA"
				Unit "Volts in Counts";

	Member		V9_TestA_Value
				Type IRIS_INT32
				Description "9VA"
				Unit "mV";

	Member		V9_TestB_Counts
				Type IRIS_UINT16
				Description "9VB"
				Unit "Volts in Counts";

	Member		V9_TestB_Value
				Type IRIS_INT32
				Description "9VB"
				Unit "mV";
}


/****  MESSAGE FOUR ****/

Message InputSignalLatch
{
	Description "See the status of the input signal latches.";

	Rate		"Set Clocking Period";

	Member		ModPwrFail
				Type IRIS_BOOL
				Description "Mod Power Fail"
				Unit "None";

	Member		PsmPwrFail
				Type IRIS_BOOL
				Description "Psm Power Fail"
				Unit "None";

	Member		OverPress
				Type IRIS_BOOL
				Description "Over Pressure"
				Unit "None";

	Member		ZeroExppOn
				Type IRIS_BOOL
				Description "Zero Expired Pressure On"
				Unit "None";

	Member		VmBuzzerOn
				Type IRIS_BOOL
				Description "VM Buzzer On"
				Unit "None";

	Member		NebSnse1
				Type IRIS_BOOL
				Description "Nebulizer sensor 1"
				Unit "None";

	Member		NebSnse2
				Type IRIS_BOOL
				Description "Nebulizer sensor 2"
				Unit "None";

	Member		ExpPwrFail
				Type IRIS_BOOL
				Description "Expiration Power Fail"
				Unit "None";

	Member		BuzzerSnse
				Type IRIS_BOOL
				Description "Buzzer sensor"
				Unit "None";

	Member		ZeroAuxPOn
				Type IRIS_BOOL
				Description "Zero Auxilary Pressure On"
				Unit "None";

	Member		VmExhalOpen
				Type IRIS_BOOL
				Description "Vm Exhalation Open"
				Unit "None";

}

/****  MESSAGE FIVE ****/

Message PingCalibrationStatus
{
	Description "See the status of the input signal latches.";

	Rate		"Set Clocking Period";

	Member     	CalStatus
                Type IRIS_BYTE[40]
                Description	"Current running calibration"
                Unit "None";

	Member		PassFailStatus
				Type IRIS_UBYTE
                Description	"Pass/Fail running calibration"
                Unit "CAL_STATUS";

	Member		CalPercent
				Type IRIS_UINT16
				Description	"Percentage complete of current running calibration"
                Unit "None";
}

/****  MESSAGE SIX ****/

Message OtherVcbData
{
    Description "Random Vcb Data";

    Rate        "Set Clocking Period";

	Member		VmbVcbCommErrors
				Type IRIS_UINT32
				Description "Vcb/Vmb Crc errors"
				Unit "None";

	Member     	CpuLoadAvg
                Type IRIS_UINT16
                Description	"Cpu Loading Average"
                Unit "None";

	Member		O2Comp
				Type IRIS_INT16
				Description "Compensated O2 Value"
				Unit "%*10";

	Member      VCBTechnicalAlarmStatus1
                Type IRIS_UINT32
                Description "Technical alarm status bits #1 reported by the VCB.
						For all bits:
								0 = Alarm Not Active
								1 = Alarm Active
						Bit  0: Backup Buzzer POST
						Bit  1: Standby Patient Detection
						Bit  2: DU To VCB Comm Error
						Bit  3: VMB To VCB Comm Error
						Bit  4: VCB Processor Reset
						Bit  5: Air Supply Pressure High
						Bit  6: O2 Supply Pressure High
						Bit  7: Air Supply Pressure Low
						Bit  8: O2 Supply Pressure Low
						Bit  9: No Supply Pressure
						Bit 10: Exhalation Flow Sensor Comparision
						Bit 11: Temp High
						Bit 12: Negative Pressure
        				Bit 13: No Exhalation Flow Sensor
        				Bit 14: not used
        				Bit 15: not used
						Bit 16: Barometric Pressure Sensor Out Of Range
        				Bit 17: Exhalation Flow Sensor Communication Failure
						Bit 18: O2 Supply Pressure Sensor Out Of Range
						Bit 19: Air Supply Pressure Sensor Out Of Range
        				Bit 20: Paw Insp Sensor Out Of Range
						Bit 21: Paw Exp Sensor Out Of Range
						Bit 22: Paux Sensor Out Of Range
						Bit 23: Air Flow Sensor Communications Failure
						Bit 24: O2 Flow Sensor Communications Failure
						Bit 25: Total Flow Sensor Communications Failure
						Bit 26: Air Temperature Sensor Failure
						Bit 27: O2 Temperature Sensor Failure
						Bit 28: Total Flow Temperature Sensor Failure
						Bit 29: Nebulizer Not Connected
						Bit 30: Paw Cross-Check
						Bit 31: not used"
                Unit "None";

    Member      VCBTechnicalAlarmStatus2
                Type IRIS_UINT32
                Description "Technical alarm status bits #2 reported by the VCB.
						For all bits:
								0 = Alarm Not Active
								1 = Alarm Active
						Bit  0: not used
						Bit  1: not used
						Bit  2: not used
						Bit  3: Safety Valve Checkout Failure
						Bit  4: Paw Insp Zeroing Error
						Bit  5: Paw Exp Zeroing Error
                        Bit  6: Paux Zeroing Error
                        Bit  7: Paux High
                        Bit  8: Exp Flow Sensor Zeroing Error"
                Unit "None";

    Member      VCBParameterAlarmStatus
                Type IRIS_UINT32
                Description "Parameter alarm status bits reported by the VCB.
						For all bits:
								0 = Alarm Not Active
								1 = Alarm Active
						Bit  0: High Paw
						Bit  1: High Paw Plus
                        Bit  2: High Paw Sustained
						Bit  3: Low Paw
                        Bit  4: Breathing Circuit Occlusion
						Bit  5: Breathing Circuit Leak
						Bit  6: Sustained Paw
                        Bit  7: Apnea
						Bit  8: MV Expired Low
						Bit  9: MV Expired High
						Bit 10: Low FiO2
						Bit 11: High FiO2
                        Bit 12: Patient Disconnected
						Bit 13: TV Not Achieved"
                Unit "None";

	Member		WaveformJitter
				Type IRIS_UINT16
				Description "Monitors our waveform submission to see if we are sending data,
					at the desired 5Hz rate.  It is measured as millisecond deviation,
					from the expected 200ms per transmission."
				Unit "msec";

	Member		MaxVentParamJitter
				Type IRIS_UINT16
				Description "Maximum deviation from expected 500ms timeframe for vent parameters message."
				Unit "msec";

	Member		AvgVentParamJitter
				Type IRIS_UINT16
				Description "Average jitter over 1 minute."
				Unit "msec";

	Member		MaxSysStateJitter
				Type IRIS_UINT16
				Description "Maximum deviation from expected 1s timeframe for system state message."
				Unit "msec";

	Member		AvgSysStateJitter
				Type IRIS_UINT16
				Description "Average jitter over 1 minute."
				Unit "msec";
}

Message SystemState
{
	Description "Vcb System State";

    Rate        "Set Clocking Period";

	Member      SystemState
                Type IRIS_UBYTE
                Description "Enum SYSTEM_STATE"
                Unit "SYSTEM_STATE";
}


/****  MESSAGE SEVEN ****/

Message InterruptNumber
{
	Description	"This message receives number of interrupts";

	Rate		"Set Clocking Period";

	Member     	Interrupt
                Type IRIS_UINT32
                Description	"Number of Interrupts"
                Unit "None";
}

/****  MESSAGE EIGHT ****/
Message CrcErrorCheck
{
    Description "Used to log CRC errors detected on VCB to VMB and DC to VMB messages";

    Rate        "Set Clocking Period";

    Member      ExpAirwayPress
                Type IRIS_INT16
                Description "Pressure value of airway pressure transducer.  Valid
                range is from -20 to +120 cmH2O."
                Unit "cmH2O x100";

    Member      VcbVmbCrcErrors
                Type IRIS_UINT16
                Description "Number of CRC errors detected in VCB to VMB messages
                since last VMB reset"
                Unit "none";

    Member      DcVmbCrcErrors
                Type IRIS_UINT16
                Description "Number of CRC errors detected in DC to VMB messages
                since last VMB reset"
                Unit "none";
}

/****  MESSAGE NINE ****/
Message VcbVmbCommonAlarms
{
	Description "To display the VCB/VMB common alarms";

	Rate		"Set Clocking Period";

	Member		VcbCommonAlarms
				Type IRIS_UINT16
				Description "VCB alarms
					 Bit 9, NEG_PRESS
					 Bit 8, LOW_PAW
					 Bit 7, HIGH_FIO2
                     Bit 6, LOW_FIO2
                     Bit 5, HIGH_MV
                     Bit 4, LOW_MV
                     Bit 3, APNEA
                     Bit 2, SUSTAINED_PAW
                     Bit 1, HIGH_PAW_PLUS
                     Bit 0, HIGH_PAW"
				Unit "None";

	Member		VmbCommonAlarms
				Type IRIS_UINT16
				Description "VMB alarms
					 Bit 9, NEG_PRESS
					 Bit 8, LOW_PAW
					 Bit 7, HIGH_FIO2
                     Bit 6, LOW_FIO2
                     Bit 5, HIGH_MV
                     Bit 4, LOW_MV
                     Bit 3, APNEA
                     Bit 2, SUSTAINED_PAW
                     Bit 1, HIGH_PAW_PLUS
                     Bit 0, HIGH_PAW"
				Unit "None";
}

/****  MESSAGE TEN ****/

Message SendSpanDacValue
{
	Description "This message is to send the DAC Value for the span calibration";

	Rate		"Set Clocking Period";

	Member     	DAC_Value
                Type IRIS_UINT16
                Description	"First value to be sent to the VCB for calibration purposes"
                Unit "None";
}

/****  MESSAGE ELEVEN ****/

Message SendAirvlvDac
{
	Description "This message is to send the DAC Value for the air valve";

	Rate		"Set Clocking Period";

	Member     	DAC_Value
                Type IRIS_UINT16
                Description	"First value to be sent to the VCB for calibration purposes"
                Unit "None";
}

/****  MESSAGE TWELVE ****/

Message SendO2vlvDac
{
	Description "This message is to send the DAC Value for the O2 valve";

	Rate		"Set Clocking Period";

	Member     	DAC_Value
                Type IRIS_UINT16
                Description	"First value to be sent to the VCB for calibration purposes"
                Unit "None";
}

/****  MESSAGE THIRTEEN ****/

Message SendExhvlvDac
{
	Description "This message is to send the DAC Value for the exhalation valve";

	Rate		"Set Clocking Period";

	Member     	DAC_Value
                Type IRIS_UINT16
                Description	"First value to be sent to the VCB for calibration purposes"
                Unit "None";
}

/****  MESSAGE FOURTEEN ****/

Message SendExhvlvDitherDac
{
	Description "This message is to send the Dither DAC Value for the exhalation valve";

	Rate		"Set Clocking Period";

	Member     	DAC_Value
                Type IRIS_UINT16
                Description	"First value to be sent to the VCB for calibration purposes"
                Unit "None";
}


// VMB INFORMATION

/****  MESSAGE FIFTEEN ****/

Message PwrVmbInternal
{
    Description "Measured results of the VMB internal power supplies.";

    Rate        "Set Clocking Period";

	Member      ExpAirwayPress
                Type IRIS_INT16
                Description "Pressure value of airway pressure transducer.  Valid
                range is from -20 to +120 cmH2O."
                Unit "cmH2O x100";

    Member      P12p5vBits
                Type IRIS_UINT16
                Description "Scaled +12.5 volt input power supply"
                Unit "ADC10 bits, 1 LSB = 4.8828 mV";

    Member      P12p5vMv
                Type IRIS_UINT16
                Description "Scaled +12.5 volt input power supply"
                Unit "millivolts";

    Member      N5p5vBits
                Type IRIS_UINT16
                Description "Scaled -5.5 volt analog power supply"
                Unit "ADC10 bits, 1 LSB = 4.8828 mV";

    Member      N5p5vMv
                Type IRIS_UINT16
                Description "Scaled -5.5 volt analog power supply"
                Unit "millivolts";

    Member      P5p5vBits
                Type IRIS_UINT16
                Description "Scaled +5.5 volt analog power supply"
                Unit "ADC10 bits, 1 LSB = 4.8828 mV";

    Member      P5p5vMv
                Type IRIS_UINT16
                Description "Scaled +5.5 volt analog power supply"
                Unit "millivolts";

    Member      Vref122Bits
                Type IRIS_UINT16
                Description "Independent +1.22 volt internal microcontroller
                reference"
                Unit "ADC10 bits, 1 LSB = 4.8828 mV";

    Member      Vref122Mv
                Type IRIS_UINT16
                Description "Independent +1.22 volt internal microcontroller
                reference"
                Unit "millivolts";

    Member      AgndBits
                Type IRIS_UINT16
                Description "Analog ground."
                Unit "ADC10 bits, 1 LSB = 4.8828 mV";

    Member      AgndMv
                Type IRIS_UINT16
                Description "Analog ground."
                Unit "millivolts";
}

/****  MESSAGE SIXTEEN ****/

Message PwrExtSensor
{
    Description "Measurements of power supply voltages from the VMB to external
    		sensors.";

    Rate        "Set Clocking Period";

	Member      ExpAirwayPress
                Type IRIS_INT16
                Description "Pressure value of airway pressure transducer.  Valid
                range is from -20 to +120 cmH2O."
                Unit "cmH2O x100";

    Member      AirSupplyBits
                Type IRIS_UINT16
                Description "Scaled +5 volt supply for the Air supply pressure
                transducer"
                Unit "ADC10 bits, 1 LSB = 4.8828 mV";

    Member      AirSupplyMv
                Type IRIS_UINT16
                Description "Scaled +5 volt supply for the Air supply pressure
                transducer"
                Unit "millivolts";

    Member      O2SupplyBits
                Type IRIS_UINT16
                Description "Scaled +5 volt supply for the O2 supply pressure
                transducer"
                Unit "ADC10 bits, 1 LSB = 4.8828 mV";

    Member      O2SupplyMv
                Type IRIS_UINT16
                Description "Scaled +5 volt supply for the O2 supply pressure
                transducer"
                Unit "millivolts";

    Member      O2ParaBits
                Type IRIS_UINT16
                Description "Scaled +5 volt supply for the paramagnetic O2 sensor"
                Unit "ADC10 bits, 1 LSB = 4.8828 mV";

    Member      O2ParaMv
                Type IRIS_UINT16
                Description "Scaled +5 volt supply for the paramagnetic O2 sensor"
                Unit "millivolts";

    Member      ExFlowBits
                Type IRIS_UINT16
                Description "Scaled +5 volt supply for the exhilation flow sensor"
                Unit "ADC10 bits, 1 LSB = 4.8828 mV";

    Member      ExFlowMv
                Type IRIS_UINT16
                Description "Scaled +5 volt supply for the exhilation flow sensor"
                Unit "millivolts";
}

/****  MESSAGE SEVENTEEN ****/

Message PressXdcrOut
{
    Description "Measured A/D results of all pressure sensors.";

    Rate        "Set Clocking Period";

	Member      ExpAirwayPress
                Type IRIS_INT16
                Description "Pressure value of airway pressure transducer.  Valid
                range is from -20 to +120 cmH2O."
                Unit "cmH2O x100";

    Member      ExpAirwayBitsMv
                Type IRIS_UINT16
                Description "Output of airway pressure sensor"
                Unit "ADC12 bits, 1 LSB = 1.00 mV";

    Member      BaroBits
                Type IRIS_UINT16
                Description "Output of barometric pressure sensor"
                Unit "ADC10 bits, 1 LSB = 4.8828 mV";

    Member      BaroMv
                Type IRIS_UINT16
                Description "Output of barometric pressure sensor"
                Unit "millivolts";

    Member      O2SupplyBits
                Type IRIS_UINT16
                Description "Output of O2 supply pressure transducer"
                Unit "ADC10 bits, 1 LSB = 4.8828 mV";

    Member      O2SupplyMv
                Type IRIS_UINT16
                Description "Output of O2 supply pressure transducer"
                Unit "millivolts";

    Member      AirSupplyBits
                Type IRIS_UINT16
                Description "Output of Air supply pressure transducer"
                Unit "ADC10 bits, 1 LSB = 4.8828 mV";

    Member      AirSupplyMv
                Type IRIS_UINT16
                Description "Output of Air supply pressure transducer"
                Unit "millivolts";
}

/****  MESSAGE EIGHTEEN ****/

Message PortInput
{
    Description "Binary data sensed at the pins of microcontroller ports A, B, C,
    		D and E";

    Rate        "Set Clocking Period";

	Member      ExpAirwayPress
                Type IRIS_INT16
                Description "Pressure value of airway pressure transducer.  Valid
                range is from -20 to +120 cmH2O."
                Unit "cmH2O x100";

    Member      PortA
                Type IRIS_UBYTE
                Description "Data sensed at the Port A pins on the microcontroller
                     Bit 7, not used
                     Bit 6, /ADC_CS
                     Bit 5, /O2_CS
                     Bit 4, /EXCOM_CS
                     Bit 3, not used
                     Bits 2 to 0: analog multiplexer control for 10-bit ADC"
                Unit "none";

    Member      PortB
                Type IRIS_UBYTE
                Description "Data sensed at the Port B pins on the microcontroller
                     Bit 7 to 5, not used
                     Bit 4, /STROBE
                     Bit 3, MISO
                     Bit 2, MOSI
                     Bit 1, SPI_CLK
                     Bit 0, not used"
                Unit "none";

    Member      PortC
                Type IRIS_UBYTE
                Description "Data sensed at the Port C pins on the microcontroller
                     Bit 7, /UC_ACT
                     Bit 6, not used
                     Bit 5, EXHAL_OPEN
                     Bit 4, SAFE_CLSE
                     Bit 3, /ZEROINSP_DIS
                     Bit 2, /O2_ON
                     Bit 1, /EX_OFF
                     Bit 0, /BUZZER_ON"
                Unit "none";

    Member      PortD
                Type IRIS_UBYTE
                Description "Data sensed at the Port D pins on the microcontroller
                     Bits 7 to 4, not used
                     Bit 3, VMBTX_DURX
                     Bit 2, VMBRX_DUTX
                     Bit 1, EX_SDA
                     Bit 0, EX_SCL"
                Unit "none";

    Member      PortE
                Type IRIS_UBYTE
                Description "Data sensed at the Port E pins on the microcontroller
                     Bit 7, /EXC0M_RDY
                     Bit 6, /O2_RDY
                     Bit 5, /OK_TO_ZERO
                     Bit 4, /OVER_PRESS
                     Bit 3, /BUZZER_SNSE
                     Bit 2, EX_SW
                     Bit 1, VMBTX_VCBRX
                     Bit 0, VMBRX_VCBTX"
                Unit "none";
}

/**** MESSAGE NINTEEN ****/

Message OtherVmbData
{
	Description "Other Vmb Data";

    Rate        "Set Clocking Period";

    Member		ExpAirwayPress
                Type IRIS_INT16
                Description "Pressure value of airway pressure transducer.  Valid
                range is from -20 to +120 cmH2O."
                Unit "cmH2O x100";

	Member      AirPress
                Type IRIS_UBYTE
                Description "Air supply pressure.  Valid range is from 0 to 120 psig."
                Unit "psig";

    Member      O2Press
                Type IRIS_UBYTE
                Description "O2 supply pressure.  Valid range is from 0 to 120 psig."
                Unit "psig";

	Member      BaroPress
                Type IRIS_UINT16
                Description "Pressure value of barometric pressure transducer.
                Valid range is from 0 to +1088 cmH2O."
                Unit "cmH2O x10";

	Member      PerfData1
                Type IRIS_UINT16
                Description "Indication of VMB performance"
                Unit "None";

    Member      PerfData2
                Type IRIS_UBYTE
                Description "Indication of VMB performance"
                Unit "None";

	Member      ExpFlow
                Type IRIS_INT32
                Description "Measured expiratory flow.  Valid range is from 0 to
                200 L/min."
                Unit "L/min x100";

    Member      ExpFlowStatus
                Type IRIS_UINT16
                Description "Status output of expiratory flow sensor. Status
                bit = 1 indicates an active condition
                    Bits 15 to 8, not used
                    Bit 7, Checksum failure
                    Bit 6, Voltage failure (VCC/REF)
                    Bit 5, System calibration failure
                    Bit 4, Sensor calibration failure
                    Bit 3, Shutdown of hot wire
                    Bit 2, Clean sensor
                    Bit 1, Data-in-overflow (SSPOV)
                    Bit 0, Command under work (when sensor calibration)"
                Unit "none";

	Member      InspO2Pct
                Type IRIS_INT16
                Description "Uncompensated Paracube O2 measurement data"
                Unit "%*10";

    Member      ExhaledMv
                Type IRIS_UINT16
                Description "Exhaled minute volume."
                Unit "l/m x10";

	Member      ExhaledTv
                Type IRIS_UINT16
                Description "Exhaled tidal volume."
                Unit "ml";

    Member      VmbReset
                Type IRIS_UBYTE
                Description "Indicates if a VMB microcontroller reset has occurred
                since the last time the status was sent to the VCB and identifies
                the source of the last reset.
                  Status:
                    Bit 7, 1=reset occurred (bit cleared after transmission to VCB)
                  Not used:
                    Bits 6 to 5
		  Source of last microcontroller reset:
                    Bit 4, JTAG instruction
                    Bit 3, Internal watchdog timeout
                    Bit 2, Internal brown out detector
                    Bit 1, External reset applied to microcontroller
                    Bit 0, Power-on reset"
                Unit "None";

    Member      BreathRate
                Type IRIS_UBYTE
                Description "Measured breath rate"
                Unit "breaths per minute (bpm)";

	Member      TechnicalAlarms
                Type IRIS_UBYTE
                Description "Technical alarm status bits reported by the Vent Monitor Board.

				VMB CRC POST failure:
					A VMB Flash CRC POST failure will only be detected and reported by the
					VMB Boot code.  Boot code will not allow execution of Application code
					in the event of a CRC failure.  The failure information is included in
					an IRIS status response message.

				For all bits 0 = Alarm Not Active, 1 = Alarm Active.
							Bits 7 to 3, not used
					Bit 2: VMB RAM POST failure
					Bit 1: DC To VMB Comm Error
					Bit 0: not used (reserved)"
						Unit "None";

     Member     ParameterAlarms1
                Type IRIS_UBYTE
                Description "Parameter alarm status bits #2 reported by the Vent
                Monitor Board.  Status bits will remain active as long as the alarm
                condition exists.

				For all bits 0 = Alarm Not Active, 1 = Alarm Active.
					Bit  0: High Paw
					Bit  1: High Paw Plus
					Bit  2: Low Paw
    					Bit  3: Breathing Circuit Occlusion
					Bit  4: Sustained Paw
					Bit  5: Apnea
							Bit  6: MV Expired Low
					Bit  7: MV Expired High"
						Unit "None";

	 Member     ParameterAlarms2
                Type IRIS_UBYTE
                Description "Parameter alarm status bits #2 reported by the Vent
                Monitor Board.  Status bits will remain active as long as the alarm
                condition exists.

				For all bits 0 = Alarm Not Active, 1 = Alarm Active.
					Bit  0: Low FiO2
					Bit  1: High FiO2
					Bits 2 to 7, not used"
						Unit "None";

	Member      ParaStatus
                Type IRIS_UBYTE
                Description "Enum PARACUBE_STATUS, describes the current state of
                the Paracube O2 sensor."
                Unit "None";

	Member      ExhaledMvDataStatus
                Type IRIS_UBYTE
                Description "Enum DATA_STATUS, defining the Data Status for the
                named data item."
                Unit "None";

	Member      VmbSysStatus
                Type IRIS_UBYTE
                Description "The current state of system signals monitored by the VMB.
                    Bits 7 to 5, not used
                    Bit 4, /OVER_PRESS, 0=airway overpressure condition detected by
                    	   VMB hardware comparator
                    Bit 3, /BUZZER_SENSE, 0=VCB buzzer active
                    Bits 2 to 0, not used"
                Unit "none";

	Member      ExhaledTvDataStatus
                Type IRIS_UBYTE
                Description "Enum DATA_STATUS, defining the Data Status for the
                named data item."
                Unit "None";

	Member      BreathRateDataStatus
                Type IRIS_UBYTE
                Description "Enum DATA_STATUS, defining the Data Status for the
                named data item."
                Unit "none";

	Member      BreathPeriod
                Type IRIS_UBYTE
                Description "Enum TRIGGER"
                Unit "None";
}

/****  MESSAGE TWENTY ****/

Message VmbTaskInfo
{
	Description	"Measured values of internal VMB performance information.";

	Rate		"Set Clocking Period";

	Member      TaskData1
                Type IRIS_UINT16
                Description "Indication of task performance"
                Unit "None";

    Member      TaskData2
                Type IRIS_UBYTE
                Description "Indication of task performance"
                Unit "None";

    Member      TaskData3
                Type IRIS_UBYTE
                Description "Indication of task performance"
                Unit "None";
}

/****  MESSAGE TWENTY-ONE ****/

Message ParacubeData
{
    Description "Additional Paracube O2 sensor information";

    Rate        "Set Clocking Period";

	Member      ExpAirwayPress
                Type IRIS_INT16
                Description "Pressure value of airway pressure transducer.  Valid
                range is from -20 to +120 cmH2O."
                Unit "cmH2O x100";

    Member      InspO2PctComp
                Type IRIS_INT16
                Description "Uncompensated Paracube O2 measurement data.
                Valid range is from 0 to 100%."
                Unit "percent O2 x10";

    Member      SerialNum
                Type IRIS_UBYTE[8]
                Description "Serial number in ASCII format"
                Unit "none";
}

/****  MESSAGE	TWENTY-TWO ****/

Message AcutronicsInfo
{
    Description "Additional Acutronics flow sensor information";

    Rate        "Set Clocking Period";

	Member      ExpAirwayPress
                Type IRIS_INT16
                Description "Pressure value of airway pressure transducer.  Valid
                range is from -20 to +120 cmH2O."
                Unit "cmH2O x100";

    Member      SoftwareVersion
                Type IRIS_UINT16
                Description "High byte = major version, low byte = minor version"
                Unit "none";
}

/****  MESSAGE	TWENTY-THREE ****/

Message VmbSystemState
{
    Description "Send system state";

    Rate        "Set Clocking Period";

    Member      VmbSystemState
                Type IRIS_UBYTE
                Description "Enum SYSTEM_STATE, defining the system state as received
                from the DC."
                Unit "SYSTEM_STATE";
}

/****  MESSAGE TWENTY-FOUR ****/

Message SystemChecksData
{
	Description	"This message sets watchdog strobe on/off.";

	Rate		"Set Clocking Period";

	Member     	FlashPasses
                Type IRIS_UINT16
                Description	"Number of VCB Flash passes"
                Unit "None";

	Member     	FlashFailures
                Type IRIS_UINT16
                Description	"Number of VCB Flash failures"
                Unit "None";

	Member     	SramPasses
                Type IRIS_UINT16
                Description	"Number of SRAM passes"
                Unit "None";

	Member     	SramFailures
                Type IRIS_UINT16
                Description	"Number of SRAM failures"
                Unit "None";

	Member     	EEPromPasses
                Type IRIS_UINT16
                Description	"Number of EEProm passes"
                Unit "None";

	Member     	EEPromFailures
                Type IRIS_UINT16
                Description	"Number of EEProm failures"
                Unit "None";

	Member     	TimerRatio
                Type IRIS_INT16
                Description	"Timer ratio"
                Unit "None";
}

/****  MESSAGE TWENTY-FIVE ****/

Message CheckoutCircuitCheck
{
	Description	"This message receives the value of leak, compliance and resistance after running checkout";

	Rate		"Set Clocking Period";

	Member		Leak
				Type IRIS_UINT16
                Description	"Leak"
                Unit "None";

	Member		Resistance
				Type IRIS_UINT32
                Description	"Leak"
                Unit "None";

	Member		Compliance
				Type IRIS_UINT32
                Description	"Leak"
                Unit "None";
}

/****  MESSAGE TWENTY-SIX ****/
Message Level4DiagnosticLeaks
{
	Description "This message returns the leak values of the level 4 diagnostic leak tests";

	Rate "Set Clocking Period";

	Member		LowPressureLeak
				Type IRIS_UINT16
				Description "Low Pressure Leak"
				Unit "cmH20*100";

	Member		HighOxygenPressureLeak
				Type IRIS_UINT16
				Description "High Oxygen Pressure Leak"
				Unit "cmH20*100";

	Member		HighAirPressureLeak
				Type IRIS_UINT16
				Description "High Air Pressure Leak"
				Unit "cmH20*100";
}

/****  MESSAGE TWENTY-SEVEN ****/
Message GetNVMErrorLog
{
	Description "This message requests a copy of the NVM error log";

	Rate		"On Demand";

	Member		NvmLogStrc
				Type IRIS_UINT32[80]
				Description "This is a structure of 20 log entries of 16 bytes"
				Unit "None";
}

/****  MESSAGE TWENTY-EIGHT ****/
Message RegulatorTestResults
{
	Description "This message returns the results of the regulator test.";

	Rate "Set Clocking Period";

	Member		TotalFlowWithO2
				Type IRIS_INT32
				Description "Total Flow for O2 test"
				Unit "cmH20*100";

	Member		OxygenFlow
				Type IRIS_INT32
				Description "Oxygen Flow"
				Unit "cmH20*100";

	Member		OxygenPercError
				Type IRIS_UINT16
				Description "% difference error between total and oxygen flow"
				Unit "%";

	Member		TotalFlowWithAir
				Type IRIS_INT32
				Description "Total Flow for Air test"
				Unit "cmH20*100";

	Member		AirFlow
				Type IRIS_INT32
				Description "Air Flow"
				Unit "cmH20*100";

	Member		AirPercError
				Type IRIS_UINT16
				Description "% difference error between total and air flow"
				Unit "%";
}

Message CalStatus
{
    Description "Status of selected calibration sequence.
    		This message will be sent twice when a calibration request is
    		received.  The first transmission is an acknowledgement of the
    		calibration request.  The second is sent when the calibration has
    		completed and indicates the result of the calibration.
    		This message can also be requested on demand and will always
    		indicate the status of the last requested calibration.";

    Rate        "1 KHz/on request and on completion";

    Member      ExpAirwayPress
                Type IRIS_INT16
                Description "Pressure value of airway pressure transducer.  Valid
                range is from -20 to +120 cmH2O."
                Unit "cmH2O x100";

    Member      CalRequested
                Type IRIS_UBYTE
                Description "Indicates which sensor calibration has been selected.
                For all bits, 1 = calibration selected, 0 = no calibration selected.
                    Expiratory pressure sensor:
                        Bit 7, Zero calibration selected
                        Bit 6, Span calibration selected
                    Paramagnetic O2 sensor, internal calibration (must be done
                    at 20.9%, then 100%):
                        Bit 5, 20.9% O2 calibration selected
                        Bit 4, 100% O2 calibration selected
                    Paramagnetic O2 sensor, single point adjustment by VMB:
                        Bit 3, Offset calculation selected
                    Expiratory flow sensor:
                        Bit 2, Zero flow calibration selected
                    Not used:
                        Bit 1
                        Bit 0"
                Unit "None";

    Member      CurrentStatus
                Type IRIS_UBYTE
                Description "Enum CALIBRATION_STATUS, defines the current status of
                the selected calibration."
                Unit "None";
}

/**********************************************************************************
**
** VCB to Test Fixture: On demand message traffic
** --------------------------------
**
***********************************************************************************/

/****  MESSAGE ONE ****/

Message StartZeroCal
{
	Description	"This message is sent by the test to start zero calibration";

	Rate		"When button is pressed";

	Member     	DAC_Value
                Type IRIS_UINT16
                Description	"First value to be sent to the VCB for calibration purposes"
                Unit "None";
}

/****  MESSAGE TWO ****/

Message StartSpanCal
{
	Description	"This message is sent by the test to start span calibration";

	Rate		"When button is pressed";
}

/****  MESSAGE THREE ****/

Message EndSpanCal
{
	Description	"This message is sent by the test to end span calibration";

	Rate		"When button is pressed";
}

/****  MESSAGE FOUR ****/

Message StartParacubeCal
{
	Description	"This message is sent by the test to start the paracube calibration";

	Rate		"When button is pressed";

}

/****  MESSAGE FIVE ****/

Message StartExpFlowCal
{
	Description	"This message is sent by the test to start the expiratory flow calibration";

	Rate		"When button is pressed";

}

/****  MESSAGE SIX ****/

Message SetSafeClose
{
	Description	"This message switches control safety valve to on/off.";

	Rate		"When box is checked";

	Member     	Setting
                Type IRIS_UBYTE
                Description	"Set to on/off"
                Unit "None";
}

/****  MESSAGE SEVEN ****/

Message SetMnvrOpen
{
	Description	"This message switches control manuever valve to on/off.";

	Rate		"When box is checked";

	Member     	Setting
                Type IRIS_UBYTE
                Description	"Set to on/off"
                Unit "None";

}

/****  MESSAGE EIGHT ****/

Message SetOkToZero
{
	Description	"This message switches ok to zero to on/off.";

	Rate		"When box is checked";

	Member     	Setting
                Type IRIS_UBYTE
                Description	"Set to on/off"
                Unit "None";
}

/****  MESSAGE NINE ****/

Message SetSwLed
{
	Description	"This message switches sw led to on/off.";

	Rate		"When box is checked";

	Member     	Setting
                Type IRIS_UBYTE
                Description	"Set to on/off"
                Unit "None";

}

/****  MESSAGE TEN ****/

Message SetFsPwrEn
{
	Description	"This message switches flow sensor power enable to on/off.";

	Rate		"When box is checked";

	Member     	Setting
                Type IRIS_UBYTE
                Description	"Set to on/off"
                Unit "None";

}

/****  MESSAGE ELEVEN ****/

Message SetNebOn
{
	Description	"This message switches nebulizer on/off.";

	Rate		"When box is checked";

	Member     	Setting
                Type IRIS_UBYTE
                Description	"Set to on/off"
                Unit "None";

}

/****  MESSAGE TWELVE ****/

Message SetMbusReset
{
	Description	"This message switches Mbus reset to on/off.";

	Rate		"When box is checked";

	Member     	Setting
                Type IRIS_UBYTE
                Description	"Set to on/off"
                Unit "None";

}

/****  MESSAGE THIRTEEN ****/

Message SetIlimModEn
{
	Description	"This message switches ILIM_MOD_EN to on/off.";

	Rate		"When box is checked";

	Member     	Setting
                Type IRIS_UBYTE
                Description	"Set to on/off"
                Unit "None";

}

/****  MESSAGE FOURTEEN ****/

Message SetIlimPsmEn
{
	Description	"This message switches ILIM_PSM_EN to on/off.";

	Rate		"When box is checked";

	Member     	Setting
                Type IRIS_UBYTE
                Description	"Set to on/off"
                Unit "None";

}

/****  MESSAGE FIFTEEN ****/

Message SetWdStrb
{
	Description	"This message switches watchdog to on/off.";

	Rate		"When box is checked";

	Member     	Setting
                Type IRIS_UBYTE
                Description	"Set to on/off"
                Unit "None";

}

/****  MESSAGE SIXTEEN ****/

Message SetExpZero
{
	Description	"This message switches zero expiratory pressure sensor to on/off.";

	Rate		"When box is checked";

	Member     	Setting
                Type IRIS_UBYTE
                Description	"Set to on/off"
                Unit "None";

}

/****  MESSAGE SEVENTEEN ****/

Message SetAuxZero
{
	Description	"This message switches zero auxiliary pressure sensor to on/off.";

	Rate		"When box is checked";

	Member     	Setting
                Type IRIS_UBYTE
                Description	"Set to on/off"
                Unit "None";

}

/****  MESSAGE EIGHTEEN ****/

Message SetBuzzer
{
	Description	"This message switches buzzer on/off.";

	Rate		"When box is checked";

	Member     	Setting
                Type IRIS_UBYTE
                Description	"Set to on/off"
                Unit "None";

}

/****  MESSAGE NINETEEN ****/

Message SetAirValveEn
{
	Description	"This message switches air valve on/off.";

	Rate		"When box is checked";

	Member     	Setting
                Type IRIS_UBYTE
                Description	"Set to on/off"
                Unit "None";

}

/****  MESSAGE TWENTY ****/

Message SetO2ValveEn
{
	Description	"This message switches oxygen valve on/off.";

	Rate		"When box is checked";

	Member     	Setting
                Type IRIS_UBYTE
                Description	"Set to on/off"
                Unit "None";

}

/****  MESSAGE TWENTY-ONE ****/

Message SetExhValveEn
{
	Description	"This message switches exhalation valve on/off.";

	Rate		"When box is checked";

	Member     	Setting
                Type IRIS_UBYTE
                Description	"Set to on/off"
                Unit "None";

}

/****  MESSAGE TWENTY-TWO ****/

Message SendEEPromTest
{
	Description	"This message tests the EEProm";

	Rate		"When button is pressed";
}

/****  MESSAGE TWENTY-THREE ****/

Message EEPromTestProgress
{
	Description	"This message gets the progress for the EEProm test";

	Rate		"When button is pressed";

	Member     	Progress
                Type IRIS_UINT16
                Description	"Progress of the EEProm test"
                Unit "Percent";
}

/****  MESSAGE TWENTY-FOUR ****/

Message SetVmbBuzzerOn
{
	Description	"This message sets buzzer on/off.";

	Rate		"When box is checked";

	Member     	Setting
                Type IRIS_UBYTE
                Description	"Set to on/off"
                Unit "None";

}

/****  MESSAGE TWENTY-FIVE ****/

Message SetVmbExhalOpen
{
	Description	"This message sets exhal open/close.";

	Rate		"When box is checked";

	Member     	Setting
                Type IRIS_UBYTE
                Description	"Set to on/off"
                Unit "None";

}

/****  MESSAGE TWENTY-SIX ****/

Message SetVmbExOn
{
	Description	"This message sets ex on/off.";

	Rate		"When box is checked";

	Member     	Setting
                Type IRIS_UBYTE
                Description	"Set to on/off"
                Unit "None";

}

/****  MESSAGE TWENTY-SEVEN ****/

Message SetVmbO2On
{
	Description	"This message sets O2 on/off.";

	Rate		"When box is checked";

	Member     	Setting
                Type IRIS_UBYTE
                Description	"Set to on/off"
                Unit "None";

}

/****  MESSAGE TWENTY-EIGHT ****/

Message SetVmbSafeClse
{
	Description	"This message sets safe close on/off.";

	Rate		"When box is checked";

	Member     	Setting
                Type IRIS_UBYTE
                Description	"Set to on/off"
                Unit "None";

}

/****  MESSAGE TWENTY-NINE ****/

Message SetVmbSwLed
{
	Description	"This message sets sw led on/off.";

	Rate		"When box is checked";

	Member     	Setting
                Type IRIS_UBYTE
                Description	"Set to on/off"
                Unit "None";

}

/****  MESSAGE THIRTY ****/

Message SetVmbWdStrobe
{
	Description	"This message sets watchdog strobe on/off.";

	Rate		"When box is checked";

	Member     	Setting
                Type IRIS_UBYTE
                Description	"Set to on/off"
                Unit "None";

}

/****  MESSAGE THIRTY-ONE ****/

Message InitializeVmbOutputs
{
	Description	"This message initializes the bits for the vmb outputs";

	Rate		"When the test program starts up and the vmb resets";

	Member     	Bit
                Type IRIS_UBYTE
                Description	"Set to default value"
                Unit "None";
}

/****  MESSAGE THIRTY-TWO ****/

Message SendInterrupt
{
	Description	"This message causes one interrupt on the VCB";

	Rate		"When button is pressed";
}

/****  MESSAGE THIRTY-THREE ****/

Message StopWdResetVcb
{
	Description	"Stops the watchdog from servicing and resets the VCB";

	Rate		"When button is pressed";
}

/****  MESSAGE THIRTY-FOUR ****/

Message StartCheckoutCal
{
	Description	"This message is sent by the test to start the checkout";

	Rate		"When button is pressed";

}

/****  MESSAGE THIRTY-FIVE ****/
Message TaskMonitor
{
	Description	"Specifies CMX task to be monitored for performance evaluation.";

	Rate		"on demand";

	Member		TaskNum
				Type IRIS_UBYTE
				Description "Enum CMX_TASK"
				Unit "None";
}

/****  MESSAGE THIRTY-SIX ****/
Message StartHighAirLeak
{
	Description	"This message is sent to start the high air leak test";

	Rate		"When button is pressed";
}

/****  MESSAGE THIRTY-SEVEN ****/
Message StartHighO2Leak
{
	Description	"This message is sent to start the high O2 leak test";

	Rate		"When button is pressed";
}

/****  MESSAGE THIRTY-EIGHT ****/
Message StartLowPLeak
{
	Description	"This message is sent to start the low pressure leak test";

	Rate		"When button is pressed";
}

/****  MESSAGE THIRTY-NINE ****/
Message StartAirCal
{
	Description	"This message is sent by the test to start air calibration";

	Rate		"When button is pressed";
}

/****  MESSAGE FORTY ****/
Message StartOxygenCal
{
	Description	"This message is sent by the test to start oxygen calibration";

	Rate		"When button is pressed";
}

/****  MESSAGE FORTY-ONE ****/
Message StartExhCal
{
	Description	"This message is sent by the test to start exhalation calibration";

	Rate		"When button is pressed";

}

/****  MESSAGE FORTY-TWO ****/
Message GetCalibrationTables
{
	Description	"This message is sent by the test to get Air, O2 and Exh calibration tables";

	Rate		"When button is pressed";

	Member		AirValveCalFlowData
				Type IRIS_UINT32[23]
                Description "Air Valve - Flow values in calibration table."
                Unit "None";

	Member		AirValveCalCountsData
				Type IRIS_UINT16[23]
                Description "Air Valve - Counts in calibration table."
                Unit "None";

	Member		O2ValveCalFlowData
				Type IRIS_UINT32[23]
                Description "O2 Valve - Flow values in calibration table."
                Unit "None";

	Member		O2ValveCalCountsData
				Type IRIS_UINT16[23]
                Description "O2 Valve - Counts in calibration table."
                Unit "None";

	Member		ExhValveCalPressureData
				Type IRIS_UINT16[16]
                Description "Exh Valve - Pressure values in calibration table."
                Unit "None";

	Member		ExhValveCalCountsData
				Type IRIS_UINT16[16]
                Description "Exh Valve - Counts in calibration table."
                Unit "None";
}

/****  MESSAGE FORTY-THREE ****/
Message DataRequestMicroEeprom
{
    Description "Requests the data contained in sixteen consecutive locations of
    		the EEPROM located in the VMB microcontroller.  The starting address
    		of the EEPROM data is specified.";

    Rate        "On Demand";

    Member      StartAddr
                Type IRIS_UINT16
                Description "Starting address for the EEPROM data.  Valid range
                is 0 to 0xFF0"
                Unit "None";
}

/****  MESSAGE FORTY-FOUR ****/
Message ClearEepromLog
{
	Description "Request to clear the eeprom";

	Rate		"On Demand";

	Member		Address
				Type IRIS_UINT16
                Description "Address for clearing the EEPROM data.  Valid range
                is 0 to 0xFF0"
                Unit "None";
}

/****  MESSAGE FORTY-FIVE ****/
Message StartValveSweepCal
{
	Description	"This message is sent by the test to start valve sweep calibration";

	Rate		"When button is pressed";

}

/****  MESSAGE	FORTY-SIX ****/
Message BurnHardwareRevInformation
{
    Description "Sent by test package to burn hardware rev information";

    Rate        "On Demand";

	Member		PartNumRev
				Type IRIS_BYTE[20]
				Description "Part Number"
				Unit "String";

	Member		SerialNum
				Type IRIS_BYTE[8]
				Description "Serial Number"
				Unit "String";

    Member      BoardType
                Type IRIS_UBYTE
                Description "Enumeration BOARD_TYPE indicates VCB or VMB"
                Unit "BOARD_TYPE";
}

/**** MESSAGE FORTY-SEVEN ****/
Message GetVcbHardwareRevInfo
{
	Description "Get existing hardware rev information";

	Rate		"On Demand";

	Member		PartNumRev
				Type IRIS_UBYTE[20]
				Description "Part Number"
				Unit "String";

	Member		SerialNum
				Type IRIS_UBYTE[8]
				Description "Serial Number"
				Unit "String";
}

/****  MESSAGE	FORTY-EIGHT ****/
Message MicroEeprom
{
    Description "Data contained in sixteen consecutive locations of the EEPROM
    		located in the VMB microcontroller.  The starting address of the
    		EEPROM data is specified.";

    Rate        "On Demand";

    Member      ExpAirwayPress
                Type IRIS_INT16
                Description "Pressure value of airway pressure transducer.  Valid
                range is from -20 to +120 cmH2O."
                Unit "cmH2O x100";

    Member      StartAddr
                Type IRIS_UINT16
                Description "Starting address for the EEPROM data.  Valid range
                is 0 to 0xFF0"
                Unit "None";

    Member      Data
                Type IRIS_UBYTE[16]
                Description "Sixteen EEPROM data bytes in consecutive order, starting
                from the specified address"
                Unit "None";
}

/****  MESSAGE	FORTY-NINE ****/
Message ClearNVMErrorLog
{
    Description	"Clears the NVM Error Log";

	Rate		"On Demand";
}

/****  MESSAGE FIFTY ****/
Message StartExpiratoryValveSweepCal
{
	Description	"This message is sent by the test to start expiratory valve sweep calibration";

	Rate		"When button is pressed";

	Member		Dither
				Type IRIS_UINT16
                Description "Dither value to send to expiratory valve sweep cal"
                Unit "None";

	Member		Flow
				Type IRIS_INT32
                Description "Dither value to send to expiratory valve sweep cal"
                Unit "None";
}

/****  MESSAGE FIFTY-ONE ****/
Message StartRegulatorStep
{
	Description	"This message is sent by the test to start the regulator step test";

	Rate		"When button is pressed";
}

/****  MESSAGE FIFTY-TWO ****/
Message StartBaroPressCal
{
	Description	"This message is sent by the test to the VMB to cal the baro pressure transducer ";

	Rate		"When button is pressed";

	Member		UserPressure
				Type IRIS_INT16
				Description "Pressure value used calculate new gain for baro pressure transducer"
                Unit "cmH2O*10";
}

/****  MESSAGE FIFTY-THREE ****/
Message SetVmbExpZeroOpen
{
	Description	"This message sets expiratory zero valve open/close";

	Rate		"When checkbox is changed";

	Member     	Setting
                Type IRIS_UBYTE
                Description	"Set to 1=open/0=close"
                Unit "None";
}

/**** MESSAGE FIFTY-FOUR ****/
Message GetSystemSoftwareVersionInfo
{
	Description "Get System Software Version";

	Rate		"On Demand";

	Member		SoftwareVersion
				Type IRIS_UINT16
				Description "System Software Version"
				Unit "None";

	Member		BuildNumber
				Type IRIS_UINT16
				Description "Build number"
				Unit "None";
}

/****  MESSAGE FIFTY-FIVE ****/

Message SendExpansionInspDac
{
	Description "This message is to send the DAC Value for the Expansion Insp DAC (NFS)";

	Rate		"Set Clocking Period";

	Member     	DAC_Value
                Type IRIS_UINT16
                Description	"Sent for flow sensor zeroing purposes"
                Unit "None";
}

/****  MESSAGE FIFTY-SIX ****/

Message SendExpansionExpDac
{
	Description "This message is to send the DAC Value for the Expansion Exp DAC (NFS)";

	Rate		"Set Clocking Period";

	Member     	DAC_Value
                Type IRIS_UINT16
                Description	"Sent for flow sensor zeroing purposes"
                Unit "None";
}

/****  MESSAGE FIFTY-SEVEN ****/

Message NeonFlowSensorInfo
{
	Description "Flow Info for Neonatal Flow Sensor.";

	Rate		"Set Clocking Period";

	Member		InspFlowCounts
				Type IRIS_UINT16
				Description "Inspiratory Flow Counts"
				Unit "mLPM in Counts";

	Member		InspZeroDac
				Type IRIS_UINT16
				Description "Last Inspiratory Flow DAC used to achieve zero"
				Unit "None";

	Member		ExpFlowCounts
				Type IRIS_UINT16
				Description "Expiratory Flow Counts"
				Unit "mLPM in Counts";

	Member		ExpZeroDac
				Type IRIS_UINT16
				Description "Last Expiratory DAC used to achieve zero"
				Unit "mLPM in Counts";

	Member		NetFlowValue
				Type IRIS_INT32
				Description "Neon Net Flow"
				Unit "Flow in mL";

	Member		ZeroCounts
				Type IRIS_UINT16
				Description "Zero counts used for last zero procedure"
				Unit "Dac Counts";

	Member		InspZeroOffset
				Type IRIS_INT32
				Description "Current insp DAC offset since last zero procedure"
				Unit "Dac Counts";

	Member		ExpZeroOffset
				Type IRIS_INT32
				Description "Current exp DAC offset since last zero procedure"
				Unit "Dac Counts";

	Member		NeonTVi
				Type IRIS_INT32
				Description "Last TVi measured from NFS"
				Unit "mL";

	Member		NeonTVe
				Type IRIS_INT32
				Description "Last TVe measured from NFS"
				Unit "mL";

	Member		VentTVi
				Type IRIS_INT32
				Description "Last TVi measured from vent insp/exp sensors"
				Unit "mL";

	Member		VentTVe
				Type IRIS_INT32
				Description "Last TVe measured from vent insp/exp sensors"
				Unit "mL";

	Member		InspReverseTV
				Type IRIS_INT32
				Description "Exp volume detected from NFS during the last insp phase"
				Unit "mL";
}

/****  MESSAGE FIFTY-EIGHT ****/

Message ZeroNeonatalFlowSensor
{
	Description "Perform the zero procedure on the neonatal flow sensor";

	Rate		"On Demand";
}

/****  MESSAGE FIFTY-NINE ****/

Message FlowControlValveBiasCounts
{
	Description "Air and O2 FCV Bias Count Data";

	Rate		"Set Clocking Period";

	Member     	AirValveBias
                Type IRIS_INT16
                Description	"Air Valve bias shift (dac counts)"
                Unit "Dac Counts";

	Member     	O2ValveBias
                Type IRIS_INT16
                Description	"O2 Valve bias shift (dac counts)"
                Unit "Dac Counts";
}

/****  MESSAGE SIXTY ****/

Message VistaInfo
{
	Description "Vista Debug Info";

	Rate		"Set Clocking Period";

	Member     	LastLoop
                Type IRIS_UBYTE
                Description	"Sequence number of the last loop sent to the DU"
                Unit "none";

	Member     	LastCurve
                Type IRIS_UBYTE
                Description	"Sequence number of the last curve sent to the DU"
                Unit "none";

	Member     	InvalidData
                Type IRIS_UBYTE
                Description	"Reason for invalid data (numeric code)"
                Unit "none";

	Member     	SpontRpat
                Type IRIS_UINT32
                Description	"Calculated spontaneous patient resistance"
                Unit "cmH2O  / mLpm";

	Member     	VistaDebugMsg
                Type IRIS_BYTE[40]
                Description	"Vista debug output messges, separated by ,"
                Unit "None";
}

/****  MESSAGE SIXTY-ONE ****/

Message VmbNeonData
{
    Description "VMB-measured expiratory and inspiratory flow data from the
                neonatal flow sensor.";

    Rate        "Set Clocking Period";

    Member      ExpHotBits
                Type IRIS_UINT16
                Description "Measured output of hot wire sensing circuit for
                expiratory flow"
                Unit "ADC12 bits, 1 LSB = 1.0669 mV";

    Member      ExpFlow
                Type IRIS_UINT16
                Description "Expiratory flow measured by the neonatal sensor,
                corrected for altitude and temperature.  Valid range is from 0
                to 32 L/min."
                Unit "mL/min";

    Member      InspHotBits
                Type IRIS_UINT16
                Description "Measured output of hot wire sensing circuit for
                inspiratory flow"
                Unit "ADC12 bits, 1 LSB = 1.0669 mV";

    Member      InspFlow
                Type IRIS_UINT16
                Description "Inspiratory flow measured by the neonatal sensor,
                corrected for altitude and temperature.  Valid range is from 0
                to 32 L/min."
                Unit "mL/min";

    Member      ZeroFlowOffset
                Type IRIS_INT16
                Description "Flow offset value to be added to the neonatal flow sensor
                A/D conversion result.  The resulting sum will be forced to zero if
                negative and will be used as the index into the flow conversion table.
                VCB and VMB flow measurement ADC bit weights must be identical."
                Unit "ADC12 bits, 1 LSB = 4370/4096 mV";
}

/**** MESSAGE SIXTY-TWO ****/
Message GetVmbHardwareRevInfo
{
	Description "Get existing hardware rev information";

	Rate		"On Demand";

	Member		PartNumRev
				Type IRIS_UBYTE[20]
				Description "Part Number"
				Unit "String";

	Member		SerialNum
				Type IRIS_UBYTE[8]
				Description "Serial Number"
				Unit "String";
}