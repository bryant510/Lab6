/**
 * @file PMOD_ENC.h
 * @brief Header file for the PMOD_ENC driver.
 *
 * This file contains the function definitions for the PMOD_ENC driver.
 * It uses GPIO to interface with the PMOD ENC (Rotary Encoder) module.
 *
 * The PMOD ENC module (rotary encoder) uses the following pinout:
 *  - PMOD ENC Pin 1 (A)        <-->  Tiva LaunchPad Pin PD0
 *  - PMOD ENC Pin 2 (B)        <-->  Tiva LaunchPad Pin PD1
 *  - PMOD ENC Pin 3 (BTN)      <-->  Tiva LaunchPad Pin PD2
 *  - PMOD ENC Pin 4 (SWT)      <-->  Tiva LaunchPad Pin PD3
 *  - PMOD ENC Pin 5 (GND)      <-->  Tiva LaunchPad GND
 *  - PMOD ENC Pin 6 (VCC)      <-->  Tiva LaunchPad 3.3V
 *
 * @note The EduBase push buttons (EduBase_Button_Init) should not be used with the
 * PMOD ENC module because both drivers share the same pins (PD0 - PD3).
 * 
 * @note For more information regarding the PMOD ENC module, refer to the Reference Manual
 * Link: https://reference.digilentinc.com/reference/pmod/pmodenc/reference-manual
 *
 * @author Bryant Cuenca
 *
 */

#include "TM4C123GH6PM.h"

#define PMOD_ENC_PIN_A_MASK     0x01
#define PMOD_ENC_PIN_B_MASK     0x02
#define PMOD_ENC_BUTTON_MASK    0x04
#define PMOD_ENC_SWITCH_MASK    0x08
#define PMOD_ENC_ALL_PINS_MASK  0x0F


/**
 * @brief Reads the states of the PMOD ENC module every 1 ms.
 *
 * The PMOD_ENC_Task funtion is called when the Timer 0A module triggers a periodic interrupt
 * every 1ms. It reads the state of the PMOD ENC module. It sets the pmod_enc_btn_pressed flag
 * if the button is pressed. In addition, it increments or decrements the global variable, main_menu_counter,
 * depending on the direction of the rotary encoder's rotation. This used to indicate the active item on the LCD menu.
 * 
 * @param None
 *
 * @return None
 */
 void PMOD_ENC_TASK(void);
 
 /**
 * @brief Display the main menu items on the LCD based on the value of main_menu_state.
 * 
 *
 * @param main_menu_state Determines the menu item that is currently selected 
 *				based on the global variable, main_menu_counter.
 *
 * @return None
 */
 void Display_Main_Menu(int main_menu_state);
 
/**
 * @brief Handles main menu selection whenever the PMOD ENC button is pressed.
 *
 * This function calls corresponding functions based on the menu item selected when
 * the button on the PMOD ENC module is pressed.
 * 
 * @param None
 * 
 * @return None
 */
 void Process_Main_Menu_Selection(void);
 
/**
 * @brief Initializes the PMOD ENC module using Port D.
 *
 * This function initializes the following pins used by the PMOD ENC module:
 *  - PMOD ENC Pin 1 (A)    - PD0
 *  - PMOD ENC Pin 2 (B)    - PD1
 *  - PMOD ENC Pin 3 (BTN)  - PD2
 *  - PMOD ENC Pin 4 (SWT)  - PD3
 *  - PMOD ENC Pin 5 (GND)  - GND
 *  - PMOD ENC Pin 6 (VCC)  - 3.3V
 *
 * @param None
 *
 * @return None
 */
void PMOD_ENC_Init(void);

/**
 * @brief Gets the current state of the PMOD ENC module.
 *
 * This function reads the current state of the PMOD encoder module from the GPIO pins
 * and returns the state as a byte where each bit represents the state of a pin.
 *
 * @param None
 *
 * @return The current state of the PMOD encoder module.
 */
uint8_t PMOD_ENC_Get_State(void);

/**
 * @brief Determines the rotation direction of the PMOD ENC module.
 *
 * This function determines the rotation direction of the PMOD ENC module based on the 
 * current state and the previous state of the encoder pins.
 *
 * @param state The current state of the PMOD ENC module pins.
 * @param last_state The previous state of the PMOD ENC module pins.
 *
 * @return Returns "1" if the rotation is clockwise, -1 if counter-clockwise, and 0 if there is 
 * no change in the state of the encoder.
 */
int PMOD_ENC_Get_Rotation(uint8_t state, uint8_t last_state);

/**
 * @brief Reads the button state of the PMOD ENC module.
 *
 * This function reads the button state of the PMOD ENC module from the current 
 * state of the GPIO pins.
 *
 * @param state The current state of the PMOD ENC module pins.
 *
 * @return The button state of the PMOD ENC module.
 */
uint8_t PMOD_ENC_Button_Read(uint8_t state);

/**
 * @brief Reads the switch state of the PMOD ENC module.
 *
 * This function reads the switch state of the PMOD ENC module from the current 
 * state of the GPIO pins.
 *
 * @param state The current state of the PMOD ENC module pins.
 *
 * @return The switch state of the PMOD ENC module.
 */
uint8_t PMOD_ENC_Switch_Read(uint8_t state);
