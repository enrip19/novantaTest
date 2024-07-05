#include <stdint.h>

/**
 * @brief Initializes the I2C module. It enables the proper configuration.
 * 
 */
void I2cInit(void);

/**
 * @brief Reads data from the slave with address u16Add.
 * 
 * @param u16Add slave address
 * @param pu8Data a pointer where data from I2C will be stored 
 * @param u16Size is the size of the read operation (assuming is in BYTES)
 */
void I2cRead(uint16_t u16Add, uint8_t* pu8Data, uint16_t u16Size);

/**
 * @brief Writes data to the slave with address u16Add
 * 
 * @param u16Add slave address
 * @param pu8Data a pointer where data from I2C will be stored
 * @param u16Size is the size of the read operation (assuming is in BYTES)
 */
void I2cWrite(uint16_t u16Add, uint8_t* pu8Data, uint16_t u16Size);

/**
 * @brief Initializes an external interrupt through the INT pin. 
 * The ISR is called ExtIntISR( )
 * 
 */
void ExtIntInit(void);

/**
 * @brief Interrupt service routine
 * 
 */
void ExtIntISR(void);
