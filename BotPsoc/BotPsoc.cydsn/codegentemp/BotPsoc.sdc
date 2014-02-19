# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\GitHub\RPi-Dev\BotPsoc\BotPsoc.cydsn\BotPsoc.cyprj
# Date: Wed, 19 Feb 2014 17:42:46 GMT
#set_units -time ns
create_clock -name {CyIMO} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 15.151515151515152 -waveform {0 7.57575757575758} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyILO} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyMASTER_CLK} -period 15.151515151515152 -waveform {0 7.57575757575758} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {PiSPI_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 5 9} [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {MotorPwmClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 13 27} -nominal_period 196.96969696969697 [list [get_pins {ClockBlock/dclk_glb_1}]]
create_clock -name {MotorPwmClock(fixed-function)} -period 196.96969696969697 -waveform {0 15.1515151515152} -nominal_period 196.96969696969697 [get_pins {ClockBlock/dclk_glb_ff_1}]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for C:\GitHub\RPi-Dev\BotPsoc\BotPsoc.cydsn\TopDesign\TopDesign.cysch
# Project: C:\GitHub\RPi-Dev\BotPsoc\BotPsoc.cydsn\BotPsoc.cyprj
# Date: Wed, 19 Feb 2014 17:42:41 GMT
