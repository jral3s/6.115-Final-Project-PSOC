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
uint8  getCompare(uint16 num);

uint16 adcResult;
uint32 adcOut;
uint8  pwmCmp;

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    LCD_Start();
    LCD_ClearDisplay();
    ADC_Start();
    ADC_StartConvert();
    PWM_1_Init();
    PWM_1_Start();
    
    for(;;)
    {
        /* Place your application code here. */
        if (ADC_IsEndConversion(ADC_WAIT_FOR_RESULT)) {
            
            LCD_ClearDisplay();
            adcOut = ADC_GetResult32();
            adcResult = clipADC(adcOut);
            
            //LCD_PrintHexUint16(adcResult);
            
            pwmCmp = getCompare(adcResult);
            
            LCD_PrintHexUint8(pwmCmp);
            PWM_1_WriteCompare1(pwmCmp);
            
            CyDelay(20);
        }
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

uint8 getCompare(uint16 num){
    return (uint8) (num >> 8);  
}

/* [] END OF FILE */
