package require -exact qsys 12.1

# module properties
set_module_property NAME {system_export}
set_module_property DISPLAY_NAME {system_export_display}

# default module properties
set_module_property VERSION {1.0}
set_module_property GROUP {default group}
set_module_property DESCRIPTION {default description}
set_module_property AUTHOR {author}

# Instances and instance parameters
# (disabled instances are intentionally culled)
add_instance clk_sys clock_source 12.1
set_instance_parameter_value clk_sys clockFrequency {100000000.0}
set_instance_parameter_value clk_sys clockFrequencyKnown {1}
set_instance_parameter_value clk_sys resetSynchronousEdges {NONE}

add_instance cpu altera_nios2_qsys 12.1
set_instance_parameter_value cpu setting_showUnpublishedSettings {0}
set_instance_parameter_value cpu setting_showInternalSettings {0}
set_instance_parameter_value cpu setting_preciseSlaveAccessErrorException {0}
set_instance_parameter_value cpu setting_preciseIllegalMemAccessException {0}
set_instance_parameter_value cpu setting_preciseDivisionErrorException {0}
set_instance_parameter_value cpu setting_performanceCounter {0}
set_instance_parameter_value cpu setting_illegalMemAccessDetection {0}
set_instance_parameter_value cpu setting_illegalInstructionsTrap {0}
set_instance_parameter_value cpu setting_fullWaveformSignals {0}
set_instance_parameter_value cpu setting_extraExceptionInfo {0}
set_instance_parameter_value cpu setting_exportPCB {0}
set_instance_parameter_value cpu setting_debugSimGen {0}
set_instance_parameter_value cpu setting_clearXBitsLDNonBypass {1}
set_instance_parameter_value cpu setting_bit31BypassDCache {1}
set_instance_parameter_value cpu setting_bigEndian {0}
set_instance_parameter_value cpu setting_export_large_RAMs {0}
set_instance_parameter_value cpu setting_asic_enabled {0}
set_instance_parameter_value cpu setting_asic_synopsys_translate_on_off {0}
set_instance_parameter_value cpu setting_oci_export_jtag_signals {0}
set_instance_parameter_value cpu setting_bhtIndexPcOnly {0}
set_instance_parameter_value cpu setting_avalonDebugPortPresent {0}
set_instance_parameter_value cpu setting_alwaysEncrypt {1}
set_instance_parameter_value cpu setting_allowFullAddressRange {0}
set_instance_parameter_value cpu setting_activateTrace {1}
set_instance_parameter_value cpu setting_activateTestEndChecker {0}
set_instance_parameter_value cpu setting_activateMonitors {1}
set_instance_parameter_value cpu setting_activateModelChecker {0}
set_instance_parameter_value cpu setting_HDLSimCachesCleared {1}
set_instance_parameter_value cpu setting_HBreakTest {0}
set_instance_parameter_value cpu muldiv_divider {0}
set_instance_parameter_value cpu mpu_useLimit {0}
set_instance_parameter_value cpu mpu_enabled {0}
set_instance_parameter_value cpu mmu_enabled {0}
set_instance_parameter_value cpu mmu_autoAssignTlbPtrSz {1}
set_instance_parameter_value cpu manuallyAssignCpuID {1}
set_instance_parameter_value cpu debug_triggerArming {1}
set_instance_parameter_value cpu debug_embeddedPLL {1}
set_instance_parameter_value cpu debug_debugReqSignals {0}
set_instance_parameter_value cpu debug_assignJtagInstanceID {0}
set_instance_parameter_value cpu dcache_omitDataMaster {0}
set_instance_parameter_value cpu cpuReset {0}
set_instance_parameter_value cpu is_hardcopy_compatible {0}
set_instance_parameter_value cpu setting_shadowRegisterSets {0}
set_instance_parameter_value cpu mpu_numOfInstRegion {8}
set_instance_parameter_value cpu mpu_numOfDataRegion {8}
set_instance_parameter_value cpu mmu_TLBMissExcOffset {0}
set_instance_parameter_value cpu debug_jtagInstanceID {0}
set_instance_parameter_value cpu resetOffset {0}
set_instance_parameter_value cpu exceptionOffset {32}
set_instance_parameter_value cpu cpuID {0}
set_instance_parameter_value cpu cpuID_stored {0}
set_instance_parameter_value cpu breakOffset {32}
set_instance_parameter_value cpu userDefinedSettings {}
set_instance_parameter_value cpu resetSlave {sdram.s1}
set_instance_parameter_value cpu mmu_TLBMissExcSlave {}
set_instance_parameter_value cpu exceptionSlave {sdram.s1}
set_instance_parameter_value cpu breakSlave {cpu.jtag_debug_module}
set_instance_parameter_value cpu setting_perfCounterWidth {32}
set_instance_parameter_value cpu setting_interruptControllerType {Internal}
set_instance_parameter_value cpu setting_branchPredictionType {Automatic}
set_instance_parameter_value cpu setting_bhtPtrSz {8}
set_instance_parameter_value cpu muldiv_multiplierType {EmbeddedMulFast}
set_instance_parameter_value cpu mpu_minInstRegionSize {12}
set_instance_parameter_value cpu mpu_minDataRegionSize {12}
set_instance_parameter_value cpu mmu_uitlbNumEntries {4}
set_instance_parameter_value cpu mmu_udtlbNumEntries {6}
set_instance_parameter_value cpu mmu_tlbPtrSz {7}
set_instance_parameter_value cpu mmu_tlbNumWays {16}
set_instance_parameter_value cpu mmu_processIDNumBits {8}
set_instance_parameter_value cpu impl {Fast}
set_instance_parameter_value cpu icache_size {8192}
set_instance_parameter_value cpu icache_ramBlockType {Automatic}
set_instance_parameter_value cpu icache_numTCIM {0}
set_instance_parameter_value cpu icache_burstType {None}
set_instance_parameter_value cpu dcache_bursts {false}
set_instance_parameter_value cpu debug_level {Level1}
set_instance_parameter_value cpu debug_OCIOnchipTrace {_128}
set_instance_parameter_value cpu dcache_size {4096}
set_instance_parameter_value cpu dcache_ramBlockType {Automatic}
set_instance_parameter_value cpu dcache_numTCDM {0}
set_instance_parameter_value cpu dcache_lineSize {32}
set_instance_parameter_value cpu regfile_ramBlockType {Automatic}
set_instance_parameter_value cpu mmu_ramBlockType {Automatic}
set_instance_parameter_value cpu bht_ramBlockType {Automatic}

add_instance sysid altera_avalon_sysid_qsys 12.1
set_instance_parameter_value sysid id {0}

add_instance sdram altera_avalon_new_sdram_controller 12.1
set_instance_parameter_value sdram TAC {5.5}
set_instance_parameter_value sdram TMRD {3.0}
set_instance_parameter_value sdram TRCD {20.0}
set_instance_parameter_value sdram TRFC {70.0}
set_instance_parameter_value sdram TRP {20.0}
set_instance_parameter_value sdram TWR {14.0}
set_instance_parameter_value sdram casLatency {3}
set_instance_parameter_value sdram columnWidth {9}
set_instance_parameter_value sdram dataWidth {16}
set_instance_parameter_value sdram generateSimulationModel {0}
set_instance_parameter_value sdram initNOPDelay {0.0}
set_instance_parameter_value sdram initRefreshCommands {8}
set_instance_parameter_value sdram masteredTristateBridgeSlave {}
set_instance_parameter_value sdram model {custom}
set_instance_parameter_value sdram numberOfBanks {4}
set_instance_parameter_value sdram numberOfChipSelects {1}
set_instance_parameter_value sdram pinsSharedViaTriState {0}
set_instance_parameter_value sdram powerUpDelay {200.0}
set_instance_parameter_value sdram refreshPeriod {7.8125}
set_instance_parameter_value sdram registerDataIn {1}
set_instance_parameter_value sdram rowWidth {13}

add_instance epcs_flash_controller altera_avalon_epcs_flash_controller 12.1
set_instance_parameter_value epcs_flash_controller autoSelectASMIAtom {1}
set_instance_parameter_value epcs_flash_controller useASMIAtom {0}

add_instance sys_clk_timer altera_avalon_timer 12.1
set_instance_parameter_value sys_clk_timer alwaysRun {0}
set_instance_parameter_value sys_clk_timer counterSize {32}
set_instance_parameter_value sys_clk_timer fixedPeriod {0}
set_instance_parameter_value sys_clk_timer period {1}
set_instance_parameter_value sys_clk_timer periodUnits {MSEC}
set_instance_parameter_value sys_clk_timer resetOutput {0}
set_instance_parameter_value sys_clk_timer snapshot {1}
set_instance_parameter_value sys_clk_timer timeoutPulseOutput {0}
set_instance_parameter_value sys_clk_timer timerPreset {CUSTOM}

add_instance transmitter altera_avalon_pio 12.1
set_instance_parameter_value transmitter bitClearingEdgeCapReg {0}
set_instance_parameter_value transmitter bitModifyingOutReg {1}
set_instance_parameter_value transmitter captureEdge {0}
set_instance_parameter_value transmitter direction {Output}
set_instance_parameter_value transmitter edgeType {RISING}
set_instance_parameter_value transmitter generateIRQ {0}
set_instance_parameter_value transmitter irqType {LEVEL}
set_instance_parameter_value transmitter resetValue {0.0}
set_instance_parameter_value transmitter simDoTestBenchWiring {0}
set_instance_parameter_value transmitter simDrivenValue {0.0}
set_instance_parameter_value transmitter width {4}

add_instance pio_led_green altera_avalon_pio 12.1
set_instance_parameter_value pio_led_green bitClearingEdgeCapReg {0}
set_instance_parameter_value pio_led_green bitModifyingOutReg {1}
set_instance_parameter_value pio_led_green captureEdge {0}
set_instance_parameter_value pio_led_green direction {Output}
set_instance_parameter_value pio_led_green edgeType {RISING}
set_instance_parameter_value pio_led_green generateIRQ {0}
set_instance_parameter_value pio_led_green irqType {LEVEL}
set_instance_parameter_value pio_led_green resetValue {0.0}
set_instance_parameter_value pio_led_green simDoTestBenchWiring {0}
set_instance_parameter_value pio_led_green simDrivenValue {0.0}
set_instance_parameter_value pio_led_green width {7}

add_instance jtag_uart altera_avalon_jtag_uart 12.1
set_instance_parameter_value jtag_uart allowMultipleConnections {0}
set_instance_parameter_value jtag_uart hubInstanceID {0}
set_instance_parameter_value jtag_uart readBufferDepth {64}
set_instance_parameter_value jtag_uart readIRQThreshold {8}
set_instance_parameter_value jtag_uart simInputCharacterStream {}
set_instance_parameter_value jtag_uart simInteractiveOptions {INTERACTIVE_INPUT_OUTPUT}
set_instance_parameter_value jtag_uart useRegistersForReadBuffer {0}
set_instance_parameter_value jtag_uart useRegistersForWriteBuffer {0}
set_instance_parameter_value jtag_uart useRelativePathForSimFile {0}
set_instance_parameter_value jtag_uart writeBufferDepth {64}
set_instance_parameter_value jtag_uart writeIRQThreshold {8}

add_instance de0_nano_adc_0 altera_up_avalon_de0_nano_adc 12.0
set_instance_parameter_value de0_nano_adc_0 sclk_freq {3.2}
set_instance_parameter_value de0_nano_adc_0 numch {2}

# connections and connection parameters
add_connection cpu.instruction_master cpu.jtag_debug_module avalon
set_connection_parameter_value cpu.instruction_master/cpu.jtag_debug_module arbitrationPriority {1}
set_connection_parameter_value cpu.instruction_master/cpu.jtag_debug_module baseAddress {0x04001000}

add_connection cpu.data_master cpu.jtag_debug_module avalon
set_connection_parameter_value cpu.data_master/cpu.jtag_debug_module arbitrationPriority {1}
set_connection_parameter_value cpu.data_master/cpu.jtag_debug_module baseAddress {0x04001000}

add_connection clk_sys.clk_reset cpu.reset_n reset

add_connection cpu.jtag_debug_module_reset cpu.reset_n reset

add_connection clk_sys.clk_reset sysid.reset reset

add_connection cpu.jtag_debug_module_reset sysid.reset reset

add_connection clk_sys.clk_reset sdram.reset reset

add_connection cpu.jtag_debug_module_reset sdram.reset reset

add_connection clk_sys.clk_reset epcs_flash_controller.reset reset

add_connection cpu.jtag_debug_module_reset epcs_flash_controller.reset reset

add_connection clk_sys.clk_reset sys_clk_timer.reset reset

add_connection cpu.jtag_debug_module_reset sys_clk_timer.reset reset

add_connection clk_sys.clk_reset transmitter.reset reset

add_connection cpu.jtag_debug_module_reset transmitter.reset reset

add_connection cpu.data_master sysid.control_slave avalon
set_connection_parameter_value cpu.data_master/sysid.control_slave arbitrationPriority {1}
set_connection_parameter_value cpu.data_master/sysid.control_slave baseAddress {0x04001890}

add_connection cpu.data_master sdram.s1 avalon
set_connection_parameter_value cpu.data_master/sdram.s1 arbitrationPriority {1}
set_connection_parameter_value cpu.data_master/sdram.s1 baseAddress {0x02000000}

add_connection cpu.data_master epcs_flash_controller.epcs_control_port avalon
set_connection_parameter_value cpu.data_master/epcs_flash_controller.epcs_control_port arbitrationPriority {1}
set_connection_parameter_value cpu.data_master/epcs_flash_controller.epcs_control_port baseAddress {0x04000800}

add_connection cpu.data_master sys_clk_timer.s1 avalon
set_connection_parameter_value cpu.data_master/sys_clk_timer.s1 arbitrationPriority {1}
set_connection_parameter_value cpu.data_master/sys_clk_timer.s1 baseAddress {0x04001860}

add_connection cpu.data_master transmitter.s1 avalon
set_connection_parameter_value cpu.data_master/transmitter.s1 arbitrationPriority {1}
set_connection_parameter_value cpu.data_master/transmitter.s1 baseAddress {0x04001840}

add_connection cpu.instruction_master sdram.s1 avalon
set_connection_parameter_value cpu.instruction_master/sdram.s1 arbitrationPriority {1}
set_connection_parameter_value cpu.instruction_master/sdram.s1 baseAddress {0x02000000}

add_connection clk_sys.clk cpu.clk clock

add_connection clk_sys.clk sysid.clk clock

add_connection clk_sys.clk sdram.clk clock

add_connection clk_sys.clk epcs_flash_controller.clk clock

add_connection clk_sys.clk transmitter.clk clock

add_connection clk_sys.clk sys_clk_timer.clk clock

add_connection cpu.d_irq epcs_flash_controller.irq interrupt
set_connection_parameter_value cpu.d_irq/epcs_flash_controller.irq irqNumber {0}

add_connection cpu.d_irq sys_clk_timer.irq interrupt
set_connection_parameter_value cpu.d_irq/sys_clk_timer.irq irqNumber {1}

add_connection clk_sys.clk pio_led_green.clk clock

add_connection clk_sys.clk_reset pio_led_green.reset reset

add_connection cpu.data_master pio_led_green.s1 avalon
set_connection_parameter_value cpu.data_master/pio_led_green.s1 arbitrationPriority {1}
set_connection_parameter_value cpu.data_master/pio_led_green.s1 baseAddress {0x04001820}

add_connection cpu.jtag_debug_module_reset pio_led_green.reset reset

add_connection clk_sys.clk jtag_uart.clk clock

add_connection clk_sys.clk_reset jtag_uart.reset reset

add_connection cpu.data_master jtag_uart.avalon_jtag_slave avalon
set_connection_parameter_value cpu.data_master/jtag_uart.avalon_jtag_slave arbitrationPriority {1}
set_connection_parameter_value cpu.data_master/jtag_uart.avalon_jtag_slave baseAddress {0x04001888}

add_connection cpu.jtag_debug_module_reset jtag_uart.reset reset

add_connection cpu.d_irq jtag_uart.irq interrupt
set_connection_parameter_value cpu.d_irq/jtag_uart.irq irqNumber {2}

add_connection clk_sys.clk de0_nano_adc_0.clk clock

add_connection cpu.jtag_debug_module_reset de0_nano_adc_0.reset reset

add_connection clk_sys.clk_reset de0_nano_adc_0.reset reset

add_connection cpu.data_master de0_nano_adc_0.adc_slave avalon
set_connection_parameter_value cpu.data_master/de0_nano_adc_0.adc_slave arbitrationPriority {1}
set_connection_parameter_value cpu.data_master/de0_nano_adc_0.adc_slave baseAddress {0x04001800}

# exported interfaces
add_interface clk_sys_clk_in_reset reset sink
set_interface_property clk_sys_clk_in_reset EXPORT_OF clk_sys.clk_in_reset
add_interface sdram_wire conduit end
set_interface_property sdram_wire EXPORT_OF sdram.wire
add_interface de0_nano_adc_0_external_interface conduit end
set_interface_property de0_nano_adc_0_external_interface EXPORT_OF de0_nano_adc_0.external_interface
add_interface epcs_flash_controller_external conduit conduit
set_interface_property epcs_flash_controller_external EXPORT_OF epcs_flash_controller.external
add_interface pio_led_green_external_connection conduit conduit
set_interface_property pio_led_green_external_connection EXPORT_OF pio_led_green.external_connection
add_interface clk_sys_clk_in clock sink
set_interface_property clk_sys_clk_in EXPORT_OF clk_sys.clk_in
add_interface transmitter_external_connection conduit conduit
set_interface_property transmitter_external_connection EXPORT_OF transmitter.external_connection
