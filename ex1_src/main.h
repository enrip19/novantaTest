#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>


#define STEP_READ_EEPROM 0
#define STEP_RUN_TASK 1
#define STEP_DO_NOTHING 2

typedef struct {
    uint8_t u8_sensorVal; 
    uint8_t u8_eepromVal;
    uint8_t u8_step; 
    bool b_readSensor:1;
    bool b_readEeprom:1;
    bool b_stopRobot;
    bool dummy3:1;
    bool dummy4:1;
    bool dummy5:1;
    bool dummy6:1;
    bool dummy7:1;
} s_readCtrl_t;


typedef union {
    s_readCtrl_t s_readCtrl;
    uint32_t bytes;
} u_readCtrl_t;


extern u_readCtrl_t u_readCtrl;

#endif /* MAIN_H*/