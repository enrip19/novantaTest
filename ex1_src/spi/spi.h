#ifndef SPI_H
#define SPI_H

#include "../main.h"

/* Function Prototypes */
/**
 * @brief Initializes the SPI module. 
 * It enables the proper configuration for operation with EEPROM and sensor.
 * 
 * Time of exectuion: 7ms
 */
void SPIInit(void);

/**
 * @brief Set to LOW the Chip select signal of the SPI protocol to allow 
 * communication with EEPROM.
 * 
 * Time of exectuion: 1us
 */
void SpiEepromEnable(void);

/**
 * @brief Set to HIGH the Chip select signal of the SPI protocol 
 * to disable communication with EEPROM.
 * 
 * Time of exectuion: 1us
 */
void SpiEepromDisable(void);

/**
 * @brief Set to LOW the Chip select signal of the SPI protocol 
 * to allow communication with Sensor.
 * 
 * Time of exectuion: 1us
 */
void SpiSensorEnable(void);

/**
 * @brief Set to HIGH the Chip select signal of the SPI protocol 
 * to disable communication with Sensor.
 * 
 * Time of exectuion: 1us
 */
void SpiSensorDisable(void);

/**
 * @brief Returns the value read from the SPI bus.
 * Assume that dummy bytes are not needed.
 * 
 * Time of exectuion: 5us
 */
uint8_t SpiRead(void);

#endif /* SPI_H*/ 