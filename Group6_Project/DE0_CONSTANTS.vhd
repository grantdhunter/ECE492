library ieee;

-- Commonly imported packages:

-- STD_LOGIC and STD_LOGIC_VECTOR types, and relevant functions
use ieee.std_logic_1164.all;

-- SIGNED and UNSIGNED types, and relevant functions
use ieee.numeric_std.all;

-- Basic sequential functions and concurrent procedures
use ieee.VITAL_Primitives.all;

package DE0_CONSTANTS is	
	
	type DE0_SDRAM_ADDR_BUS  is array(12 downto 0) of std_logic;
	type DE0_SDRAM_DATA_BUS is array(15 downto 0) of std_logic;
	
	type DE0_LED_GREEN		is array(7 downto 0)  of std_logic;
	
	type DE0_SRAM_ADDR_BUS	is array(17 downto 0) of std_logic;
	type DE0_SRAM_DATA_BUS  is array(15 downto 0) of std_logic;
	
	
end DE0_CONSTANTS;