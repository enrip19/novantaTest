#ifndef IMU_H
#define IMU_H

#define IMU_I2C_ADDR 0x68 /*0b1101000*/

#define IMU_REG_INT_STATUS      0x3A /* Register to read which interrupt jumps in */

#define IMU_REGISTER_NUMBER 12

enum registers {
    IMU_REG_ACCEL_XOUT_H = 0x3B,
    IMU_REG_ACCEL_XOUT_L,
    IMU_REG_ACCEL_YOUT_H,
    IMU_REG_ACCEL_YOUT_L,
    IMU_REG_ACCEL_ZOUT_H,
    IMU_REG_ACCEL_ZOUT_L,
    IMU_REG_GYRO_XOUT_H = 0x43,
    IMU_REG_GYRO_XOUT_L,
    IMU_REG_GYRO_YOUT_H,
    IMU_REG_GYRO_YOUT_L,
    IMU_REG_GYRO_ZOUT_H, 
    IMU_REG_GYRO_ZOUT_L,
    IMU_REG_PWR_MGMT_1 = 0x6B
};

#define IMU_INT_STATUS_DATA_RDY 0x01 

#define IMU_PWR_MGMT_1_PWRON 0x00

#include <stdint.h>
#include <stdbool.h>

#include "api.h"


typedef struct {
    uint16_t x;
    uint16_t y;
    uint16_t z;    
} s_accelStruct_t;

typedef struct 
{
    uint16_t x;
    uint16_t y;
    uint16_t z;
} s_gyroStruct_t;


/* IMU Functions */
/**
 * @brief IMU initialization and configuration
 * 
 */
void icm20602_initialize(void);

/**
 * @brief Read data
 * 
 */
void icm20602_readData(s_accelStruct_t *accel, s_gyroStruct_t *gyro );


#endif /* IMU_H */