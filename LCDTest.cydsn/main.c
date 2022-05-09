/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
	LCD_Char_Start();					// initialize lcd
	LCD_Char_ClearDisplay();            // clear
    LCD_Char_PrintString("100");

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
