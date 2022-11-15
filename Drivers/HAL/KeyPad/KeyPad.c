/*
 * KeyPad.c
 *
 * Created: 9/11/2022 9:28:18 PM
 *  Author: pc
 */ 
#include "KeyPad.h"
/*
*Description: Function to init keypad according to the configuration file (see keypad_config.h)
*Inputs: none
*void return
*Expected Output: configured pins are used as DIO
*======================= make sure you configured the keypad pins in "keypad_config.h"========================
*/
void Keypad_init(){
	#ifdef ROW_1						/*Configure rows as Output*/
	DIO_SetPinDirection(Keypad_Port,ROW_1,Output);
	#endif
	#ifdef ROW_2
	DIO_SetPinDirection(Keypad_Port,ROW_2,Output);
	#endif
	#ifdef ROW_3
	DIO_SetPinDirection(Keypad_Port,ROW_3,Output);
	#endif
	#ifdef ROW_4
	DIO_SetPinDirection(Keypad_Port,ROW_4,Output);
	#endif
	
	#ifdef COL_1						/*configure columns as inputs with pull up resistors*/
	DIO_SetPinDirection(Keypad_Port,COL_1,Input);
	#endif
	
	#ifdef COL_2
	DIO_SetPinDirection(Keypad_Port,COL_2,Input);
	#endif
	
	#ifdef COL_3
	DIO_SetPinDirection(Keypad_Port,COL_3,Input);
	#endif
	
	#ifdef COL_4
	DIO_SetPinDirection(Keypad_Port,COL_4,Input);
	#endif
	
	
}
/*
*Function to check the pressed key on the 4*4 keypad
*Inputs: none
*return: Ascii code of the pressed button {'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'o','0','=','+'}
*if no button is pressed it return NO_KEY_PRESSED which is defined in keypad.h
*/
uint8 Keypad_read(EN_KEYPAD_ReadingMode MODE)
{
	uint8 mapping_return = 0;							/*variable to save the return of mapping function*/
	uint8 (*CallFunc) (uint8);								/*pointer to function that will be called in reading columns according to mode*/
	
	if (MODE == ONE_PRESS){
		CallFunc = MapKeyPad4x4_OnePress;
	}
	else{
		CallFunc = MapKeyPad4x4_cont;
	}
	
	for (int rows =0 ; rows<ROWS; rows++)				/*loop on the rows*/
	{
		if (rows == 0){
			ClearBIT(Keypad_Port_Set_Clear,ROW_1);						/*move the 0 from one pin to other*/
			SetBIT(Keypad_Port_Set_Clear,ROW_2);
			SetBIT(Keypad_Port_Set_Clear,ROW_3);
			SetBIT(Keypad_Port_Set_Clear,ROW_4);
			mapping_return = CallFunc(rows);		/*check for pressed column*/
			if (mapping_return != NO_KEY_PRESSED){
				return mapping_return;					/*return value if button is pressed in the row*/
			}
		}
		else if (rows == 1){
			
			SetBIT(Keypad_Port_Set_Clear,ROW_1);
			ClearBIT(Keypad_Port_Set_Clear,ROW_2);						/*change the position of the 0 to the next row*/
			SetBIT(Keypad_Port_Set_Clear,ROW_3);
			SetBIT(Keypad_Port_Set_Clear,ROW_4);
			mapping_return = CallFunc(rows);
			if (mapping_return != NO_KEY_PRESSED){
				return mapping_return;
			}
		}
		else if (rows == 2){
			
			SetBIT(Keypad_Port_Set_Clear,ROW_1);
			SetBIT(Keypad_Port_Set_Clear,ROW_2);
			ClearBIT(Keypad_Port_Set_Clear,ROW_3);
			SetBIT(Keypad_Port_Set_Clear,ROW_4);
			mapping_return = CallFunc(rows);
			if (mapping_return != NO_KEY_PRESSED){
				return mapping_return;
			}
		}
		else if (rows == 3){
			
			SetBIT(Keypad_Port_Set_Clear,ROW_1);
			SetBIT(Keypad_Port_Set_Clear,ROW_2);
			SetBIT(Keypad_Port_Set_Clear,ROW_3);
			ClearBIT(Keypad_Port_Set_Clear,ROW_4);
			mapping_return = CallFunc(rows);
			if (mapping_return != NO_KEY_PRESSED){
				return mapping_return;
			}
		}
		
	}
	return NO_KEY_PRESSED;
}
/*Function to return actual pin state one time only
*Input parameters:  EN_PORTS_t PORT (DIO.h)
*					EN_PINS_t pin (DIO.h)
*I/O parameters:	uint8_t* last_value reserves the last pin state
*return:	return pin state one time only and return any other value for the rest of readings
*
*/
uint8 read_one_press(DIO_Port_ID port,DIO_PIN_ID pin,uint8* last_value)
{
	uint8 current_value =0;

	uint8 return_value = 0;
	
	current_value = DIO_GetPinValue(port,pin);
	
	if (current_value!= (*last_value)){
		return_value = current_value;					/*return pressed value */
	}
	else return_value = 2;								/*return any other value*/
	
	*last_value = current_value;							/*update variables*/
	
	return return_value;
}

/*
*Function to map the button presses to the return values continuously
*input:Row number to check
*return:
*it checks for pressed button in the selected row
*if no button is pressed in the row it returns 0 ,otherwise it returns the character
*of the pressed button continuously
*This function is designed for 4x4 keypad
*/

uint8 MapKeyPad4x4_cont(uint8 row){
	switch (row)
	{
		case 0:											/*elements of first row*/
		{
			if (!DIO_GetPinValue(Keypad_Port,COL_1)){
				return '7';
			}
			else if (!DIO_GetPinValue(Keypad_Port,COL_2)){
				return '8';
			}
			else if (!DIO_GetPinValue(Keypad_Port,COL_3)){
				return '9';
			}
			else if (!DIO_GetPinValue(Keypad_Port,COL_4)){
				return '/';
			}
			break;
		}
		case 1:											/*elements of second row*/
		{
			if (!DIO_GetPinValue(Keypad_Port,COL_1)){
				return '4';
			}
			else if (!DIO_GetPinValue(Keypad_Port,COL_2)){
				return '5';
			}
			else if (!DIO_GetPinValue(Keypad_Port,COL_3)){
				return '6';
			}
			else if (!DIO_GetPinValue(Keypad_Port,COL_4)){
				return '*';
			}
			break;
		}
		case 2:											/*elements of third row*/
		{
			if (!DIO_GetPinValue(Keypad_Port,COL_1)){
				return '1';
			}
			else if (!DIO_GetPinValue(Keypad_Port,COL_2)){
				return '2';
			}
			else if (!DIO_GetPinValue(Keypad_Port,COL_3)){
				return '3';
			}
			else if (!DIO_GetPinValue(Keypad_Port,COL_4)){
				return '-';
			}
			break;
		}
		case 3:											/*elements of fourth row*/
		{
			if (!DIO_GetPinValue(Keypad_Port,COL_1)){
				return 'o';
			}
			else if (!DIO_GetPinValue(Keypad_Port,COL_2)){
				return '0';
			}
			else if (!DIO_GetPinValue(Keypad_Port,COL_3)){
				return '=';
			}
			else if (!DIO_GetPinValue(Keypad_Port,COL_4)){
				return '+';
			}
		}
		default:
		return 0;
	}
	
	return NO_KEY_PRESSED;										/*return if no key is pressed in the selected row*/
}

/*
*Function to map the button presses to the return values one time only
*input:Row number to check
*return:
*it checks for pressed button in the selected row
*if no button is pressed in the row it returns 0 ,otherwise it returns the character
*of the pressed button one time only and return any other value for the rest of readings
*This function is designed for 4x4 keypad
*/

uint8 MapKeyPad4x4_OnePress(uint8 row){
	static uint8 lastpresses[16] = {0};
	switch (row)
	{
		case 0:											/*elements of first row*/
		{
			
			if (read_one_press(Keypad_Port,COL_1,&lastpresses[0])==LOW){
				return '7';
			}
			else if (read_one_press(Keypad_Port,COL_2,&lastpresses[1])==LOW){
				return '8';
			}
			else if (read_one_press(Keypad_Port,COL_3,&lastpresses[2])==LOW){
				return '9';
			}
			else if (read_one_press(Keypad_Port,COL_4,&lastpresses[3])==LOW){
				return '/';
			}
			break;
		}
		
		case 1:											/*elements of second row*/
		{
						

			if (read_one_press(Keypad_Port,COL_1,&lastpresses[4])==LOW){
				return '4';
			}
			else if (read_one_press(Keypad_Port,COL_2,&lastpresses[5])==LOW){
				return '5';
			}
			else if (read_one_press(Keypad_Port,COL_3,&lastpresses[6])==LOW){
				return '6';
			}
			else if (read_one_press(Keypad_Port,COL_4,&lastpresses[7])==LOW){
				return '*';
			}
			break;
		}
		case 2:											/*elements of third row*/
		{
						

			if (read_one_press(Keypad_Port,COL_1,&lastpresses[8])==LOW){
				return '1';
			}
			else if (read_one_press(Keypad_Port,COL_2,&lastpresses[9])==LOW){
				return '2';
			}
			else if (read_one_press(Keypad_Port,COL_3,&lastpresses[10])==LOW){
				return '3';
			}
			else if (read_one_press(Keypad_Port,COL_4,&lastpresses[11])==LOW){
				return '-';
			}
			break;
		}
		case 3:											/*elements of fourth row*/
		{
						

			if (read_one_press(Keypad_Port,COL_1,&lastpresses[12])==LOW){
				return 'o';
			}
			else if (read_one_press(Keypad_Port,COL_2,&lastpresses[13])==LOW){
				return '0';
			}
			else if (read_one_press(Keypad_Port,COL_3,&lastpresses[14])==LOW){
				return '=';
			}
			else if (read_one_press(Keypad_Port,COL_4,&lastpresses[15])==LOW){
				return '+';
			}
		}
		default:
		return 0;
	}
	
	return NO_KEY_PRESSED;										/*return if no key is pressed in the selected row*/
}