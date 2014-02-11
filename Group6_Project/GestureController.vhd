-- Top-level module for DE0 nano
-- Group 6 - Gesture-based Controller Design
-- ECE492w2014. @author: German R. Gomez Urbina.

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
use ieee.VITAL_Primitives.all;
use work.DE0_CONSTANTS.all;

entity GestureController is
port (

	CLOCK_50 : in std_logic; -- Port for clock input
	
	-- Ports for SDRAM core
	DRAM_addr   : out std_logic_vector(11 downto 0); -- addr
	DRAM_ba     : out std_logic_vector(1 downto 0);  -- ba
	DRAM_cas_n  : out std_logic;                     -- cas_n
	DRAM_cke    : out std_logic;                     -- cke
	DRAM_cs_n   : out std_logic;                     -- cs_n
	DRAM_dq     : inout std_logic_vector(15 downto 0) := (others => 'X'); -- dq
	DRAM_dqm    : out std_logic_vector(1 downto 0);  -- dqm
	DRAM_ras_n  : out std_logic;                     -- ras_n
	DRAM_we_n   : out std_logic;                     -- we_n
	
	-- Green LEDs port
	LED : out DE0_LED_GREEN
);
end GestureController;

architecture structure of GestureController is

	component niosII_system is
		port (
			leds_external_connection_export  : out     DE0_LED_GREEN;                      -- export
			sdram_addr                : out   std_logic_vector(11 downto 0);      -- addr
			sdram_ba                  : out   std_logic_vector(1 downto 0);       -- ba
			sdram_cas_n               : out   std_logic;                          -- cas_n
			sdram_cke                 : out   std_logic;                          -- cke
			sdram_cs_n                : out   std_logic;                          -- cs_n
			sdram_dq                  : inout std_logic_vector(15 downto 0) := (others => 'X'); -- dq
			sdram_dqm                 : out   std_logic_vector(1 downto 0);       -- dqm
			sdram_ras_n               : out   std_logic;                          -- ras_n
			sdram_we_n                : out   std_logic;                          -- we_n
			clk_in_clk                : in    std_logic              := 'X'       -- clk
		);
	end component niosII_system;

begin
    u0: component niosII_system
        port map (
            leds_external_connection_export => LED,
            sdram_addr                => DRAM_addr,
            sdram_ba                  => DRAM_ba,
            sdram_cas_n               => DRAM_cas_n,
            sdram_cke                 => DRAM_cke,
            sdram_cs_n                => DRAM_cs_n,
            sdram_dq                  => DRAM_dq,
            sdram_dqm                 => DRAM_dqm,
            sdram_ras_n               => DRAM_ras_n,
            sdram_we_n                => DRAM_we_n,
            clk_in_clk                => CLOCK_50
        );
		  
end structure;