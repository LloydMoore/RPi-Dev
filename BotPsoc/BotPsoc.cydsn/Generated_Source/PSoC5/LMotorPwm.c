/*******************************************************************************
* File Name: LMotorPwm.c  
* Version 3.0
*
* Description:
*  The PWM User Module consist of an 8 or 16-bit counter with two 8 or 16-bit
*  comparitors. Each instance of this user module is capable of generating
*  two PWM outputs with the same period. The pulse width is selectable between
*  1 and 255/65535. The period is selectable between 2 and 255/65536 clocks. 
*  The compare value output may be configured to be active when the present 
*  counter is less than or less than/equal to the compare value.
*  A terminal count output is also provided. It generates a pulse one clock
*  width wide when the counter is equal to zero.
*
* Note:
*
*******************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "cytypes.h"
#include "LMotorPwm.h"

uint8 LMotorPwm_initVar = 0u;


/*******************************************************************************
* Function Name: LMotorPwm_Start
********************************************************************************
*
* Summary:
*  The start function initializes the pwm with the default values, the 
*  enables the counter to begin counting.  It does not enable interrupts,
*  the EnableInt command should be called if interrupt generation is required.
*
* Parameters:  
*  None  
*
* Return: 
*  None
*
* Global variables:
*  LMotorPwm_initVar: Is modified when this function is called for the 
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void LMotorPwm_Start(void) 
{
    /* If not Initialized then initialize all required hardware and software */
    if(LMotorPwm_initVar == 0u)
    {
        LMotorPwm_Init();
        LMotorPwm_initVar = 1u;
    }
    LMotorPwm_Enable();

}


/*******************************************************************************
* Function Name: LMotorPwm_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the 
*  customizer of the component placed onto schematic. Usually called in 
*  LMotorPwm_Start().
*
* Parameters:  
*  None
*
* Return: 
*  None
*
*******************************************************************************/
void LMotorPwm_Init(void) 
{
    #if (LMotorPwm_UsingFixedFunction || LMotorPwm_UseControl)
        uint8 ctrl;
    #endif /* (LMotorPwm_UsingFixedFunction || LMotorPwm_UseControl) */
    
    #if(!LMotorPwm_UsingFixedFunction) 
        #if(LMotorPwm_UseStatus)
            /* Interrupt State Backup for Critical Region*/
            uint8 LMotorPwm_interruptState;
        #endif /* (LMotorPwm_UseStatus) */
    #endif /* (!LMotorPwm_UsingFixedFunction) */
    
    #if (LMotorPwm_UsingFixedFunction)
        /* You are allowed to write the compare value (FF only) */
        LMotorPwm_CONTROL |= LMotorPwm_CFG0_MODE;
        #if (LMotorPwm_DeadBand2_4)
            LMotorPwm_CONTROL |= LMotorPwm_CFG0_DB;
        #endif /* (LMotorPwm_DeadBand2_4) */
                
        ctrl = LMotorPwm_CONTROL3 & ((uint8 )(~LMotorPwm_CTRL_CMPMODE1_MASK));
        LMotorPwm_CONTROL3 = ctrl | LMotorPwm_DEFAULT_COMPARE1_MODE;
        
         /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
        LMotorPwm_RT1 &= ((uint8)(~LMotorPwm_RT1_MASK));
        LMotorPwm_RT1 |= LMotorPwm_SYNC;     
                
        /*Enable DSI Sync all all inputs of the PWM*/
        LMotorPwm_RT1 &= ((uint8)(~LMotorPwm_SYNCDSI_MASK));
        LMotorPwm_RT1 |= LMotorPwm_SYNCDSI_EN;
       
    #elif (LMotorPwm_UseControl)
        /* Set the default compare mode defined in the parameter */
        ctrl = LMotorPwm_CONTROL & ((uint8)(~LMotorPwm_CTRL_CMPMODE2_MASK)) & ((uint8)(~LMotorPwm_CTRL_CMPMODE1_MASK));
        LMotorPwm_CONTROL = ctrl | LMotorPwm_DEFAULT_COMPARE2_MODE | 
                                   LMotorPwm_DEFAULT_COMPARE1_MODE;
    #endif /* (LMotorPwm_UsingFixedFunction) */
        
    #if (!LMotorPwm_UsingFixedFunction)
        #if (LMotorPwm_Resolution == 8)
            /* Set FIFO 0 to 1 byte register for period*/
            LMotorPwm_AUX_CONTROLDP0 |= (LMotorPwm_AUX_CTRL_FIFO0_CLR);
        #else /* (LMotorPwm_Resolution == 16)*/
            /* Set FIFO 0 to 1 byte register for period */
            LMotorPwm_AUX_CONTROLDP0 |= (LMotorPwm_AUX_CTRL_FIFO0_CLR);
            LMotorPwm_AUX_CONTROLDP1 |= (LMotorPwm_AUX_CTRL_FIFO0_CLR);
        #endif /* (LMotorPwm_Resolution == 8) */

        LMotorPwm_WriteCounter(LMotorPwm_INIT_PERIOD_VALUE);
    #endif /* (!LMotorPwm_UsingFixedFunction) */
        
    LMotorPwm_WritePeriod(LMotorPwm_INIT_PERIOD_VALUE);

        #if (LMotorPwm_UseOneCompareMode)
            LMotorPwm_WriteCompare(LMotorPwm_INIT_COMPARE_VALUE1);
        #else
            LMotorPwm_WriteCompare1(LMotorPwm_INIT_COMPARE_VALUE1);
            LMotorPwm_WriteCompare2(LMotorPwm_INIT_COMPARE_VALUE2);
        #endif /* (LMotorPwm_UseOneCompareMode) */
        
        #if (LMotorPwm_KillModeMinTime)
            LMotorPwm_WriteKillTime(LMotorPwm_MinimumKillTime);
        #endif /* (LMotorPwm_KillModeMinTime) */
        
        #if (LMotorPwm_DeadBandUsed)
            LMotorPwm_WriteDeadTime(LMotorPwm_INIT_DEAD_TIME);
        #endif /* (LMotorPwm_DeadBandUsed) */

    #if (LMotorPwm_UseStatus || LMotorPwm_UsingFixedFunction)
        LMotorPwm_SetInterruptMode(LMotorPwm_INIT_INTERRUPTS_MODE);
    #endif /* (LMotorPwm_UseStatus || LMotorPwm_UsingFixedFunction) */
        
    #if (LMotorPwm_UsingFixedFunction)
        /* Globally Enable the Fixed Function Block chosen */
        LMotorPwm_GLOBAL_ENABLE |= LMotorPwm_BLOCK_EN_MASK;
        /* Set the Interrupt source to come from the status register */
        LMotorPwm_CONTROL2 |= LMotorPwm_CTRL2_IRQ_SEL;
    #else
        #if(LMotorPwm_UseStatus)
            
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            LMotorPwm_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            LMotorPwm_STATUS_AUX_CTRL |= LMotorPwm_STATUS_ACTL_INT_EN_MASK;
            
             /* Exit Critical Region*/
            CyExitCriticalSection(LMotorPwm_interruptState);
            
            /* Clear the FIFO to enable the LMotorPwm_STATUS_FIFOFULL
                   bit to be set on FIFO full. */
            LMotorPwm_ClearFIFO();
        #endif /* (LMotorPwm_UseStatus) */
    #endif /* (LMotorPwm_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: LMotorPwm_Enable
********************************************************************************
*
* Summary: 
*  Enables the PWM block operation
*
* Parameters:  
*  None
*
* Return: 
*  None
*
* Side Effects: 
*  This works only if software enable mode is chosen
*
*******************************************************************************/
void LMotorPwm_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (LMotorPwm_UsingFixedFunction)
        LMotorPwm_GLOBAL_ENABLE |= LMotorPwm_BLOCK_EN_MASK;
        LMotorPwm_GLOBAL_STBY_ENABLE |= LMotorPwm_BLOCK_STBY_EN_MASK;
    #endif /* (LMotorPwm_UsingFixedFunction) */
    
    /* Enable the PWM from the control register  */
    #if (LMotorPwm_UseControl || LMotorPwm_UsingFixedFunction)
        LMotorPwm_CONTROL |= LMotorPwm_CTRL_ENABLE;
    #endif /* (LMotorPwm_UseControl || LMotorPwm_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: LMotorPwm_Stop
********************************************************************************
*
* Summary:
*  The stop function halts the PWM, but does not change any modes or disable
*  interrupts.
*
* Parameters:  
*  None  
*
* Return: 
*  None
*
* Side Effects:
*  If the Enable mode is set to Hardware only then this function
*  has no effect on the operation of the PWM
*
*******************************************************************************/
void LMotorPwm_Stop(void) 
{
    #if (LMotorPwm_UseControl || LMotorPwm_UsingFixedFunction)
        LMotorPwm_CONTROL &= ((uint8)(~LMotorPwm_CTRL_ENABLE));
    #endif /* (LMotorPwm_UseControl || LMotorPwm_UsingFixedFunction) */
    
    /* Globally disable the Fixed Function Block chosen */
    #if (LMotorPwm_UsingFixedFunction)
        LMotorPwm_GLOBAL_ENABLE &= ((uint8)(~LMotorPwm_BLOCK_EN_MASK));
        LMotorPwm_GLOBAL_STBY_ENABLE &= ((uint8)(~LMotorPwm_BLOCK_STBY_EN_MASK));
    #endif /* (LMotorPwm_UsingFixedFunction) */
}


#if (LMotorPwm_UseOneCompareMode)
	#if (LMotorPwm_CompareMode1SW)


		/*******************************************************************************
		* Function Name: LMotorPwm_SetCompareMode
		********************************************************************************
		* 
		* Summary:
		*  This function writes the Compare Mode for the pwm output when in Dither mode,
		*  Center Align Mode or One Output Mode.
		*
		* Parameters:
		*  comparemode:  The new compare mode for the PWM output. Use the compare types
		*                defined in the H file as input arguments.
		*
		* Return:
		*  None
		*
		*******************************************************************************/
		void LMotorPwm_SetCompareMode(uint8 comparemode) 
		{
		    #if(LMotorPwm_UsingFixedFunction)
            
                #if(0 != LMotorPwm_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemodemasked = ((uint8)((uint8)comparemode << LMotorPwm_CTRL_CMPMODE1_SHIFT));
                #else
                    uint8 comparemodemasked = comparemode;
                #endif /* (0 != LMotorPwm_CTRL_CMPMODE1_SHIFT) */
            
	            LMotorPwm_CONTROL3 &= ((uint8)(~LMotorPwm_CTRL_CMPMODE1_MASK)); /*Clear Existing Data */
	            LMotorPwm_CONTROL3 |= comparemodemasked;     
		                
		    #elif (LMotorPwm_UseControl)
		        
                #if(0 != LMotorPwm_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemode1masked = ((uint8)((uint8)comparemode << LMotorPwm_CTRL_CMPMODE1_SHIFT)) & 
    		                                    LMotorPwm_CTRL_CMPMODE1_MASK;
                #else
                    uint8 comparemode1masked = comparemode & LMotorPwm_CTRL_CMPMODE1_MASK;                
                #endif /* (0 != LMotorPwm_CTRL_CMPMODE1_SHIFT) */
                
                #if(0 != LMotorPwm_CTRL_CMPMODE2_SHIFT)                            
    		        uint8 comparemode2masked = ((uint8)((uint8)comparemode << LMotorPwm_CTRL_CMPMODE2_SHIFT)) & 
    		                                   LMotorPwm_CTRL_CMPMODE2_MASK;
                #else
    		        uint8 comparemode2masked = comparemode & LMotorPwm_CTRL_CMPMODE2_MASK;                
                #endif /* (0 != LMotorPwm_CTRL_CMPMODE2_SHIFT) */
                
		        /*Clear existing mode */
		        LMotorPwm_CONTROL &= ((uint8)(~(LMotorPwm_CTRL_CMPMODE1_MASK | LMotorPwm_CTRL_CMPMODE2_MASK))); 
		        LMotorPwm_CONTROL |= (comparemode1masked | comparemode2masked);
		        
		    #else
		        uint8 temp = comparemode;
		    #endif /* (LMotorPwm_UsingFixedFunction) */
		}
	#endif /* LMotorPwm_CompareMode1SW */

#else /* UseOneCompareMode */

	#if (LMotorPwm_CompareMode1SW)


		/*******************************************************************************
		* Function Name: LMotorPwm_SetCompareMode1
		********************************************************************************
		* 
		* Summary:
		*  This function writes the Compare Mode for the pwm or pwm1 output
		*
		* Parameters:  
		*  comparemode:  The new compare mode for the PWM output. Use the compare types
		*                defined in the H file as input arguments.
		*
		* Return: 
		*  None
		*
		*******************************************************************************/
		void LMotorPwm_SetCompareMode1(uint8 comparemode) 
		{
		    #if(0 != LMotorPwm_CTRL_CMPMODE1_SHIFT)
                uint8 comparemodemasked = ((uint8)((uint8)comparemode << LMotorPwm_CTRL_CMPMODE1_SHIFT)) & 
    		                               LMotorPwm_CTRL_CMPMODE1_MASK;
		    #else
                uint8 comparemodemasked = comparemode & LMotorPwm_CTRL_CMPMODE1_MASK;                
            #endif /* (0 != LMotorPwm_CTRL_CMPMODE1_SHIFT) */
                   
		    #if (LMotorPwm_UseControl)
		        LMotorPwm_CONTROL &= ((uint8)(~LMotorPwm_CTRL_CMPMODE1_MASK)); /*Clear existing mode */
		        LMotorPwm_CONTROL |= comparemodemasked;
		    #endif /* (LMotorPwm_UseControl) */
		}
	#endif /* LMotorPwm_CompareMode1SW */

#if (LMotorPwm_CompareMode2SW)


    /*******************************************************************************
    * Function Name: LMotorPwm_SetCompareMode2
    ********************************************************************************
    * 
    * Summary:
    *  This function writes the Compare Mode for the pwm or pwm2 output
    *
    * Parameters:  
    *  comparemode:  The new compare mode for the PWM output. Use the compare types
    *                defined in the H file as input arguments.
    *
    * Return: 
    *  None
    *
    *******************************************************************************/
    void LMotorPwm_SetCompareMode2(uint8 comparemode) 
    {

        #if(0 != LMotorPwm_CTRL_CMPMODE2_SHIFT)
            uint8 comparemodemasked = ((uint8)((uint8)comparemode << LMotorPwm_CTRL_CMPMODE2_SHIFT)) & 
                                                 LMotorPwm_CTRL_CMPMODE2_MASK;
        #else
            uint8 comparemodemasked = comparemode & LMotorPwm_CTRL_CMPMODE2_MASK;            
        #endif /* (0 != LMotorPwm_CTRL_CMPMODE2_SHIFT) */
        
        #if (LMotorPwm_UseControl)
            LMotorPwm_CONTROL &= ((uint8)(~LMotorPwm_CTRL_CMPMODE2_MASK)); /*Clear existing mode */
            LMotorPwm_CONTROL |= comparemodemasked;
        #endif /* (LMotorPwm_UseControl) */
    }
    #endif /*LMotorPwm_CompareMode2SW */

#endif /* UseOneCompareMode */


#if (!LMotorPwm_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: LMotorPwm_WriteCounter
    ********************************************************************************
    * 
    * Summary:
    *  Writes a new counter value directly to the counter register. This will be 
    *  implemented for that currently running period and only that period. This API 
    *  is valid only for UDB implementation and not available for fixed function 
    *  PWM implementation.    
    *
    * Parameters:  
    *  counter:  The period new period counter value.
    *
    * Return: 
    *  None
    *
    * Side Effects: 
    *  The PWM Period will be reloaded when a counter value will be a zero
    *
    *******************************************************************************/
    void LMotorPwm_WriteCounter(uint16 counter) \
                                       
    {
        CY_SET_REG16(LMotorPwm_COUNTER_LSB_PTR, counter);
    }


    /*******************************************************************************
    * Function Name: LMotorPwm_ReadCounter
    ********************************************************************************
    * 
    * Summary:
    *  This function returns the current value of the counter.  It doesn't matter
    *  if the counter is enabled or running.
    *
    * Parameters:  
    *  None  
    *
    * Return: 
    *  The current value of the counter.
    *
    *******************************************************************************/
    uint16 LMotorPwm_ReadCounter(void) 
    {
        /* Force capture by reading Accumulator */
        /* Must first do a software capture to be able to read the counter */
        /* It is up to the user code to make sure there isn't already captured data in the FIFO */
        (void)LMotorPwm_COUNTERCAP_LSB;
        
        /* Read the data from the FIFO (or capture register for Fixed Function)*/
        return (CY_GET_REG16(LMotorPwm_CAPTURE_LSB_PTR));
    }

        #if (LMotorPwm_UseStatus)


            /*******************************************************************************
            * Function Name: LMotorPwm_ClearFIFO
            ********************************************************************************
            * 
            * Summary:
            *  This function clears all capture data from the capture FIFO
            *
            * Parameters:  
            *  None
            *
            * Return: 
            *  None
            *
            *******************************************************************************/
            void LMotorPwm_ClearFIFO(void) 
            {
                while(0u != (LMotorPwm_ReadStatusRegister() & LMotorPwm_STATUS_FIFONEMPTY))
                {
                    (void)LMotorPwm_ReadCapture();
                }
            }

        #endif /* LMotorPwm_UseStatus */

#endif /* !LMotorPwm_UsingFixedFunction */


/*******************************************************************************
* Function Name: LMotorPwm_WritePeriod
********************************************************************************
* 
* Summary:
*  This function is used to change the period of the counter.  The new period 
*  will be loaded the next time terminal count is detected.
*
* Parameters:  
*  period:  Period value. May be between 1 and (2^Resolution)-1.  A value of 0 
*           will result in the counter remaining at zero.
*
* Return: 
*  None
*
*******************************************************************************/
void LMotorPwm_WritePeriod(uint16 period) 
{
    #if(LMotorPwm_UsingFixedFunction)
        CY_SET_REG16(LMotorPwm_PERIOD_LSB_PTR, (uint16)period);
    #else
        CY_SET_REG16(LMotorPwm_PERIOD_LSB_PTR, period);
    #endif /* (LMotorPwm_UsingFixedFunction) */
}

#if (LMotorPwm_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: LMotorPwm_WriteCompare
    ********************************************************************************
    * 
    * Summary:
    *  This funtion is used to change the compare1 value when the PWM is in Dither
    *  mode. The compare output will reflect the new value on the next UDB clock. 
    *  The compare output will be driven high when the present counter value is 
    *  compared to the compare value based on the compare mode defined in 
    *  Dither Mode.
    *
    * Parameters:  
    *  compare:  New compare value.  
    *
    * Return: 
    *  None
    *
    * Side Effects:
    *  This function is only available if the PWM mode parameter is set to
    *  Dither Mode, Center Aligned Mode or One Output Mode
    *
    *******************************************************************************/
    void LMotorPwm_WriteCompare(uint16 compare) \
                                       
    {	
		#if(LMotorPwm_UsingFixedFunction)
			CY_SET_REG16(LMotorPwm_COMPARE1_LSB_PTR, (uint16)compare);
		#else
	        CY_SET_REG16(LMotorPwm_COMPARE1_LSB_PTR, compare);	
		#endif /* (LMotorPwm_UsingFixedFunction) */
        
        #if (LMotorPwm_PWMMode == LMotorPwm__B_PWM__DITHER)
            #if(LMotorPwm_UsingFixedFunction)
    			CY_SET_REG16(LMotorPwm_COMPARE2_LSB_PTR, (uint16)(compare + 1u));
    		#else
    	        CY_SET_REG16(LMotorPwm_COMPARE2_LSB_PTR, (compare + 1u));	
    		#endif /* (LMotorPwm_UsingFixedFunction) */
        #endif /* (LMotorPwm_PWMMode == LMotorPwm__B_PWM__DITHER) */
    }


#else


    /*******************************************************************************
    * Function Name: LMotorPwm_WriteCompare1
    ********************************************************************************
    * 
    * Summary:
    *  This funtion is used to change the compare1 value.  The compare output will 
    *  reflect the new value on the next UDB clock.  The compare output will be 
    *  driven high when the present counter value is less than or less than or 
    *  equal to the compare register, depending on the mode.
    *
    * Parameters:  
    *  compare:  New compare value.  
    *
    * Return: 
    *  None
    *
    *******************************************************************************/
    void LMotorPwm_WriteCompare1(uint16 compare) \
                                        
    {
        #if(LMotorPwm_UsingFixedFunction)
            CY_SET_REG16(LMotorPwm_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG16(LMotorPwm_COMPARE1_LSB_PTR, compare);
        #endif /* (LMotorPwm_UsingFixedFunction) */
    }


    /*******************************************************************************
    * Function Name: LMotorPwm_WriteCompare2
    ********************************************************************************
    * 
    * Summary:
    *  This funtion is used to change the compare value, for compare1 output.  
    *  The compare output will reflect the new value on the next UDB clock.  
    *  The compare output will be driven high when the present counter value is 
    *  less than or less than or equal to the compare register, depending on the 
    *  mode.
    *
    * Parameters:  
    *  compare:  New compare value.  
    *
    * Return: 
    *  None
    *
    *******************************************************************************/
    void LMotorPwm_WriteCompare2(uint16 compare) \
                                        
    {
        #if(LMotorPwm_UsingFixedFunction)
            CY_SET_REG16(LMotorPwm_COMPARE2_LSB_PTR, compare);
        #else
            CY_SET_REG16(LMotorPwm_COMPARE2_LSB_PTR, compare);
        #endif /* (LMotorPwm_UsingFixedFunction) */
    }
#endif /* UseOneCompareMode */

#if (LMotorPwm_DeadBandUsed)


    /*******************************************************************************
    * Function Name: LMotorPwm_WriteDeadTime
    ********************************************************************************
    * 
    * Summary:
    *  This function writes the dead-band counts to the corresponding register
    *
    * Parameters:  
    *  deadtime:  Number of counts for dead time 
    *
    * Return: 
    *  None
    *
    *******************************************************************************/
    void LMotorPwm_WriteDeadTime(uint8 deadtime) 
    {
        /* If using the Dead Band 1-255 mode then just write the register */
        #if(!LMotorPwm_DeadBand2_4)
            CY_SET_REG8(LMotorPwm_DEADBAND_COUNT_PTR, deadtime);
        #else
            /* Otherwise the data has to be masked and offset */        
            /* Clear existing data */
            LMotorPwm_DEADBAND_COUNT &= ((uint8)(~LMotorPwm_DEADBAND_COUNT_MASK));
            
            /* Set new dead time */
            #if(LMotorPwm_DEADBAND_COUNT_SHIFT)        
                LMotorPwm_DEADBAND_COUNT |= ((uint8)((uint8)deadtime << LMotorPwm_DEADBAND_COUNT_SHIFT)) & 
                                                    LMotorPwm_DEADBAND_COUNT_MASK;
            #else
                LMotorPwm_DEADBAND_COUNT |= deadtime & LMotorPwm_DEADBAND_COUNT_MASK;        
            #endif /* (LMotorPwm_DEADBAND_COUNT_SHIFT) */
        
        #endif /* (!LMotorPwm_DeadBand2_4) */
    }


    /*******************************************************************************
    * Function Name: LMotorPwm_ReadDeadTime
    ********************************************************************************
    * 
    * Summary:
    *  This function reads the dead-band counts from the corresponding register
    *
    * Parameters:  
    *  None
    *
    * Return: 
    *  Dead Band Counts
    *
    *******************************************************************************/
    uint8 LMotorPwm_ReadDeadTime(void) 
    {
        /* If using the Dead Band 1-255 mode then just read the register */
        #if(!LMotorPwm_DeadBand2_4)
            return (CY_GET_REG8(LMotorPwm_DEADBAND_COUNT_PTR));
        #else
        
            /* Otherwise the data has to be masked and offset */
            #if(LMotorPwm_DEADBAND_COUNT_SHIFT)      
                return ((uint8)(((uint8)(LMotorPwm_DEADBAND_COUNT & LMotorPwm_DEADBAND_COUNT_MASK)) >> 
                                                                           LMotorPwm_DEADBAND_COUNT_SHIFT));
            #else
                return (LMotorPwm_DEADBAND_COUNT & LMotorPwm_DEADBAND_COUNT_MASK);
            #endif /* (LMotorPwm_DEADBAND_COUNT_SHIFT) */
        #endif /* (!LMotorPwm_DeadBand2_4) */
    }
#endif /* DeadBandUsed */

#if (LMotorPwm_UseStatus || LMotorPwm_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: LMotorPwm_SetInterruptMode
    ********************************************************************************
    * 
    * Summary:
    *  This function configures the interrupts mask control of theinterrupt 
    *  source status register.
    *
    * Parameters:  
    *  uint8 interruptMode: Bit field containing the interrupt sources enabled 
    *
    * Return: 
    *  None
    *
    *******************************************************************************/
    void LMotorPwm_SetInterruptMode(uint8 interruptMode)  
    {
    	CY_SET_REG8(LMotorPwm_STATUS_MASK_PTR, interruptMode);
    }


    /*******************************************************************************
    * Function Name: LMotorPwm_ReadStatusRegister
    ********************************************************************************
    * 
    * Summary:
    *  This function returns the current state of the status register. 
    *
    * Parameters:  
    *  None
    *
    * Return: 
    *  uint8 : Current status register value. The status register bits are:
    *  [7:6] : Unused(0)
    *  [5]   : Kill event output
    *  [4]   : FIFO not empty
    *  [3]   : FIFO full
    *  [2]   : Terminal count
    *  [1]   : Compare output 2
    *  [0]   : Compare output 1
    *
    *******************************************************************************/
    uint8 LMotorPwm_ReadStatusRegister(void)   
    {
    	uint8 result;
    	
    	result = CY_GET_REG8(LMotorPwm_STATUS_PTR);
    	return (result);
    }

#endif /* (LMotorPwm_UseStatus || LMotorPwm_UsingFixedFunction) */


#if (LMotorPwm_UseControl)


    /*******************************************************************************
    * Function Name: LMotorPwm_ReadControlRegister
    ********************************************************************************
    * 
    * Summary:
    *  Returns the current state of the control register. This API is available 
    *  only if the control register is not removed.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  uint8 : Current control register value
    *
    *******************************************************************************/    
    uint8 LMotorPwm_ReadControlRegister(void) 
    {
    	uint8 result;
    	
    	result = CY_GET_REG8(LMotorPwm_CONTROL_PTR);
    	return (result);
    }


    /*******************************************************************************
    * Function Name: LMotorPwm_WriteControlRegister
    ********************************************************************************
    * 
    * Summary:
    *  Sets the bit field of the control register. This API is available only if 
    *  the control register is not removed.
    *
    * Parameters:  
    *  uint8 control: Control register bit field, The status register bits are:
    *  [7]   : PWM Enable
    *  [6]   : Reset
    *  [5:3] : Compare Mode2
    *  [2:0] : Compare Mode2
    *
    * Return: 
    *  None
    *
    *******************************************************************************/  
    void LMotorPwm_WriteControlRegister(uint8 control) 
    {
    	CY_SET_REG8(LMotorPwm_CONTROL_PTR, control);
    }
	
#endif /* (LMotorPwm_UseControl) */


#if (!LMotorPwm_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: LMotorPwm_ReadCapture
    ********************************************************************************
    * 
    * Summary:
    *  Reads the capture value from the capture FIFO.
    *
    * Parameters:  
    *  None
    *
    * Return: 
    *  uint8/uint16: The current capture value
    *
    *******************************************************************************/  
    uint16 LMotorPwm_ReadCapture(void)  
    {
    	return (CY_GET_REG16(LMotorPwm_CAPTURE_LSB_PTR));
    }
	
#endif /* (!LMotorPwm_UsingFixedFunction) */


#if (LMotorPwm_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: LMotorPwm_ReadCompare
    ********************************************************************************
    * 
    * Summary:
    *  Reads the compare value for the compare output when the PWM Mode parameter is 
    *  set to Dither mode, Center Aligned mode, or One Output mode.
    *
    * Parameters:  
    *  None
    *
    * Return: 
    *  uint8/uint16: Current compare value
    *
    *******************************************************************************/  
    uint16 LMotorPwm_ReadCompare(void)  
    {
		#if(LMotorPwm_UsingFixedFunction)
            return ((uint16)CY_GET_REG16(LMotorPwm_COMPARE1_LSB_PTR));
        #else
            return (CY_GET_REG16(LMotorPwm_COMPARE1_LSB_PTR));
        #endif /* (LMotorPwm_UsingFixedFunction) */
    }

#else


    /*******************************************************************************
    * Function Name: LMotorPwm_ReadCompare1
    ********************************************************************************
    * 
    * Summary:
    *  Reads the compare value for the compare1 output.
    *
    * Parameters:  
    *  None
    *
    * Return: 
    *  uint8/uint16: Current compare value.
    *
    *******************************************************************************/  
    uint16 LMotorPwm_ReadCompare1(void) 
    {
		return (CY_GET_REG16(LMotorPwm_COMPARE1_LSB_PTR));
    }


    /*******************************************************************************
    * Function Name: LMotorPwm_ReadCompare2
    ********************************************************************************
    * 
    * Summary:
    *  Reads the compare value for the compare2 output.
    *
    * Parameters:  
    *  None
    *
    * Return: 
    *  uint8/uint16: Current compare value.
    *
    *******************************************************************************/  
    uint16 LMotorPwm_ReadCompare2(void)  
    {
		return (CY_GET_REG16(LMotorPwm_COMPARE2_LSB_PTR));
    }

#endif /* (LMotorPwm_UseOneCompareMode) */


/*******************************************************************************
* Function Name: LMotorPwm_ReadPeriod
********************************************************************************
* 
* Summary:
*  Reads the period value used by the PWM hardware.
*
* Parameters:  
*  None
*
* Return: 
*  uint8/16: Period value
*
*******************************************************************************/ 
uint16 LMotorPwm_ReadPeriod(void) 
{
	#if(LMotorPwm_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(LMotorPwm_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG16(LMotorPwm_PERIOD_LSB_PTR));
    #endif /* (LMotorPwm_UsingFixedFunction) */
}

#if ( LMotorPwm_KillModeMinTime)


    /*******************************************************************************
    * Function Name: LMotorPwm_WriteKillTime
    ********************************************************************************
    * 
    * Summary:
    *  Writes the kill time value used by the hardware when the Kill Mode 
    *  is set to Minimum Time.
    *
    * Parameters:  
    *  uint8: Minimum Time kill counts
    *
    * Return: 
    *  None
    *
    *******************************************************************************/ 
    void LMotorPwm_WriteKillTime(uint8 killtime) 
    {
    	CY_SET_REG8(LMotorPwm_KILLMODEMINTIME_PTR, killtime);
    }


    /*******************************************************************************
    * Function Name: LMotorPwm_ReadKillTime
    ********************************************************************************
    * 
    * Summary:
    *  Reads the kill time value used by the hardware when the Kill Mode is set 
    *  to Minimum Time.
    *
    * Parameters:  
    *  None
    *
    * Return: 
    *  uint8: The current Minimum Time kill counts
    *
    *******************************************************************************/ 
    uint8 LMotorPwm_ReadKillTime(void) 
    {
    	return (CY_GET_REG8(LMotorPwm_KILLMODEMINTIME_PTR));
    }

#endif /* ( LMotorPwm_KillModeMinTime) */

/* [] END OF FILE */
