/* Linker script to configure memory regions. 
 * Need modifying for a specific board. 
 *   FLASH.ORIGIN: starting address of flash
 *   FLASH.LENGTH: length of flash
 *   RAM.ORIGIN: starting address of RAM bank 0
 *   RAM.LENGTH: length of RAM bank 0
 */
MEMORY
{
  /* Main internal SRAM1 - 112KB */
  FLASH (rx) : ORIGIN = 0x20000000, LENGTH = 64K 
  RAM (rwx) : ORIGIN = 0x20010000, LENGTH = 48K
}
