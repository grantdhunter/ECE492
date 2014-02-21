--*****************************************************************************
--*  Copyright (c) 2012 by Michael Fischer. All rights reserved.
--*
--*  Redistribution and use in source and binary forms, with or without 
--*  modification, are permitted provided that the following conditions 
--*  are met:
--*  
--*  1. Redistributions of source code must retain the above copyright 
--*     notice, this list of conditions and the following disclaimer.
--*  2. Redistributions in binary form must reproduce the above copyright
--*     notice, this list of conditions and the following disclaimer in the 
--*     documentation and/or other materials provided with the distribution.
--*  3. Neither the name of the author nor the names of its contributors may 
--*     be used to endorse or promote products derived from this software 
--*     without specific prior written permission.
--*
--*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
--*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
--*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
--*  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL 
--*  THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, 
--*  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
--*  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS 
--*  OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED 
--*  AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
--*  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF 
--*  THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF 
--*  SUCH DAMAGE.
--*
--*****************************************************************************
--*  History:
--*
--*  01.08.2012  mifi  First version
--*  15.08.2012  mifi  Added RESET port of the DM9000
--*****************************************************************************

--*****************************************************************************
--*  DEFINE: Library                                                          *
--*****************************************************************************
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;


--*****************************************************************************
--*  DEFINE: Entity                                                           *
--*****************************************************************************

entity de0_nano_system is
  port ( 
         --
         -- Input clock 
         --
         CLOCK_50      : in  std_logic;
        
         --
         -- SDRAM interface,
         -- here a IS42S16160B (143MHz@CL-3) is used.
         -- Reference is made to ISSI datasheet:
         -- IS42S16160B, 12/14/05 
         --        
         SDRAM_CLK     : out   std_logic;                       -- Master Clock
         SDRAM_CKE     : out   std_logic;                       -- Clock Enable    
         SDRAM_CS_N    : out   std_logic;                       -- Chip Select
         SDRAM_RAS_N   : out   std_logic;                       -- Row Address Strobe
         SDRAM_CAS_N   : out   std_logic;                       -- Column Address Strobe
         SDRAM_WE_N    : out   std_logic;                       -- Write Enable
         SDRAM_DQ      : inout std_logic_vector(15 downto 0);   -- Data I/O (16 bits)
         SDRAM_DQML    : out   std_logic;                       -- Output Disable / Write Mask (low)
         SDRAM_DQMU    : out   std_logic;                       -- Output Disable / Write Mask (high)
         SDRAM_ADDR    : out   std_logic_vector(12 downto 0);   -- Address Input (13 bits)
         SDRAM_BA_0    : out   std_logic;                       -- Bank Address 0
         SDRAM_BA_1    : out   std_logic;                       -- Bank Address 1
                  
         --
         -- EPCS
         --
         EPCS_DCLK     : out   std_logic;
         EPCS_NCSO     : out   std_logic;
         EPCS_ASDO     : out   std_logic;
         EPCS_DATA0    : in    std_logic;
                  
         --
         -- LEDs, green and heartbeat
         --
         LED_GREEN     : out   std_logic_vector(6 downto 0);
         LED_HEARTBEAT : out   std_logic;
        
			-- TRANSMITTER
			GPIO_0 	: out std_logic_vector(3 downto 0)
  
         
 
          
       );
end entity de0_nano_system;


--*****************************************************************************
--*  DEFINE: Architecture                                                     *
--*****************************************************************************

architecture syn of de0_nano_system is

   --
   -- Define all components which are included here
   --
   
   component pll_sys
     port ( 
            inclk0   : in  std_logic  := '0';
            c0       : out std_logic ;
            c1       : out std_logic ;
            c2       : out std_logic ;
            locked   : out std_logic 
          );
   end component pll_sys;
   
   
   component heartbeat is
      port (  
             clk         : in  std_logic;
             counter_out : out std_logic
           );
   end component heartbeat;
   

   component system is
      port (
            clk_clk              : in    std_logic                     := 'X';             -- clk
            reset_reset_n        : in    std_logic                     := 'X';             -- reset_n
            sdram_addr           : out   std_logic_vector(12 downto 0);                    -- addr
            sdram_ba             : out   std_logic_vector(1 downto 0);                     -- ba
            sdram_cas_n          : out   std_logic;                                        -- cas_n
            sdram_cke            : out   std_logic;                                        -- cke
            sdram_cs_n           : out   std_logic;                                        -- cs_n
            sdram_dq             : inout std_logic_vector(15 downto 0) := (others => 'X'); -- dq
            sdram_dqm            : out   std_logic_vector(1 downto 0);                     -- dqm
            sdram_ras_n          : out   std_logic;                                        -- ras_n
            sdram_we_n           : out   std_logic;                                        -- we_n
            transmitter_export   : out   std_logic_vector(3 downto 0);                     -- export
            epcs_dclk            : out   std_logic;                                        -- dclk
            epcs_sce             : out   std_logic;                                        -- sce
            epcs_sdo             : out   std_logic;                                        -- sdo
            epcs_data0           : in    std_logic                     := 'X';             -- data0
            pio_led_green_export : out   std_logic_vector(6 downto 0)                      -- export
 
           );
   end component system;
   
      
   --
   -- Define all local signals (like static data) here
   --
   signal clk_10     : std_logic;
   signal clk_sys    : std_logic;
   signal pll_locked : std_logic;
   signal sdram_ba   : std_logic_vector(1 downto 0);
   signal sdram_dqm  : std_logic_vector(1 downto 0);
   signal vs_pio     : std_logic_vector(2 downto 0);
   signal spi_cs_n   : std_logic;
	  
begin

   inst_pll_sys : pll_sys
      port map ( 
                 inclk0 => CLOCK_50,
                 c0     => clk_sys,
                 c1     => SDRAM_CLK,
                 c2     => clk_10,
                 locked => pll_locked
               );
                                  
   inst_heartbeat : heartbeat 
      port map ( 
                 clk         => clk_10,
                 counter_out => LED_HEARTBEAT
               );   
               
   inst_cpu : system
      port map ( 
                 clk_clk              => clk_sys,
                 reset_reset_n        => pll_locked,
                 
                               
                 sdram_addr           => SDRAM_ADDR,
                 sdram_ba             => sdram_ba,
                 sdram_cas_n          => SDRAM_CAS_N,
                 sdram_cke            => SDRAM_CKE,
                 sdram_cs_n           => SDRAM_CS_N,
                 sdram_dq             => SDRAM_DQ,
                 sdram_dqm            => sdram_dqm,
                 sdram_ras_n          => SDRAM_RAS_N,
                 sdram_we_n           => SDRAM_WE_N,
                 
                 epcs_dclk            => EPCS_DCLK,
                 epcs_sce             => EPCS_NCSO,
                 epcs_sdo             => EPCS_ASDO,
                 epcs_data0           => EPCS_DATA0,
                 
                 
                 pio_led_green_export => LED_GREEN,
               
					  transmitter_export => GPIO_0
               );  
            
   SDRAM_BA_1 <= sdram_ba(1);
   SDRAM_BA_0 <= sdram_ba(0);
   
   SDRAM_DQMU <= sdram_dqm(1);
   SDRAM_DQML <= sdram_dqm(0);

         
end architecture syn;

-- *** EOF ***
