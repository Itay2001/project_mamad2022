/////////////////////////////////////
//  Generated Initialization File  //
/////////////////////////////////////

#include "compiler_defs.h"
#include "C8051F380_defs.h"

// Peripheral specific initialization functions,
// Called from the Init_Device() function
void PCA_Init()
{
    PCA0CN    = 0x40;
    PCA0MD    &= ~0x40;
    PCA0MD    = 0x00;
    PCA0CPM0  = 0xC2;
    PCA0CPM1  = 0xC2;
}

void Timer_Init()
{
    TCON      = 0x40;
    TMOD      = 0x20;
    TH1       = 0x30;
}

void UART_Init()
{
    SCON0     = 0x10;
    SBRLL1    = 0x5F;
    SBRLH1    = 0xFE;
    SCON1     = 0x10;
    SBCON1    = 0x43;
}

void SPI_Init()
{
    SPI0CFG   = 0x40;
    SPI0CN    = 0x01;
    SPI0CKR   = 0x17;
}

void ADC_Init()
{
    AMX0P     = 0x15;
    AMX0N     = 0x1F;
    ADC0CN    = 0x80;
}

void Voltage_Reference_Init()
{
    REF0CN    = 0x10;
}

void Port_IO_Init()
{
    // P0.0  -  SCK  (SPI0), Push-Pull,  Digital
    // P0.1  -  MISO (SPI0), Open-Drain, Digital
    // P0.2  -  MOSI (SPI0), Push-Pull,  Digital
    // P0.3  -  Skipped,     Open-Drain, Digital
    // P0.4  -  TX0 (UART0), Push-Pull,  Digital
    // P0.5  -  RX0 (UART0), Open-Drain, Digital
    // P0.6  -  Skipped,     Open-Drain, Digital
    // P0.7  -  Skipped,     Open-Drain, Digital

    // P1.0  -  Skipped,     Open-Drain, Analog
    // P1.1  -  CEX0  (PCA), Push-Pull,  Digital
    // P1.2  -  CEX1  (PCA), Push-Pull,  Digital
    // P1.3  -  Unassigned,  Push-Pull,  Digital
    // P1.4  -  Unassigned,  Open-Drain, Digital
    // P1.5  -  Unassigned,  Open-Drain, Digital
    // P1.6  -  Unassigned,  Open-Drain, Digital
    // P1.7  -  Unassigned,  Open-Drain, Digital

    // P2.0  -  Unassigned,  Open-Drain, Digital
    // P2.1  -  Unassigned,  Open-Drain, Digital
    // P2.2  -  Unassigned,  Open-Drain, Digital
    // P2.3  -  Unassigned,  Open-Drain, Digital
    // P2.4  -  Unassigned,  Open-Drain, Digital
    // P2.5  -  Unassigned,  Open-Drain, Digital
    // P2.6  -  Unassigned,  Open-Drain, Digital
    // P2.7  -  Unassigned,  Open-Drain, Digital

    // P3.0  -  Unassigned,  Open-Drain, Digital
    // P3.1  -  Unassigned,  Open-Drain, Digital
    // P3.2  -  Unassigned,  Open-Drain, Digital
    // P3.3  -  Unassigned,  Open-Drain, Digital
    // P3.4  -  Unassigned,  Open-Drain, Digital
    // P3.5  -  Unassigned,  Open-Drain, Digital
    // P3.6  -  Unassigned,  Open-Drain, Digital
    // P3.7  -  Unassigned,  Open-Drain, Digital

    P1MDIN    = 0xFE;
    P0MDOUT   = 0x15;
    P1MDOUT   = 0x0E;
    P0SKIP    = 0xC8;
    P1SKIP    = 0x01;
    XBR0      = 0x03;
    XBR1      = 0x42;
}

void Oscillator_Init()
{
    FLSCL     = 0x90;
    CLKSEL    = 0x03;
    OSCICN    = 0xC3;
}

// Initialization function for device,
// Call Init_Device() from your main program
void Init_Device(void)
{
    PCA_Init();
    Timer_Init();
    UART_Init();
    SPI_Init();
    ADC_Init();
    Voltage_Reference_Init();
    Port_IO_Init();
    Oscillator_Init();
}
