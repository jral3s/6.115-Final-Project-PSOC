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

uint16 clipADC(uint32 num);

uint32 adcOut;
uint16 adcResult;

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    LCD_Start();
    LCD_ClearDisplay();
    ADC_Start();
    ADC_StartConvert();
    
    
    for(;;) {
        if (ADC_IsEndConversion(ADC_WAIT_FOR_RESULT)) {
            LCD_ClearDisplay();
            adcOut = ADC_GetResult32();
            adcResult = clipADC(adcOut);
            LCD_PrintHexUint16(adcResult);
            CyDelay(20);
        }
        /* Place your application code here. */
    }
}


uint16 clipADC(uint32 num){
    if (num & 0x800000)
   	{
        return 0;       // ignore negative ADC results
   	}
   	else if (num >= 0xffff)
   	{
    	return 0xffff;      // ignore high ADC results
   	}
    else return (uint16) num;
}

/* [] END OF FILE */
