#include "icm20602.h"

typedef struct 
{
    b_dataReady:1;
} s_control_t;

typedef union 
{
    s_control_t s_control;
    uint8_t byte;
}s_imuCtrl_t;

s_imuCtrl_t s_imuCtrl;

/* Private functions prototypes*/
uint8_t icm20602_readRegister(uint8_t reg);
void icm20602_writeRegister(uint8_t reg, uint8_t data);


/* Public fucntions declaration */
void icm20602_initialize(void)
{
    /* Initialize i2c protocol and peripheral */
    I2cInit();

    /* Initialize interruption */
    ExtIntInit();

    /* Clear control flags */
    s_imuCtrl.byte = 0;

    /* Wake up IMU from sleep mode*/
    icm20602_writeRegister(IMU_REG_PWR_MGMT_1, IMU_PWR_MGMT_1_PWRON);
}

void icm20602_readData(s_accelStruct_t *accel, s_gyroStruct_t *gyro )
{
    uint8_t tempValues[12];
    /* Read registers with data */
    tempValues[0] =  icm20602_readRegister(IMU_REG_ACCEL_XOUT_L);
    tempValues[0] =  icm20602_readRegister(IMU_REG_ACCEL_XOUT_H);
    tempValues[0] =  icm20602_readRegister(IMU_REG_ACCEL_YOUT_L);
    tempValues[0] =  icm20602_readRegister(IMU_REG_ACCEL_YOUT_H);
    tempValues[0] =  icm20602_readRegister(IMU_REG_ACCEL_ZOUT_L);
    tempValues[0] =  icm20602_readRegister(IMU_REG_ACCEL_ZOUT_H);
    tempValues[0] =  icm20602_readRegister(IMU_REG_GYRO_XOUT_L);
    tempValues[0] =  icm20602_readRegister(IMU_REG_GYRO_XOUT_H);
    tempValues[0] =  icm20602_readRegister(IMU_REG_GYRO_YOUT_L);
    tempValues[0] =  icm20602_readRegister(IMU_REG_GYRO_YOUT_H);
    tempValues[0] =  icm20602_readRegister(IMU_REG_GYRO_ZOUT_L);
    tempValues[0] =  icm20602_readRegister(IMU_REG_GYRO_ZOUT_H);

    /* Save it on structure */
    accel->x = tempValues[0] << 0 | tempValues[1] << 8;
    accel->y = tempValues[2] << 0 | tempValues[3] << 8;
    accel->z = tempValues[4] << 0 | tempValues[5] << 8;
    gyro->x = tempValues[6] << 0 | tempValues[7] << 8;
    gyro->y = tempValues[8] << 0 | tempValues[9] << 8;
    gyro->z = tempValues[10] << 0 | tempValues[11] << 8;
}

void ExtIntISR(void)
{
    /* Clear interrupt */
    /* Disable interrupts */

    /* Read interrupt status */
    if(IMU_INT_STATUS_DATA_RDY  == icm20602_readRegister(IMU_REG_INT_STATUS))
    /* Request a read */
    s_imuCtrl.s_control.b_dataReady = true;

    /* Enable interrupts*/
}



/* Private functions */
uint8_t icm20602_readRegister(uint8_t reg)
{
    uint8_t u8_temp;

    /* Write 0 bytes to start the communication */
    I2cWrite(IMU_I2C_ADDR, 0, 0);

    /* Send Register Address data */
    I2cWrite(IMU_I2C_ADDR, reg, 1);

    /* Read data */
    I2cRead(IMU_I2C_ADDR, &u8_temp, 1);

    /* Save it to the output address */
    return u8_temp;

}

void icm20602_writeRegister(uint8_t reg, uint8_t data)
{
    /* Write 0 bytes to start the communication */
    I2cWrite(IMU_I2C_ADDR, 0, 0);

    /* Send Register Address data */
    I2cWrite(IMU_I2C_ADDR, reg, 1);
    
    /* Send data */
    I2cWrite(IMU_I2C_ADDR, data, 1);
}