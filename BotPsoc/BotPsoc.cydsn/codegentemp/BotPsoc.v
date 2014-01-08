// ======================================================================
// BotPsoc.v generated from TopDesign.cysch
// 01/06/2014 at 12:15
// This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
// ======================================================================

/* -- WARNING: The following section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_DIE_LEOPARD 1
`define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3
`define CYDEV_CHIP_REV_LEOPARD_ES3 3
`define CYDEV_CHIP_REV_LEOPARD_ES2 1
`define CYDEV_CHIP_REV_LEOPARD_ES1 0
`define CYDEV_CHIP_DIE_PSOC4A 2
`define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17
`define CYDEV_CHIP_REV_PSOC4A_ES0 17
`define CYDEV_CHIP_DIE_PANTHER 3
`define CYDEV_CHIP_REV_PANTHER_PRODUCTION 1
`define CYDEV_CHIP_REV_PANTHER_ES1 1
`define CYDEV_CHIP_REV_PANTHER_ES0 0
`define CYDEV_CHIP_DIE_PSOC5LP 4
`define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0
`define CYDEV_CHIP_REV_PSOC5LP_ES0 0
`define CYDEV_CHIP_DIE_EXPECT 4
`define CYDEV_CHIP_REV_EXPECT 0
`define CYDEV_CHIP_DIE_ACTUAL 4
/* -- WARNING: The previous section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_FAMILY_PSOC4 2
`define CYDEV_CHIP_MEMBER_4A 2
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_FAMILY_PSOC5 3
`define CYDEV_CHIP_MEMBER_5A 3
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_MEMBER_5B 4
`define CYDEV_CHIP_REVISION_5B_PRODUCTION 0
`define CYDEV_CHIP_REVISION_5B_ES0 0
`define CYDEV_CHIP_FAMILY_USED 3
`define CYDEV_CHIP_MEMBER_USED 4
`define CYDEV_CHIP_REVISION_USED 0
// Component: B_SPI_Slave_v2_60
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_SPI_Slave_v2_60"
`include "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_SPI_Slave_v2_60\B_SPI_Slave_v2_60.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_SPI_Slave_v2_60"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_SPI_Slave_v2_60\B_SPI_Slave_v2_60.v"
`endif

// Component: cy_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`endif

// Component: not_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0\not_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0\not_v1_0.v"
`endif

// SPI_Slave_v2_60(BidirectMode=false, ClockInternal=false, ControlFileName=SPI_Slave_Default.ctl, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG8, CyGetRegReplacementString_1=CY_GET_REG8, CyGetRegReplacementString_2=CY_GET_REG8, CySetRegReplacementString=CY_SET_REG8, DesiredBitRate=1000000, FixedPlacementEnabled=false, InternalInterruptEnabled=0, InternalRxInterruptEnabled=0, InternalTxInterruptEnabled=0, InterruptOnByteComplete=false, InterruptOnDone=false, InterruptOnRXEmpty=false, InterruptOnRXFull=false, InterruptOnRXNotEmpty=true, InterruptOnRXOverrun=false, InterruptOnTXEmpty=true, InterruptOnTXFull=false, InterruptOnTXNotFull=false, IntOnByteComp=0, IntOnRXEmpty=0, IntOnRXFull=0, IntOnRXNotEmpty=1, IntOnRXOver=0, IntOnSPIDone=0, IntOnTXEmpty=1, IntOnTXFull=0, IntOnTXNotFull=0, Mode=0, ModeUseZero=1, MultiSlaveEnable=false, NumberOfDataBits=8, PSoC3_ES2_PSoC5_ES1=false, RegDefReplacementString=reg8, RegSizeReplacementString=uint8, RxBufferSize=4, ShiftDir=0, SiliconRevisionReplacementString=es3, TxBufferSize=4, UseInternalInterrupt=false, UseRxInternalInterrupt=false, UseTxInternalInterrupt=false, VerilogSectionReplacementString=sR8, CY_COMPONENT_NAME=SPI_Slave_v2_60, CY_CONTROL_FILE=SPI_Slave_Default.ctl, CY_FITTER_NAME=PiComs, CY_INSTANCE_SHORT_NAME=PiComs, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=60, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=PiComs, )
module SPI_Slave_v2_60_0 (
    ss,
    mosi,
    sclk,
    miso,
    clock,
    tx_interrupt,
    sdat,
    rx_interrupt,
    miso_oe,
    reset);
    input       ss;
    input       mosi;
    input       sclk;
    output      miso;
    input       clock;
    output      tx_interrupt;
    inout       sdat;
    output      rx_interrupt;
    output      miso_oe;
    input       reset;

    parameter NumberOfDataBits = 8;
    parameter ShiftDir = 0;

          wire  Net_131;
          wire  Net_89;
          wire  Net_81;
          wire  Net_77;
          wire  Net_75;
          wire  miso_wire;
          wire  Net_146;

    B_SPI_Slave_v2_60 BSPIS (
        .mosi(Net_75),
        .sclk(sclk),
        .ss(ss),
        .miso(miso_wire),
        .reset(reset),
        .clock(Net_81),
        .tx_interpt(tx_interrupt),
        .tx_enable(Net_146),
        .rx_interpt(rx_interrupt));
    defparam BSPIS.BidirectMode = 0;
    defparam BSPIS.ModeCPHA = 0;
    defparam BSPIS.ModePOL = 0;
    defparam BSPIS.NumberOfDataBits = 8;
    defparam BSPIS.ShiftDir = 0;

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_75 = mosi;

	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign Net_81 = clock;


    assign miso_oe = ~ss;


    assign miso = miso_wire;


endmodule

// Component: cy_constant_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`endif

// Component: LUT_v1_50
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\LUT_v1_50"
`include "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\LUT_v1_50\LUT_v1_50.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\LUT_v1_50"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\LUT_v1_50\LUT_v1_50.v"
`endif

// Component: OneTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal\OneTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal\OneTerminal.v"
`endif

// Component: ZeroTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`endif

// PWM_v3_0(CaptureMode=0, Compare1_16=false, Compare1_8=false, Compare2_16=false, Compare2_8=false, CompareStatusEdgeSense=true, CompareType1=1, CompareType1Software=0, CompareType2=1, CompareType2Software=0, CompareValue1=0, CompareValue2=63, CONTROL3=1, ControlReg=false, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG16, CySetRegReplacementString=CY_SET_REG16, DeadBand=0, DeadBand2_4=0, DeadBand256=0, DeadBandUsed=0, DeadTime=1, DitherOffset=0, EnableMode=0, FF16=true, FF8=false, FixedFunction=true, FixedFunctionUsed=1, InterruptOnCMP1=false, InterruptOnCMP2=false, InterruptOnKill=false, InterruptOnTC=false, IntOnCMP1=0, IntOnCMP2=0, IntOnKill=0, IntOnTC=0, KillMode=1, KillModeMinTime=0, MinimumKillTime=1, OneCompare=true, Period=65535, PWMMode=0, PWMModeCenterAligned=0, RegDefReplacementString=reg16, RegSizeReplacementString=uint16, Resolution=16, RstStatusReplacementString=sSTSReg_rstSts, RunMode=0, Status=false, TriggerMode=0, UDB16=false, UDB8=false, UseControl=true, UseInterrupt=false, UseStatus=false, VerilogSectionReplacementString=sP16, CY_COMPONENT_NAME=PWM_v3_0, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=LMotorPwm, CY_INSTANCE_SHORT_NAME=LMotorPwm, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=0, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=LMotorPwm, )
module PWM_v3_0_1 (
    pwm2,
    tc,
    clock,
    reset,
    pwm1,
    interrupt,
    capture,
    kill,
    enable,
    trigger,
    cmp_sel,
    pwm,
    ph1,
    ph2);
    output      pwm2;
    output      tc;
    input       clock;
    input       reset;
    output      pwm1;
    output      interrupt;
    input       capture;
    input       kill;
    input       enable;
    input       trigger;
    input       cmp_sel;
    output      pwm;
    output      ph1;
    output      ph2;

    parameter Resolution = 16;

          wire  Net_114;
          wire  Net_113;
          wire  Net_107;
          wire  Net_96;
          wire  Net_55;
          wire  Net_57;
          wire  Net_101;
          wire  Net_54;
          wire  Net_63;

    cy_psoc3_timer_v1_0 PWMHW (
        .timer_reset(reset),
        .capture(capture),
        .enable(Net_113),
        .kill(Net_107),
        .clock(clock),
        .tc(Net_63),
        .compare(Net_57),
        .interrupt(Net_54));

	// vmCompare (cy_virtualmux_v1_0)
	assign pwm = Net_57;

	// vmIRQ (cy_virtualmux_v1_0)
	assign interrupt = Net_54;

	// vmTC (cy_virtualmux_v1_0)
	assign tc = Net_63;

    OneTerminal OneTerminal_1 (
        .o(Net_113));

	// FFKillMux (cy_virtualmux_v1_0)
	assign Net_107 = kill;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_114));



endmodule

// PWM_v3_0(CaptureMode=0, Compare1_16=false, Compare1_8=false, Compare2_16=false, Compare2_8=false, CompareStatusEdgeSense=true, CompareType1=1, CompareType1Software=0, CompareType2=1, CompareType2Software=0, CompareValue1=0, CompareValue2=63, CONTROL3=1, ControlReg=false, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG16, CySetRegReplacementString=CY_SET_REG16, DeadBand=0, DeadBand2_4=0, DeadBand256=0, DeadBandUsed=0, DeadTime=1, DitherOffset=0, EnableMode=0, FF16=true, FF8=false, FixedFunction=true, FixedFunctionUsed=1, InterruptOnCMP1=false, InterruptOnCMP2=false, InterruptOnKill=false, InterruptOnTC=false, IntOnCMP1=0, IntOnCMP2=0, IntOnKill=0, IntOnTC=0, KillMode=1, KillModeMinTime=0, MinimumKillTime=1, OneCompare=true, Period=65535, PWMMode=0, PWMModeCenterAligned=0, RegDefReplacementString=reg16, RegSizeReplacementString=uint16, Resolution=16, RstStatusReplacementString=sSTSReg_rstSts, RunMode=0, Status=false, TriggerMode=0, UDB16=false, UDB8=false, UseControl=true, UseInterrupt=false, UseStatus=false, VerilogSectionReplacementString=sP16, CY_COMPONENT_NAME=PWM_v3_0, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=RMotorPwm, CY_INSTANCE_SHORT_NAME=RMotorPwm, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=0, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=RMotorPwm, )
module PWM_v3_0_2 (
    pwm2,
    tc,
    clock,
    reset,
    pwm1,
    interrupt,
    capture,
    kill,
    enable,
    trigger,
    cmp_sel,
    pwm,
    ph1,
    ph2);
    output      pwm2;
    output      tc;
    input       clock;
    input       reset;
    output      pwm1;
    output      interrupt;
    input       capture;
    input       kill;
    input       enable;
    input       trigger;
    input       cmp_sel;
    output      pwm;
    output      ph1;
    output      ph2;

    parameter Resolution = 16;

          wire  Net_114;
          wire  Net_113;
          wire  Net_107;
          wire  Net_96;
          wire  Net_55;
          wire  Net_57;
          wire  Net_101;
          wire  Net_54;
          wire  Net_63;

    cy_psoc3_timer_v1_0 PWMHW (
        .timer_reset(reset),
        .capture(capture),
        .enable(Net_113),
        .kill(Net_107),
        .clock(clock),
        .tc(Net_63),
        .compare(Net_57),
        .interrupt(Net_54));

	// vmCompare (cy_virtualmux_v1_0)
	assign pwm = Net_57;

	// vmIRQ (cy_virtualmux_v1_0)
	assign interrupt = Net_54;

	// vmTC (cy_virtualmux_v1_0)
	assign tc = Net_63;

    OneTerminal OneTerminal_1 (
        .o(Net_113));

	// FFKillMux (cy_virtualmux_v1_0)
	assign Net_107 = kill;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_114));



endmodule

// Component: CyControlReg_v1_70
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_70"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_70\CyControlReg_v1_70.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_70"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_70\CyControlReg_v1_70.v"
`endif

// top
module top ;

          wire  Net_510;
          wire  Net_508;
          wire  Net_488;
          wire  Net_486;
          wire  Net_469;
          wire  Net_468;
          wire  Net_467;
          wire  Net_466;
          wire  Net_465;
          wire  Net_464;
          wire  Net_463;
          wire  Net_462;
          wire  Net_461;
          wire  Net_460;
          wire  Net_459;
          wire  Net_427;
          wire  Net_458;
          wire  Net_457;
          wire  Net_456;
          wire  Net_455;
          wire  Net_454;
          wire  Net_420;
          wire  Net_419;
    electrical  Net_235;
    electrical  Net_472;
    electrical  Net_135;
    electrical  Net_473;
          wire  Net_412;
          wire  Net_411;
          wire  Net_409;
          wire  Net_408;
          wire  Net_407;
          wire  Net_405;
          wire  Net_404;
          wire  Net_403;
          wire  Net_402;
          wire  Net_401;
          wire  Net_406;
    electrical  Net_253;
    electrical  Net_476;
    electrical  Net_252;
          wire  Net_399;
    electrical  Net_477;
          wire  Net_336;
          wire  Net_335;
          wire  Net_334;
          wire  Net_333;
          wire  Net_332;
          wire  Net_331;
          wire  Net_330;
          wire  Net_356;
          wire  Net_355;
          wire  Net_354;
          wire  Net_353;
          wire  Net_352;
          wire  Net_351;
          wire  Net_350;
          wire  Net_88;
          wire  Net_87;
          wire  Net_58;
          wire  Net_82;
          wire  Net_81;
          wire  Net_55;
          wire  Net_74;
          wire  Net_72;
          wire  Net_50;
          wire  Net_509;
          wire  Net_506;
          wire  Net_49;
          wire  Net_46;
          wire  Net_47;
          wire  Net_48;
          wire  Net_444;
          wire  Net_328;
          wire  Net_329;
          wire  Net_447;
          wire  Net_431;
          wire  Net_418;
          wire  Net_327;
          wire  Net_474;
          wire  Net_475;
          wire  Net_151;
          wire  Net_150;
          wire  Net_470;
          wire  Net_471;
          wire  Net_234;
          wire  Net_146;
    electrical  Net_128;
    electrical  Net_109;
    electrical  Net_120;
    electrical  Net_119;
    electrical  Net_115;
    electrical  Net_112;
          wire  Net_482;
          wire  Net_484;

	wire [0:0] tmpOE__Debug0_net;
	wire [0:0] tmpFB_0__Debug0_net;
	wire [0:0] tmpIO_0__Debug0_net;
	wire [0:0] tmpINTERRUPT_0__Debug0_net;
	electrical [0:0] tmpSIOVREF__Debug0_net;

	cy_psoc3_pins_v1_10
		#(.id("52f31aa9-2f0a-497d-9a1f-1424095e13e6"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		Debug0
		 (.oe(tmpOE__Debug0_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Debug0_net[0:0]}),
		  .io({tmpIO_0__Debug0_net[0:0]}),
		  .siovref(tmpSIOVREF__Debug0_net),
		  .interrupt({tmpINTERRUPT_0__Debug0_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Debug0_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Debug1_net;
	wire [0:0] tmpFB_0__Debug1_net;
	wire [0:0] tmpIO_0__Debug1_net;
	wire [0:0] tmpINTERRUPT_0__Debug1_net;
	electrical [0:0] tmpSIOVREF__Debug1_net;

	cy_psoc3_pins_v1_10
		#(.id("7f8ba9b1-e6f7-45c0-b01d-5f32ddc74dfe"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		Debug1
		 (.oe(tmpOE__Debug1_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Debug1_net[0:0]}),
		  .io({tmpIO_0__Debug1_net[0:0]}),
		  .siovref(tmpSIOVREF__Debug1_net),
		  .interrupt({tmpINTERRUPT_0__Debug1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Debug1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    SPI_Slave_v2_60_0 PiComs (
        .mosi(Net_46),
        .sclk(Net_47),
        .ss(Net_48),
        .miso(Net_49),
        .clock(Net_50),
        .tx_interrupt(Net_484),
        .sdat(Net_72),
        .rx_interrupt(Net_482),
        .miso_oe(Net_74),
        .reset(Net_55));
    defparam PiComs.NumberOfDataBits = 8;
    defparam PiComs.ShiftDir = 0;


	cy_dma_v1_0
		#(.drq_type(2'b00))
		SpiXmitDma
		 (.drq(Net_484),
		  .trq(1'b0),
		  .nrq(Net_82));


	wire [0:0] tmpOE__PiSPI_MOSI_net;
	wire [0:0] tmpIO_0__PiSPI_MOSI_net;
	wire [0:0] tmpINTERRUPT_0__PiSPI_MOSI_net;
	electrical [0:0] tmpSIOVREF__PiSPI_MOSI_net;

	cy_psoc3_pins_v1_10
		#(.id("4c15b41e-e284-4978-99e7-5aaee19bd0ce"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b00),
		  .width(1))
		PiSPI_MOSI
		 (.oe(tmpOE__PiSPI_MOSI_net),
		  .y({1'b0}),
		  .fb({Net_46}),
		  .io({tmpIO_0__PiSPI_MOSI_net[0:0]}),
		  .siovref(tmpSIOVREF__PiSPI_MOSI_net),
		  .interrupt({tmpINTERRUPT_0__PiSPI_MOSI_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PiSPI_MOSI_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__PiSPI_SCLK_net;
	wire [0:0] tmpIO_0__PiSPI_SCLK_net;
	wire [0:0] tmpINTERRUPT_0__PiSPI_SCLK_net;
	electrical [0:0] tmpSIOVREF__PiSPI_SCLK_net;

	cy_psoc3_pins_v1_10
		#(.id("ba473d3a-49b3-4f06-8a28-0fcda8af6039"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b00),
		  .width(1))
		PiSPI_SCLK
		 (.oe(tmpOE__PiSPI_SCLK_net),
		  .y({1'b0}),
		  .fb({Net_47}),
		  .io({tmpIO_0__PiSPI_SCLK_net[0:0]}),
		  .siovref(tmpSIOVREF__PiSPI_SCLK_net),
		  .interrupt({tmpINTERRUPT_0__PiSPI_SCLK_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PiSPI_SCLK_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__PiSPI_SS_net;
	wire [0:0] tmpIO_0__PiSPI_SS_net;
	wire [0:0] tmpINTERRUPT_0__PiSPI_SS_net;
	electrical [0:0] tmpSIOVREF__PiSPI_SS_net;

	cy_psoc3_pins_v1_10
		#(.id("792a292b-6d33-426c-8811-0706c32bbec7"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b00),
		  .width(1))
		PiSPI_SS
		 (.oe(tmpOE__PiSPI_SS_net),
		  .y({1'b0}),
		  .fb({Net_48}),
		  .io({tmpIO_0__PiSPI_SS_net[0:0]}),
		  .siovref(tmpSIOVREF__PiSPI_SS_net),
		  .interrupt({tmpINTERRUPT_0__PiSPI_SS_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PiSPI_SS_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__PiSPI_MISO_net;
	wire [0:0] tmpFB_0__PiSPI_MISO_net;
	wire [0:0] tmpIO_0__PiSPI_MISO_net;
	wire [0:0] tmpINTERRUPT_0__PiSPI_MISO_net;
	electrical [0:0] tmpSIOVREF__PiSPI_MISO_net;

	cy_psoc3_pins_v1_10
		#(.id("d8190f24-3d81-4c67-a2d7-769222f9f1c9"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		PiSPI_MISO
		 (.oe(tmpOE__PiSPI_MISO_net),
		  .y({Net_49}),
		  .fb({tmpFB_0__PiSPI_MISO_net[0:0]}),
		  .io({tmpIO_0__PiSPI_MISO_net[0:0]}),
		  .siovref(tmpSIOVREF__PiSPI_MISO_net),
		  .interrupt({tmpINTERRUPT_0__PiSPI_MISO_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PiSPI_MISO_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_clock_v1_0
		#(.id("e0f7effe-c87d-4c77-863b-2d9a300816ea"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("62500000"),
		  .is_direct(0),
		  .is_digital(1))
		PiSPI_CLK
		 (.clock_out(Net_50));


    assign Net_55 = 1'h0;

	wire [0:0] tmpOE__Debug2_net;
	wire [0:0] tmpFB_0__Debug2_net;
	wire [0:0] tmpIO_0__Debug2_net;
	wire [0:0] tmpINTERRUPT_0__Debug2_net;
	electrical [0:0] tmpSIOVREF__Debug2_net;

	cy_psoc3_pins_v1_10
		#(.id("552a2720-c5e1-40f0-bdcd-60f84ec0f68a"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		Debug2
		 (.oe(tmpOE__Debug2_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Debug2_net[0:0]}),
		  .io({tmpIO_0__Debug2_net[0:0]}),
		  .siovref(tmpSIOVREF__Debug2_net),
		  .interrupt({tmpINTERRUPT_0__Debug2_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Debug2_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Debug3_net;
	wire [0:0] tmpFB_0__Debug3_net;
	wire [0:0] tmpIO_0__Debug3_net;
	wire [0:0] tmpINTERRUPT_0__Debug3_net;
	electrical [0:0] tmpSIOVREF__Debug3_net;

	cy_psoc3_pins_v1_10
		#(.id("82a522ba-f5ef-4c0b-8a96-10c9f5905354"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		Debug3
		 (.oe(tmpOE__Debug3_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Debug3_net[0:0]}),
		  .io({tmpIO_0__Debug3_net[0:0]}),
		  .siovref(tmpSIOVREF__Debug3_net),
		  .interrupt({tmpINTERRUPT_0__Debug3_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Debug3_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Debug4_net;
	wire [0:0] tmpFB_0__Debug4_net;
	wire [0:0] tmpIO_0__Debug4_net;
	wire [0:0] tmpINTERRUPT_0__Debug4_net;
	electrical [0:0] tmpSIOVREF__Debug4_net;

	cy_psoc3_pins_v1_10
		#(.id("bc4203ed-2165-4b05-b709-dd4cf62fe78f"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		Debug4
		 (.oe(tmpOE__Debug4_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Debug4_net[0:0]}),
		  .io({tmpIO_0__Debug4_net[0:0]}),
		  .siovref(tmpSIOVREF__Debug4_net),
		  .interrupt({tmpINTERRUPT_0__Debug4_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Debug4_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Debug5_net;
	wire [0:0] tmpFB_0__Debug5_net;
	wire [0:0] tmpIO_0__Debug5_net;
	wire [0:0] tmpINTERRUPT_0__Debug5_net;
	electrical [0:0] tmpSIOVREF__Debug5_net;

	cy_psoc3_pins_v1_10
		#(.id("71d52255-be97-4fd2-90eb-2bb46ad1b34d"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		Debug5
		 (.oe(tmpOE__Debug5_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Debug5_net[0:0]}),
		  .io({tmpIO_0__Debug5_net[0:0]}),
		  .siovref(tmpSIOVREF__Debug5_net),
		  .interrupt({tmpINTERRUPT_0__Debug5_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Debug5_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Debug6_net;
	wire [0:0] tmpFB_0__Debug6_net;
	wire [0:0] tmpIO_0__Debug6_net;
	wire [0:0] tmpINTERRUPT_0__Debug6_net;
	electrical [0:0] tmpSIOVREF__Debug6_net;

	cy_psoc3_pins_v1_10
		#(.id("7e2648e5-99fd-4fbb-a613-ee58cfe9ae1d"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		Debug6
		 (.oe(tmpOE__Debug6_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Debug6_net[0:0]}),
		  .io({tmpIO_0__Debug6_net[0:0]}),
		  .siovref(tmpSIOVREF__Debug6_net),
		  .interrupt({tmpINTERRUPT_0__Debug6_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Debug6_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Debug7_net;
	wire [0:0] tmpFB_0__Debug7_net;
	wire [0:0] tmpIO_0__Debug7_net;
	wire [0:0] tmpINTERRUPT_0__Debug7_net;
	electrical [0:0] tmpSIOVREF__Debug7_net;

	cy_psoc3_pins_v1_10
		#(.id("56d2d614-d466-4668-8d81-444fbf026f5a"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		Debug7
		 (.oe(tmpOE__Debug7_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Debug7_net[0:0]}),
		  .io({tmpIO_0__Debug7_net[0:0]}),
		  .siovref(tmpSIOVREF__Debug7_net),
		  .interrupt({tmpINTERRUPT_0__Debug7_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Debug7_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_dma_v1_0
		#(.drq_type(2'b00))
		SpiRcvDma
		 (.drq(Net_482),
		  .trq(1'b0),
		  .nrq(Net_88));



	cy_isr_v1_0
		#(.int_type(2'b10))
		SpiXferDone
		 (.int_signal(Net_88));


    // -- LUT RMotorControlLUT start --
    if (1)
    begin : RMotorControlLUT
        reg [3:0] tmp__RMotorControlLUT_reg;
        wire [2:0] tmp__RMotorControlLUT_ins;
        assign tmp__RMotorControlLUT_ins = {Net_444,Net_447,Net_431};
        always @(tmp__RMotorControlLUT_ins)
        begin
            case (tmp__RMotorControlLUT_ins)
                3'b000 :  tmp__RMotorControlLUT_reg = 4'b1000;
                3'b001 :  tmp__RMotorControlLUT_reg = 4'b1010;
                3'b010 :  tmp__RMotorControlLUT_reg = 4'b0001;
                3'b011 :  tmp__RMotorControlLUT_reg = 4'b0101;
                3'b100 :  tmp__RMotorControlLUT_reg = 4'b0110;
                3'b101 :  tmp__RMotorControlLUT_reg = 4'b0110;
                3'b110 :  tmp__RMotorControlLUT_reg = 4'b0110;
                3'b111 :  tmp__RMotorControlLUT_reg = 4'b0110;
            endcase
        end
        assign {Net_474,Net_475,Net_150,Net_151} = tmp__RMotorControlLUT_reg;
    end
    // -- LUT RMotorControlLUT end --

    // -- LUT LMotorControlLUT start --
    if (1)
    begin : LMotorControlLUT
        reg [3:0] tmp__LMotorControlLUT_reg;
        wire [2:0] tmp__LMotorControlLUT_ins;
        assign tmp__LMotorControlLUT_ins = {Net_329,Net_328,Net_327};
        always @(tmp__LMotorControlLUT_ins)
        begin
            case (tmp__LMotorControlLUT_ins)
                3'b000 :  tmp__LMotorControlLUT_reg = 4'b1000;
                3'b001 :  tmp__LMotorControlLUT_reg = 4'b1010;
                3'b010 :  tmp__LMotorControlLUT_reg = 4'b0001;
                3'b011 :  tmp__LMotorControlLUT_reg = 4'b0101;
                3'b100 :  tmp__LMotorControlLUT_reg = 4'b0110;
                3'b101 :  tmp__LMotorControlLUT_reg = 4'b0110;
                3'b110 :  tmp__LMotorControlLUT_reg = 4'b0110;
                3'b111 :  tmp__LMotorControlLUT_reg = 4'b0110;
            endcase
        end
        assign {Net_470,Net_471,Net_234,Net_146} = tmp__LMotorControlLUT_reg;
    end
    // -- LUT LMotorControlLUT end --

	wire [0:0] tmpOE__RDV2_net;
	wire [0:0] tmpFB_0__RDV2_net;
	wire [0:0] tmpIO_0__RDV2_net;
	wire [0:0] tmpINTERRUPT_0__RDV2_net;
	electrical [0:0] tmpSIOVREF__RDV2_net;

	cy_psoc3_pins_v1_10
		#(.id("eb6c27ab-fc51-4034-b315-213e9e3744bc"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		RDV2
		 (.oe(tmpOE__RDV2_net),
		  .y({Net_151}),
		  .fb({tmpFB_0__RDV2_net[0:0]}),
		  .io({tmpIO_0__RDV2_net[0:0]}),
		  .siovref(tmpSIOVREF__RDV2_net),
		  .interrupt({tmpINTERRUPT_0__RDV2_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__RDV2_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__RDG2_net;
	wire [0:0] tmpFB_0__RDG2_net;
	wire [0:0] tmpIO_0__RDG2_net;
	wire [0:0] tmpINTERRUPT_0__RDG2_net;
	electrical [0:0] tmpSIOVREF__RDG2_net;

	cy_psoc3_pins_v1_10
		#(.id("2dcbab4f-65ea-40f8-baad-ea98d42dc211"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		RDG2
		 (.oe(tmpOE__RDG2_net),
		  .y({Net_150}),
		  .fb({tmpFB_0__RDG2_net[0:0]}),
		  .io({tmpIO_0__RDG2_net[0:0]}),
		  .siovref(tmpSIOVREF__RDG2_net),
		  .interrupt({tmpINTERRUPT_0__RDG2_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__RDG2_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__RDV1_net;
	wire [0:0] tmpFB_0__RDV1_net;
	wire [0:0] tmpIO_0__RDV1_net;
	wire [0:0] tmpINTERRUPT_0__RDV1_net;
	electrical [0:0] tmpSIOVREF__RDV1_net;

	cy_psoc3_pins_v1_10
		#(.id("d4b8a528-bfc4-48a3-9fd8-96314beacfb9"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		RDV1
		 (.oe(tmpOE__RDV1_net),
		  .y({Net_474}),
		  .fb({tmpFB_0__RDV1_net[0:0]}),
		  .io({tmpIO_0__RDV1_net[0:0]}),
		  .siovref(tmpSIOVREF__RDV1_net),
		  .interrupt({tmpINTERRUPT_0__RDV1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__RDV1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 MotorPower (
        .connect({
            Net_109
        })
    );
    defparam MotorPower.comp_name = "Power_v1_0";
    defparam MotorPower.port_names = "T1";
    defparam MotorPower.width = 1;

	wire [0:0] tmpOE__RDG1_net;
	wire [0:0] tmpFB_0__RDG1_net;
	wire [0:0] tmpIO_0__RDG1_net;
	wire [0:0] tmpINTERRUPT_0__RDG1_net;
	electrical [0:0] tmpSIOVREF__RDG1_net;

	cy_psoc3_pins_v1_10
		#(.id("1e69f5d3-19e3-469b-92b1-f3a454c3faa9"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		RDG1
		 (.oe(tmpOE__RDG1_net),
		  .y({Net_475}),
		  .fb({tmpFB_0__RDG1_net[0:0]}),
		  .io({tmpIO_0__RDG1_net[0:0]}),
		  .siovref(tmpSIOVREF__RDG1_net),
		  .interrupt({tmpINTERRUPT_0__RDG1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__RDG1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__LDV2_net;
	wire [0:0] tmpFB_0__LDV2_net;
	wire [0:0] tmpIO_0__LDV2_net;
	wire [0:0] tmpINTERRUPT_0__LDV2_net;
	electrical [0:0] tmpSIOVREF__LDV2_net;

	cy_psoc3_pins_v1_10
		#(.id("59533667-4cfc-4544-baab-8b3bd52909f1"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		LDV2
		 (.oe(tmpOE__LDV2_net),
		  .y({Net_146}),
		  .fb({tmpFB_0__LDV2_net[0:0]}),
		  .io({tmpIO_0__LDV2_net[0:0]}),
		  .siovref(tmpSIOVREF__LDV2_net),
		  .interrupt({tmpINTERRUPT_0__LDV2_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__LDV2_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__LDV1_net;
	wire [0:0] tmpFB_0__LDV1_net;
	wire [0:0] tmpIO_0__LDV1_net;
	wire [0:0] tmpINTERRUPT_0__LDV1_net;
	electrical [0:0] tmpSIOVREF__LDV1_net;

	cy_psoc3_pins_v1_10
		#(.id("97923ef1-80ab-4780-9d4a-c8d7a967982d"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		LDV1
		 (.oe(tmpOE__LDV1_net),
		  .y({Net_470}),
		  .fb({tmpFB_0__LDV1_net[0:0]}),
		  .io({tmpIO_0__LDV1_net[0:0]}),
		  .siovref(tmpSIOVREF__LDV1_net),
		  .interrupt({tmpINTERRUPT_0__LDV1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__LDV1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__LDG2_net;
	wire [0:0] tmpFB_0__LDG2_net;
	wire [0:0] tmpIO_0__LDG2_net;
	wire [0:0] tmpINTERRUPT_0__LDG2_net;
	electrical [0:0] tmpSIOVREF__LDG2_net;

	cy_psoc3_pins_v1_10
		#(.id("287415af-de3f-4249-a327-fa46c98fd051"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		LDG2
		 (.oe(tmpOE__LDG2_net),
		  .y({Net_234}),
		  .fb({tmpFB_0__LDG2_net[0:0]}),
		  .io({tmpIO_0__LDG2_net[0:0]}),
		  .siovref(tmpSIOVREF__LDG2_net),
		  .interrupt({tmpINTERRUPT_0__LDG2_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__LDG2_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__LDG1_net;
	wire [0:0] tmpFB_0__LDG1_net;
	wire [0:0] tmpIO_0__LDG1_net;
	wire [0:0] tmpINTERRUPT_0__LDG1_net;
	electrical [0:0] tmpSIOVREF__LDG1_net;

	cy_psoc3_pins_v1_10
		#(.id("ad18c94c-1026-409d-8b2d-761861c9cd40"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		LDG1
		 (.oe(tmpOE__LDG1_net),
		  .y({Net_471}),
		  .fb({tmpFB_0__LDG1_net[0:0]}),
		  .io({tmpIO_0__LDG1_net[0:0]}),
		  .siovref(tmpSIOVREF__LDG1_net),
		  .interrupt({tmpINTERRUPT_0__LDG1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__LDG1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 MotorGround (
        .connect({
            Net_128
        })
    );
    defparam MotorGround.comp_name = "Gnd_v1_0";
    defparam MotorGround.port_names = "T1";
    defparam MotorGround.width = 1;

    cy_annotation_universal_v1_0 Q_8 (
        .connect({
            Net_120,
            Net_477,
            Net_128
        })
    );
    defparam Q_8.comp_name = "NFET_En_v1_0";
    defparam Q_8.port_names = "D, G, S";
    defparam Q_8.width = 3;

    assign Net_399 = 1'h0;

    cy_annotation_universal_v1_0 Q_7 (
        .connect({
            Net_119,
            Net_252,
            Net_128
        })
    );
    defparam Q_7.comp_name = "NFET_En_v1_0";
    defparam Q_7.port_names = "D, G, S";
    defparam Q_7.width = 3;

    cy_annotation_universal_v1_0 Q_6 (
        .connect({
            Net_120,
            Net_476,
            Net_109
        })
    );
    defparam Q_6.comp_name = "PFET_En_v1_0";
    defparam Q_6.port_names = "D, G, S";
    defparam Q_6.width = 3;

    cy_annotation_universal_v1_0 Q_5 (
        .connect({
            Net_119,
            Net_253,
            Net_109
        })
    );
    defparam Q_5.comp_name = "PFET_En_v1_0";
    defparam Q_5.port_names = "D, G, S";
    defparam Q_5.width = 3;

    assign Net_406 = 1'h0;

    PWM_v3_0_1 LMotorPwm (
        .reset(Net_399),
        .clock(Net_418),
        .tc(Net_401),
        .pwm1(Net_402),
        .pwm2(Net_403),
        .interrupt(Net_404),
        .capture(1'b0),
        .kill(Net_406),
        .enable(1'b1),
        .trigger(1'b0),
        .cmp_sel(1'b0),
        .pwm(Net_327),
        .ph1(Net_411),
        .ph2(Net_412));
    defparam LMotorPwm.Resolution = 16;

    cy_annotation_universal_v1_0 RightDriveMotor (
        .connect({
            Net_119,
            Net_120
        })
    );
    defparam RightDriveMotor.comp_name = "Motor_v1_0";
    defparam RightDriveMotor.port_names = "T1, T2";
    defparam RightDriveMotor.width = 2;

    cy_annotation_universal_v1_0 Q_4 (
        .connect({
            Net_115,
            Net_473,
            Net_128
        })
    );
    defparam Q_4.comp_name = "NFET_En_v1_0";
    defparam Q_4.port_names = "D, G, S";
    defparam Q_4.width = 3;

    cy_annotation_universal_v1_0 Q_3 (
        .connect({
            Net_112,
            Net_135,
            Net_128
        })
    );
    defparam Q_3.comp_name = "NFET_En_v1_0";
    defparam Q_3.port_names = "D, G, S";
    defparam Q_3.width = 3;

    cy_annotation_universal_v1_0 Q_2 (
        .connect({
            Net_115,
            Net_472,
            Net_109
        })
    );
    defparam Q_2.comp_name = "PFET_En_v1_0";
    defparam Q_2.port_names = "D, G, S";
    defparam Q_2.width = 3;

    cy_annotation_universal_v1_0 LeftDriveMotor (
        .connect({
            Net_112,
            Net_115
        })
    );
    defparam LeftDriveMotor.comp_name = "Motor_v1_0";
    defparam LeftDriveMotor.port_names = "T1, T2";
    defparam LeftDriveMotor.width = 2;

    cy_annotation_universal_v1_0 Q_1 (
        .connect({
            Net_112,
            Net_235,
            Net_109
        })
    );
    defparam Q_1.comp_name = "PFET_En_v1_0";
    defparam Q_1.port_names = "D, G, S";
    defparam Q_1.width = 3;


	cy_clock_v1_0
		#(.id("2307c094-7db2-4382-8854-4aa6ddf619ae"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("196078431.372549"),
		  .is_direct(0),
		  .is_digital(1))
		MotorPwmClock
		 (.clock_out(Net_418));


    PWM_v3_0_2 RMotorPwm (
        .reset(Net_420),
        .clock(Net_418),
        .tc(Net_454),
        .pwm1(Net_455),
        .pwm2(Net_456),
        .interrupt(Net_457),
        .capture(1'b0),
        .kill(Net_427),
        .enable(1'b1),
        .trigger(1'b0),
        .cmp_sel(1'b0),
        .pwm(Net_431),
        .ph1(Net_462),
        .ph2(Net_463));
    defparam RMotorPwm.Resolution = 16;

    assign Net_427 = 1'h0;

    assign Net_420 = 1'h0;

    CyControlReg_v1_70 MotorControlReg (
        .control_1(Net_444),
        .control_2(Net_328),
        .control_3(Net_329),
        .control_0(Net_447),
        .control_4(Net_464),
        .control_5(Net_465),
        .control_6(Net_466),
        .control_7(Net_467),
        .clock(1'b0),
        .reset(1'b0));
    defparam MotorControlReg.Bit0Mode = 0;
    defparam MotorControlReg.Bit1Mode = 0;
    defparam MotorControlReg.Bit2Mode = 0;
    defparam MotorControlReg.Bit3Mode = 0;
    defparam MotorControlReg.Bit4Mode = 0;
    defparam MotorControlReg.Bit5Mode = 0;
    defparam MotorControlReg.Bit6Mode = 0;
    defparam MotorControlReg.Bit7Mode = 0;
    defparam MotorControlReg.BitValue = 0;
    defparam MotorControlReg.BusDisplay = 0;
    defparam MotorControlReg.ExtrReset = 0;
    defparam MotorControlReg.NumOutputs = 4;

	wire [0:0] tmpOE__SerDrv_485Sel_net;
	wire [0:0] tmpFB_0__SerDrv_485Sel_net;
	wire [0:0] tmpIO_0__SerDrv_485Sel_net;
	wire [0:0] tmpINTERRUPT_0__SerDrv_485Sel_net;
	electrical [0:0] tmpSIOVREF__SerDrv_485Sel_net;

	cy_psoc3_pins_v1_10
		#(.id("fd594dc3-3efb-4bd3-892c-7af0fc27189b"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		SerDrv_485Sel
		 (.oe(tmpOE__SerDrv_485Sel_net),
		  .y({Net_486}),
		  .fb({tmpFB_0__SerDrv_485Sel_net[0:0]}),
		  .io({tmpIO_0__SerDrv_485Sel_net[0:0]}),
		  .siovref(tmpSIOVREF__SerDrv_485Sel_net),
		  .interrupt({tmpINTERRUPT_0__SerDrv_485Sel_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__SerDrv_485Sel_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    assign Net_486 = 1'h0;

	wire [0:0] tmpOE__SerDrv_Enable_net;
	wire [0:0] tmpFB_0__SerDrv_Enable_net;
	wire [0:0] tmpIO_0__SerDrv_Enable_net;
	wire [0:0] tmpINTERRUPT_0__SerDrv_Enable_net;
	electrical [0:0] tmpSIOVREF__SerDrv_Enable_net;

	cy_psoc3_pins_v1_10
		#(.id("fccf07ce-94e8-4f8a-b8b3-0a687ca58a90"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		SerDrv_Enable
		 (.oe(tmpOE__SerDrv_Enable_net),
		  .y({Net_488}),
		  .fb({tmpFB_0__SerDrv_Enable_net[0:0]}),
		  .io({tmpIO_0__SerDrv_Enable_net[0:0]}),
		  .siovref(tmpSIOVREF__SerDrv_Enable_net),
		  .interrupt({tmpINTERRUPT_0__SerDrv_Enable_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__SerDrv_Enable_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    assign Net_488 = 1'h1;

	wire [0:0] tmpOE__SerDrv_RA_net;
	wire [0:0] tmpIO_0__SerDrv_RA_net;
	wire [0:0] tmpINTERRUPT_0__SerDrv_RA_net;
	electrical [0:0] tmpSIOVREF__SerDrv_RA_net;

	cy_psoc3_pins_v1_10
		#(.id("19a0a241-daf3-4284-bddc-bbf25efc36c5"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b00),
		  .width(1))
		SerDrv_RA
		 (.oe(tmpOE__SerDrv_RA_net),
		  .y({1'b0}),
		  .fb({Net_506}),
		  .io({tmpIO_0__SerDrv_RA_net[0:0]}),
		  .siovref(tmpSIOVREF__SerDrv_RA_net),
		  .interrupt({tmpINTERRUPT_0__SerDrv_RA_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__SerDrv_RA_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__SerDrv_RB_net;
	wire [0:0] tmpIO_0__SerDrv_RB_net;
	wire [0:0] tmpINTERRUPT_0__SerDrv_RB_net;
	electrical [0:0] tmpSIOVREF__SerDrv_RB_net;

	cy_psoc3_pins_v1_10
		#(.id("9081c06c-a743-485f-b7ff-16e38257cb73"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b00),
		  .width(1))
		SerDrv_RB
		 (.oe(tmpOE__SerDrv_RB_net),
		  .y({1'b0}),
		  .fb({Net_508}),
		  .io({tmpIO_0__SerDrv_RB_net[0:0]}),
		  .siovref(tmpSIOVREF__SerDrv_RB_net),
		  .interrupt({tmpINTERRUPT_0__SerDrv_RB_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__SerDrv_RB_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__SerDrv_DY_net;
	wire [0:0] tmpFB_0__SerDrv_DY_net;
	wire [0:0] tmpIO_0__SerDrv_DY_net;
	wire [0:0] tmpINTERRUPT_0__SerDrv_DY_net;
	electrical [0:0] tmpSIOVREF__SerDrv_DY_net;

	cy_psoc3_pins_v1_10
		#(.id("50c223ef-75a8-4158-80c6-a7fb78dfb997"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		SerDrv_DY
		 (.oe(tmpOE__SerDrv_DY_net),
		  .y({Net_509}),
		  .fb({tmpFB_0__SerDrv_DY_net[0:0]}),
		  .io({tmpIO_0__SerDrv_DY_net[0:0]}),
		  .siovref(tmpSIOVREF__SerDrv_DY_net),
		  .interrupt({tmpINTERRUPT_0__SerDrv_DY_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__SerDrv_DY_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__SerDrv_DZ_net;
	wire [0:0] tmpFB_0__SerDrv_DZ_net;
	wire [0:0] tmpIO_0__SerDrv_DZ_net;
	wire [0:0] tmpINTERRUPT_0__SerDrv_DZ_net;
	electrical [0:0] tmpSIOVREF__SerDrv_DZ_net;

	cy_psoc3_pins_v1_10
		#(.id("900f815f-ee97-4b34-a221-6822ddb4f76f"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		SerDrv_DZ
		 (.oe(tmpOE__SerDrv_DZ_net),
		  .y({Net_510}),
		  .fb({tmpFB_0__SerDrv_DZ_net[0:0]}),
		  .io({tmpIO_0__SerDrv_DZ_net[0:0]}),
		  .siovref(tmpSIOVREF__SerDrv_DZ_net),
		  .interrupt({tmpINTERRUPT_0__SerDrv_DZ_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__SerDrv_DZ_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__PiUART_RXD_net;
	wire [0:0] tmpFB_0__PiUART_RXD_net;
	wire [0:0] tmpIO_0__PiUART_RXD_net;
	wire [0:0] tmpINTERRUPT_0__PiUART_RXD_net;
	electrical [0:0] tmpSIOVREF__PiUART_RXD_net;

	cy_psoc3_pins_v1_10
		#(.id("f1ea3e85-bd6b-4d5a-bfa3-3f153e6d198d"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		PiUART_RXD
		 (.oe(tmpOE__PiUART_RXD_net),
		  .y({Net_506}),
		  .fb({tmpFB_0__PiUART_RXD_net[0:0]}),
		  .io({tmpIO_0__PiUART_RXD_net[0:0]}),
		  .siovref(tmpSIOVREF__PiUART_RXD_net),
		  .interrupt({tmpINTERRUPT_0__PiUART_RXD_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PiUART_RXD_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__PiUART_TXD_net;
	wire [0:0] tmpIO_0__PiUART_TXD_net;
	wire [0:0] tmpINTERRUPT_0__PiUART_TXD_net;
	electrical [0:0] tmpSIOVREF__PiUART_TXD_net;

	cy_psoc3_pins_v1_10
		#(.id("1f75df3a-17d6-4a7e-9bcd-8c583ccfd06e"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b00),
		  .width(1))
		PiUART_TXD
		 (.oe(tmpOE__PiUART_TXD_net),
		  .y({1'b0}),
		  .fb({Net_509}),
		  .io({tmpIO_0__PiUART_TXD_net[0:0]}),
		  .siovref(tmpSIOVREF__PiUART_TXD_net),
		  .interrupt({tmpINTERRUPT_0__PiUART_TXD_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PiUART_TXD_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    assign Net_510 = 1'h0;



endmodule

