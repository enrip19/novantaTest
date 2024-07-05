#include "spi.h"
#include "timer.h"

void TimerISR(void)
{
    /* Code for Disable interrupts */
    
    /* Block spi usage */
    u_readCtrl.s_readCtrl.b_readSensor = true;

    /* Enable SPI Chip select */
    SpiSensorEnable();
    
    /* Read sensor */
    uint8_t u8_sensorval = SpiRead();

    /* Disable SPI Chip select */
    SpiSensorDisable();

    if (128 < u8_sensorval)
    {
        /* Stop the Robot immediately */
        RobotStop();
        u_readCtrl.s_readCtrl.b_stopRobot = true;
    }

    /* Save data to the control struct */
    u_readCtrl.s_readCtrl.u8_sensorVal = u8_sensorval;

    /* Free spi usage */
    u_readCtrl.s_readCtrl.b_readSensor = false;

    /* Code for Enable interrupts */
}