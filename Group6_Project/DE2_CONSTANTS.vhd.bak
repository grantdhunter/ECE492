library ieee;

-- Commonly imported packages:

-- STD_LOGIC and STD_LOGIC_VECTOR types, and relevant functions
use ieee.std_logic_1164.all;

-- SIGNED and UNSIGNED types, and relevant functions
use ieee.numeric_std.all;

-- Basic sequential functions and concurrent procedures
use ieee.VITAL_Primitives.all;

package DE2_CONSTANTS is	
	
	type DE2_SDRAM_ADDR_BUS is array(11 downto 0) of std_logic;
	type DE2_SDRAM_DATA_BUS is array(15 downto 0) of std_logic;
	
	type DE2_LCD_DATA_BUS	is array(7 downto 0) of std_logic;
	
	type DE2_LED_GREEN		is array(7 downto 0)  of std_logic;
	
	type DE2_SRAM_ADDR_BUS	is array(17 downto 0) of std_logic;
	type DE2_SRAM_DATA_BUS  is array(15 downto 0) of std_logic;
	type DE2_SEVEN_SEGMENT  is array (6 downto 0) of std_logic;
	
	constant sev_seg_0	:	std_logic_vector( 6 downto 0) := not b"0111111";	-- ~0x3f
	constant sev_seg_1	:	std_logic_vector( 6 downto 0)	:= not b"0000110"; 	-- ~0x06
	constant sev_seg_2	:	std_logic_vector( 6 downto 0)	:= not b"1011011"; 	-- ~0x5b
	constant sev_seg_3	:	std_logic_vector( 6 downto 0)	:= not b"1001111";	-- ~0x4f
	constant sev_seg_4	: 	std_logic_vector( 6 downto 0)	:= not b"1100110"; 	-- ~0x66
	constant sev_seg_5	:	std_logic_vector( 6 downto 0)	:= not b"1101101"; 	-- ~0x6d
	constant sev_seg_6	: 	std_logic_vector( 6 downto 0)	:= not b"1111101"; 	-- ~0x7D
	constant sev_seg_7	: 	std_logic_vector( 6 downto 0)	:= not b"0000111"; 	-- ~0x07
	constant sev_seg_8	:	std_logic_vector( 6 downto 0)	:= not b"1111111"; 	-- ~0x7f
	constant sev_seg_9	:  std_logic_vector( 6 downto 0)	:= not b"1101111"; 	-- ~0x6f
	constant sev_seg_a	:	std_logic_vector( 6 downto 0)	:= not b"1110111"; 	-- ~0x77
	constant sev_seg_b	:  std_logic_vector( 6 downto 0)	:= not b"1111100"; 	-- ~0x7c
	constant sev_seg_c	:  std_logic_vector( 6 downto 0)	:= not b"0111001"; 	-- ~0x39
	constant sev_seg_d	:  std_logic_vector( 6 downto 0)	:= not b"1011110"; 	-- ~0x5e
	constant sev_seg_e	:  std_logic_vector( 6 downto 0)	:= not b"1111001"; 	-- ~0x79
	constant sev_seg_f	:  std_logic_vector( 6 downto 0)	:= not b"1110001"; 	-- ~0x71
	
	
end DE2_CONSTANTS;