#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "STK_interface.h"
#include "RCC_interface.h"

// Function to initialize system
void System_init(void)
{
    // Initialize system clock
    RCC_voidInitSysClock();

    // Enable clocks for GPIOA and other peripherals
    RCC_voidEnableClock(RCC_APB2, 2);   // GPIOA
    RCC_voidEnableClock(RCC_APB2, 14);
    RCC_voidEnableClock(RCC_APB2, 12);

    // Initialize systick
    MSTK_voidInit();
}

// Function to setup GPIO
void GPIOSetup(void)
{
    // Set pin directions
    MGPIO_VidSetPinDirection(GPIOA, 1, 0b0010);
    MGPIO_VidSetPinDirection(GPIOA, 5, 0b0010);
    MGPIO_VidSetPinDirection(GPIOA, 10, 0b0010);

    // Set pin values
    MGPIO_VidSetPinValue(GPIOA, 1, LOW);
    MGPIO_VidSetPinValue(GPIOA, 5, HIGH);
}

// Main function
int main(void)
{
    // Initialize system
    System_init();

    // Setup GPIO
    GPIOSetup();

    // Variable for bit-banding
    u32 var = 0;

    // Set bit 1 of var
    SET_BIT_SRAM(var, 1);

    // Set GPIOA pin 10 value to bit 1 of var
    MGPIO_VidSetPinValue(GPIOA, 10, GET_BIT_SRAM(var, 1));

    // Infinite loop
    while(1);

}
