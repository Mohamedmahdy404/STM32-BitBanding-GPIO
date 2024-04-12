/*********************************************************/
/* Author      : mohamed mahdy                            */
/* Date        : 29 JUL 2024                              */
/* Version     : V02                                      */
/*********************************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H



// Define base address of peripheral bit-band
#define BITBAND_PERI_BASE 0x40000000
// Define base address of peripheral alias band
#define ALIAS_PERI_BASE 0x42000000

// Convert PERI address to alias region
#define BITBAND_PERI(a,b) *((u32*)((  ALIAS_PERI_BASE + ((u32)a-BITBAND_PERI_BASE)*32 + (b*4))))

// Bit manipulation macros
#define SET_BIT(VAR,BIT)    BITBAND_PERI((u32*)(&(VAR)), BIT)=0x1
#define CLR_BIT(VAR,BIT)    BITBAND_PERI((u32*)(&(VAR)), BIT)=0x0
#define GET_BIT(VAR,BIT)	BITBAND_PERI((u32*)(&(VAR)), BIT)
#define TOG_BIT(VAR,BIT) 	BITBAND_PERI((u32*)(&(VAR)), BIT) =^BITBAND_PERI((u32*)(&(VAR)), BIT)



// Define base address of SRAM bit-band
#define BITBAND_SRAM_BASE 0x20000000
// Define base address of SRAM alias band
#define ALIAS_SRAM_BASE 0x22000000

// Convert SRAM address to alias region
#define BITBAND_SRAM(a,b) ((volatile u32*)((ALIAS_SRAM_BASE + ((u32)(a)-BITBAND_SRAM_BASE)*32U + (b*4U))))


// Bit manipulation macros
#define SET_BIT_SRAM(VAR,BIT)  (*BITBAND_SRAM((u32*)(&(VAR)), BIT)=1U)
#define CLR_BIT_SRAM(VAR,BIT)  (*BITBAND_SRAM((u32*)(&(VAR)), BIT)=0U)
#define GET_BIT_SRAM(VAR,BIT)  (*BITBAND_SRAM((u32*)(&(VAR)), BIT))
#define TOG_BIT_SRAM(VAR,BIT)  (*BITBAND_SRAM((u32*)(&(VAR)), BIT) ^= 1U)


#endif 
