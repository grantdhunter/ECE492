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
	
	reset_n  : in std_logic;
		
	-- Ports for SDRAM core
	DRAM_addr   : out std_logic_vector(11 downto 0); -- addr
	DRAM_BA_0     : out std_logic;            -- ba
	DRAM_BA_1    : out std_logic;            -- ba
	DRAM_cas_n  : out std_logic;                     -- cas_n
	DRAM_cke    : out std_logic;                     -- cke
	DRAM_cs_n   : out std_logic;                     -- cs_n
	DRAM_dq     : inout std_logic_vector(15 downto 0) := (others => 'X'); -- dq
	DRAM_dqm    : out std_logic_vector(1 downto 0);  -- dqm
	DRAM_ras_n  : out std_logic;                     -- ras_n
	DRAM_we_n   : out std_logic;                     -- we_n
	DRAM_CLK     : out   std_logic;                  -- Master Clock
	DRAM_DQML    : out   std_logic;                  -- Output Disable / Write Mask (low)
   DRAM_DQMU    : out   std_logic;                  -- Output Disable / Write Mask (high)
	
	-- Green LEDs port
	LED : out std_logic_vector(6 downto 0)
	
);
end GestureController;

architecture structure of GestureController is

	 component pll_sys is
	 port(
		 inclk0		: IN STD_LOGIC  := '0';
		 c0		: OUT STD_LOGIC ;
		 c1		: OUT STD_LOGIC ;
		 locked		: OUT STD_LOGIC 
	 );
	end component pll_sys;


	component niosII_system is
		port (
			green_leds_export  : out std_logic_vector(6 downto 0);  -- export
			sdram_addr                : out   std_logic_vector(11 downto 0);      -- addr
			sdram_ba                  : out   std_logic_vector(1 downto 0);       -- ba
			sdram_cas_n               : out   std_logic;                          -- cas_n
			sdram_cke                 : out   std_logic;                          -- cke
			sdram_cs_n                : out   std_logic;                          -- cs_n
			sdram_dq                  : inout std_logic_vector(15 downto 0) := (others => 'X'); -- dq
			sdram_ras_n               : out   std_logic;                          -- ras_n
			sdram_dqm                 : out   std_logic_vector(1 downto 0);       -- dqm
			sdram_we_n                : out   std_logic;                          -- we_n
			clk_clk                   : in    std_logic              := 'X';      -- clk
			reset_reset_n             : in    std_logic              := 'X'       -- reset         
		);
	end component niosII_system;

	signal clk_sys    : std_logic;
   signal pll_locked : std_logic;
   signal dra
   m_ba   : std_logic_vector(1 downto 0);
	signal dram_dqm  : std_logic_vector(1 downto 0);
	
begin
    u0: component niosII_system
        port map (
            green_leds_export         => LED,
            sdram_addr                => DRAM_addr,
            sdram_ba                  => sdram_ba,
            sdram_cas_n               => DRAM_cas_n,
            sdram_cke                 => DRAM_cke,
            sdram_cs_n                => DRAM_cs_n,
            sdram_dq                  => DRAM_dq,
            sdram_dqm                 => dram_dqm,
            sdram_ras_n               => DRAM_ras_n,
            sdram_we_n                => DRAM_we_n,
            clk_clk                   => clk_sys,
				reset_reset_n             => reset_n
        );
		  
	 u1: component pll_sys
		  port map (
		      inclk0	=> CLOCK_50,
	         c0		   => clk_sys,
	         c1		   => DRAM_CLK,
	         locked   => pll_locked 
		 );
	DRAM_BA_1 <= dram_ba(1);
   DRAM_BA_0 <= dram_ba(0);
   
   DRAM_DQMU <= dram_dqm(1);
   DRAM_DQML <= dram_dqm(0);
	
end structure;