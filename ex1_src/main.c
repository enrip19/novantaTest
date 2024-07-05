#include "robot/robotAPI.h"
#include "spi/spi.h"
#include "timer/timer.h"
#include "main.h"

/* Global variable declaration */
u_readCtrl_t u_readCtrl;


/* Funciton prototypes */
void initializeModules(void);
void _NOP(void);

void main(void);


/* Function declaration */
void main (void) 
{
    printf("Hello World\n");
    initializeModules();


    while (1)
    {   
        if(false == u_readCtrl.s_readCtrl.b_stopRobot){

            switch (u_readCtrl.s_readCtrl.u8_step)
            {
            case 0: /* Read robot task from EEPROM */
                if((false == u_readCtrl.s_readCtrl.b_readSensor) && (false == u_readCtrl.s_readCtrl.b_readEeprom ))
                {
                    /* Block spi usage */
                    u_readCtrl.s_readCtrl.b_readEeprom = true;

                    /* Enable SPI chip select */
                    SpiEepromEnable();
                    
                    /* Read EEPROM */
                    uint8_t u8_eepromVal = SpiRead();

                    /* Disable SPI chip select */
                    SpiEepromDisable();

                    /* Save data to the control struct */
                    u_readCtrl.s_readCtrl.u8_eepromVal = u8_eepromVal;

                    /* Free spi usage */
                    u_readCtrl.s_readCtrl.b_readEeprom = false;
                    
                    u_readCtrl.s_readCtrl.u8_step = STEP_RUN_TASK;
                }
                break;
            
            case 1:  /* Run robot task*/
                if(false == u_readCtrl.s_readCtrl.b_stopRobot)
                {
                    RobotTask(u_readCtrl.s_readCtrl.u8_eepromVal);
                    u_readCtrl.s_readCtrl.u8_step = STEP_READ_EEPROM;
                }
                break;

            default:
                u_readCtrl.s_readCtrl.u8_step = STEP_DO_NOTHING;
                _NOP();
                break;
            }
        }
        else {
            u_readCtrl.s_readCtrl.u8_step = STEP_DO_NOTHING;
            _NOP();
        }
    }
}

/**
 * @brief Initializes all modules for the system
 */
void initializeModules(void) 
{
    u_readCtrl.bytes = 0x0000; /* Fast clear for s_readCtrl struct*/
    SPIInit();
    TimerInit();
}


void _NOP(void)
{
    printf("Do nothing\n");
}