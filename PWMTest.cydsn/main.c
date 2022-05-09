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
    PWM_1_Init();
    PWM_1_Start();

    for(;;)
    {
        /* Place your application code here. */
        PWM_1_WriteCompare1(31);
        CyDelay(1000);
        PWM_1_WriteCompare1(63);
        CyDelay(1000);
        PWM_1_WriteCompare1(127);
        CyDelay(1000);
    }
}

/* [] END OF FILE */
