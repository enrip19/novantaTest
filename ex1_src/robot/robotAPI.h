#ifndef ROBOT_API_H
#define ROBOT_API_H

#include "../main.h"

/* Function Prototypes */

/**
 * @brief It is the function that executes the main task of the robot system. 
 * 
 * If robot operation is stopped by the RobotStop( ) function, 
 * this function will restart its operation. This function can be interrupted.
 * 
 * Time of execution: 100 ms
 * @param[in] u8Command It needs the command obtained from EEPROM.
 */
void RobotTask(uint8_t u8Command);

/**
 * @brief Stops immediately the robot operation. 
 * 
 * Time of execution: 15us
 */
void RobotStop(void);

#endif /* ROBOT_API_H */