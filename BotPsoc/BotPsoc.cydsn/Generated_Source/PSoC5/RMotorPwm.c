/*******************************************************************************
* File Name: RMotorPwm.c  
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
#include "RMotorPwm.h"

uint8 RMotorPwm_initVar = 0u;


/*******************************************************************************
* Function Name: RMotorPwm_Start
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
*  RMotorPwm_initVar: Is modified when this function is called for the 
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void RMotorPwm_Start(void) 
{
    /* If not Initialized then initialize all required hardware and software */
    if(RMotorPwm_initVar == 0u)
    {
        RMotorPwm_Init();
        RMotorPwm_initVar = 1u;
    }
    RMotorPwm_Enable();

}


/*******************************************************************************
* Function Name: RMotorPwm_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the 
*  customizer of the component placed onto schematic. Usually called in 
*  RMotorPwm_Start().
*
* Parameters:  
*  None
*
* Return: 
*  None
*
*******************************************************************************/
void RMotorPwm_Init(void) 
{
    #if (RMotorPwm_UsingFixedFunction || RMotorPwm_UseControl)
        uint8 ctrl;
    #endif /* (RMotorPwm_UsingFixedFunction || RMotorPwm_UseControl) */
    
    #if(!RMotorPwm_UsingFixedFunction) 
        #if(RMotorPwm_UseStatus)
            /* Interrupt State Backup for Critical Region*/
            uint8 RMotorPwm_interruptState;
        #endif /* (RMotorPwm_UseStatus) */
    #endif /* (!RMotorPwm_UsingFixedFunction) */
    
    #if (RMotorPwm_UsingFixedFunction)
        /* You are allowed to write the compare value (FF only) */
        RMotorPwm_CONTROL |= RMotorPwm_CFG0_MODE;
        #if (RMotorPwm_DeadBand2_4)
            RMotorPwm_CONTROL |= RMotorPwm_CFG0_DB;
        #endif /* (RMotorPwm_DeadBand2_4) */
                
        ctrl = RMotorPwm_CONTROL3 & ((uint8 )(~RMotorPwm_CTRL_CMPMODE1_MASK));
        RMotorPwm_CONTROL3 = ctrl | RMotorPwm_DEFAULT_COMPARE1_MODE;
        
         /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
        RMotorPwm_RT1 &= ((uint8)(~RMotorPwm_RT1_MASK));
        RMotorPwm_RT1 |= RMotorPwm_SYNC;     
                
        /*Enable DSI Sync all all inputs of the PWM*/
        RMotorPwm_RT1 &= ((uint8)(~RMotorPwm_SYNCDSI_MASK));
        RMotorPwm_RT1 |= RMotorPwm_SYNCDSI_EN;
       
    #elif (RMotorPwm_UseControl)
        /* Set the default compare mode defined in the parameter */
        ctrl = RMotorPwm_CONTROL & ((uint8)(~RMotorPwm_CTRL_CMPMODE2_MASK)) & ((uint8)(~RMotorPwm_CTRL_CMPMODE1_MASK));
        RMotorPwm_CONTROL = ctrl | RMotorPwm_DEFAULT_COMPARE2_MODE | 
                                   RMotorPwm_DEFAULT_COMPARE1_MODE;
    #endif /* (RMotorPwm_UsingFixedFunction) */
        
    #if (!RMotorPwm_UsingFixedFunction)
        #if (RMotorPwm_Resolution == 8)
            /* Set FIFO 0 to 1 byte register for period*/
            RMotorPwm_AUX_CONTROLDP0 |= (RMotorPwm_AUX_CTRL_FIFO0_CLR);
        #else /* (RMotorPwm_Resolution == 16)*/
            /* Set FIFO 0 to 1 byte register for period */
            RMotorPwm_AUX_CONTROLDP0 |= (RMotorPwm_AUX_CTRL_FIFO0_CLR);
            RMotorPwm_AUX_CONTROLDP1 |= (RMotorPwm_AUX_CTRL_FIFO0_CLR);
        #endif /* (RMotorPwm_Resolution == 8) */

        RMotorPwm_WriteCounter(RMotorPwm_INIT_PERIOD_VALUE);
    #endif /* (!RMotorPwm_UsingFixedFunction) */
        
    RMotorPwm_WritePeriod(RMotorPwm_INIT_PERIOD_VALUE);

        #if (RMotorPwm_UseOneCompareMode)
            RMotorPwm_WriteCompare(RMotorPwm_INIT_COMPARE_VALUE1);
        #else
            RMotorPwm_WriteCompare1(RMotorPwm_INIT_COMPARE_VALUE1);
            RMotorPwm_WriteCompare2(RMotorPwm_INIT_COMPARE_VALUE2);
        #endif /* (RMotorPwm_UseOneCompareMode) */
        
        #if (RMotorPwm_KillModeMinTime)
            RMotorPwm_WriteKillTime(RMotorPwm_MinimumKillTime);
        #endif /* (RMotorPwm_KillModeMinTime) */
        
        #if (RMotorPwm_DeadBandUsed)
            RMotorPwm_WriteDeadTime(RMotorPwm_INIT_DEAD_TIME);
        #endif /* (RMotorPwm_DeadBandUsed) */

    #if (RMotorPwm_UseStatus || RMotorPwm_UsingFixedFunction)
        RMotorPwm_SetInterruptMode(RMotorPwm_INIT_INTERRUPTS_MODE);
    #endif /* (RMotorPwm_UseStatus || RMotorPwm_UsingFixedFunction) */
        
    #if (RMotorPwm_UsingFixedFunction)
        /* Globally Enable the Fixed Function Block chosen */
        RMotorPwm_GLOBAL_ENABLE |= RMotorPwm_BLOCK_EN_MASK;
        /* Set the Interrupt source to come from the status register */
        RMotorPwm_CONTROL2 |= RMotorPwm_CTRL2_IRQ_SEL;
    #else
        #if(RMotorPwm_UseStatus)
            
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            RMotorPwm_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            RMotorPwm_STATUS_AUX_CTRL |= RMotorPwm_STATUS_ACTL_INT_EN_MASK;
            
             /* Exit Critical Region*/
            CyExitCriticalSection(RMotorPwm_interruptState);
            
            /* Clear the FIFO to enable the RMotorPwm_STATUS_FIFOFULL
                   bit to be set on FIFO full. */
            RMotorPwm_ClearFIFO();
        #endif /* (RMotorPwm_UseStatus) */
    #endif /* (RMotorPwm_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: RMotorPwm_Enable
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
void RMotorPwm_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (RMotorPwm_UsingFixedFunction)
        RMotorPwm_GLOBAL_ENABLE |= RMotorPwm_BLOCK_EN_MASK;
        RMotorPwm_GLOBAL_STBY_ENABLE |= RMotorPwm_BLOCK_STBY_EN_MASK;
    #endif /* (RMotorPwm_UsingFixedFunction) */
    
    /* Enable the PWM from the control register  */
    #if (RMotorPwm_UseControl || RMotorPwm_UsingFixedFunction)
        RMotorPwm_CONTROL |= RMotorPwm_CTRL_ENABLE;
    #endif /* (RMotorPwm_UseControl || RMotorPwm_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: RMotorPwm_Stop
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
void RMotorPwm_Stop(void) 
{
    #if (RMotorPwm_UseControl || RMotorPwm_UsingFixedFunction)
        RMotorPwm_CONTROL &= ((uint8)(~RMotorPwm_CTRL_ENABLE));
    #endif /* (RMotorPwm_UseControl || RMotorPwm_UsingFixedFunction) */
    
    /* Globally disable the Fixed Function Block chosen */
    #if (RMotorPwm_UsingFixedFunction)
        RMotorPwm_GLOBAL_ENABLE &= ((uint8)(~RMotorPwm_BLOCK_EN_MASK));
        RMotorPwm_GLOBAL_STBY_ENABLE &= ((uint8)(~RMotorPwm_BLOCK_STBY_EN_MASK));
    #endif /* (RMotorPwm_UsingFixedFunction) */
}


#if (RMotorPwm_UseOneCompareMode)
	#if (RMotorPwm_CompareMode1SW)


		/*******************************************************************************
		* Function Name: RMotorPwm_SetCompareMode
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
		void RMotorPwm_SetCompareMode(uint8 comparemode) 
		{
		    #if(RMotorPwm_UsingFixedFunction)
            
                #if(0 != RMotorPwm_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemodemasked = ((uint8)((uint8)comparemode << RMotorPwm_CTRL_CMPMODE1_SHIFT));
                #else
                    uint8 comparemodemasked = comparemode;
                #endif /* (0 != RMotorPwm_CTRL_CMPMODE1_SHIFT) */
            
	            RMotorPwm_CONTROL3 &= ((uint8)(~RMotorPwm_CTRL_CMPMODE1_MASK)); /*Clear Existing Data */
	            RMotorPwm_CONTROL3 |= comparemodemasked;     
		                
		    #elif (RMotorPwm_UseControl)
		        
                #if(0 != RMotorPwm_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemode1masked = ((uint8)((uint8)comparemode << RMotorPwm_CTRL_CMPMODE1_SHIFT)) & 
    		                                    RMotorPwm_CTRL_CMPMODE1_MASK;
                #else
                    uint8 comparemode1masked = comparemode & RMotorPwm_CTRL_CMPMODE1_MASK;                
                #endif /* (0 != RMotorPwm_CTRL_CMPMODE1_SHIFT) */
                
                #if(0 != RMotorPwm_CTRL_CMPMODE2_SHIFT)                            
    		        uint8 comparemode2masked = ((uint8)((uint8)comparemode << RMotorPwm_CTRL_CMPMODE2_SHIFT)) & 
    		                                   RMotorPwm_CTRL_CMPMODE2_MASK;
                #else
    		        uint8 comparemode2masked = comparemode & RMotorPwm_CTRL_CMPMODE2_MASK;                
                #endif /* (0 != RMotorPwm_CTRL_CMPMODE2_SHIFT) */
                
		        /*Clear existing mode */
		        RMotorPwm_CONTROL &= ((uint8)(~(RMotorPwm_CTRL_CMPMODE1_MASK | RMotorPwm_CTRL_CMPMODE2_MASK))); 
		        RMotorPwm_CONTROL |= (comparemode1masked | comparemode2masked);
		        
		    #else
		        uint8 temp = comparemode;
		    #endif /* (RMotorPwm_UsingFixedFunction) */
		}
	#endif /* RMotorPwm_CompareMode1SW */

#else /* UseOneCompareMode */

	#if (RMotorPwm_CompareMode1SW)


		/*******************************************************************************
		* Function Name: RMotorPwm_SetCompareMode1
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
		void RMotorPwm_SetCompareMode1(uint8 comparemode) 
		{
		    #if(0 != RMotorPwm_CTRL_CMPMODE1_SHIFT)
                uint8 comparemodemasked = ((uint8)((uint8)comparemode << RMotorPwm_CTRL_CMPMODE1_SHIFT)) & 
    		                               RMotorPwm_CTRL_CMPMODE1_MASK;
		    #else
                uint8 comparemodemasked = comparemode & RMotorPwm_CTRL_CMPMODE1_MASK;                
            #endif /* (0 != RMotorPwm_CTRL_CMPMODE1_SHIFT) */
                   
		    #if (RMotorPwm_UseControl)
		        RMotorPwm_CONTROL &= ((uint8)(~RMotorPwm_CTRL_CMPMODE1_MASK)); /*Clear existing mode */
		        RMotorPwm_CONTROL |= comparemodemasked;
		    #endif /* (RMotorPwm_UseControl) */
		}
	#endif /* RMotorPwm_CompareMode1SW */

#if (RMotorPwm_CompareMode2SW)


    /*******************************************************************************
    * Function Name: RMotorPwm_SetCompareMode2
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
    void RMotorPwm_SetCompareMode2(uint8 comparemode) 
    {

        #if(0 != RMotorPwm_CTRL_CMPMODE2_SHIFT)
            uint8 comparemodemasked = ((uint8)((uint8)comparemode << RMotorPwm_CTRL_CMPMODE2_SHIFT)) & 
                                                 RMotorPwm_CTRL_CMPMODE2_MASK;
        #else
            uint8 comparemodemasked = comparemode & RMotorPwm_CTRL_CMPMODE2_MASK;            
        #endif /* (0 != RMotorPwm_CTRL_CMPMODE2_SHIFT) */
        
        #if (RMotorPwm_UseControl)
            RMotorPwm_CONTROL &= ((uint8)(~RMotorPwm_CTRL_CMPMODE2_MASK)); /*Clear existing mode */
            RMotorPwm_CONTROL |= comparemodemasked;
        #endif /* (RMotorPwm_UseControl) */
    }
    #endif /*RMotorPwm_CompareMode2SW */

#endif /* UseOneCompareMode */


#if (!RMotorPwm_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: RMotorPwm_WriteCounter
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
    void RMotorPwm_WriteCounter(uint16 counter) \
                                       
    {
        CY_SET_REG16(RMotorPwm_COUNTER_LSB_PTR, counter);
    }


    /*******************************************************************************
    * Function Name: RMotorPwm_ReadCounter
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
    uint16 RMotorPwm_ReadCounter(void) 
    {
        /* Force capture by reading Accumulator */
        /* Must first do a software capture to be able to read the counter */
        /* It is up to the user code to make sure there isn't already captured data in the FIFO */
        (void)RMotorPwm_COUNTERCAP_LSB;
        
        /* Read the data from the FIFO (or capture register for Fixed Function)*/
        return (CY_GET_REG16(RMotorPwm_CAPTURE_LSB_PTR));
    }

        #if (RMotorPwm_UseStatus)


            /*******************************************************************************
            * Function Name: RMotorPwm_ClearFIFO
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
            void RMotorPwm_ClearFIFO(void) 
            {
                while(0u != (RMotorPwm_ReadStatusRegister() & RMotorPwm_STATUS_FIFONEMPTY))
                {
                    (void)RMotorPwm_ReadCapture();
                }
            }

        #endif /* RMotorPwm_UseStatus */

#endif /* !RMotorPwm_UsingFixedFunction */


/*******************************************************************************
* Function Name: RMotorPwm_WritePeriod
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
void RMotorPwm_WritePeriod(uint16 period) 
{
    #if(RMotorPwm_UsingFixedFunction)
        CY_SET_REG16(RMotorPwm_PERIOD_LSB_PTR, (uint16)period);
    #else
        CY_SET_REG16(RMotorPwm_PERIOD_LSB_PTR, period);
    #endif /* (RMotorPwm_UsingFixedFunction) */
}

#if (RMotorPwm_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: RMotorPwm_WriteCompare
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
    void RMotorPwm_WriteCompare(uint16 compare) \
                                       
    {	
		#if(RMotorPwm_UsingFixedFunction)
			CY_SET_REG16(RMotorPwm_COMPARE1_LSB_PTR, (uint16)compare);
		#else
	        CY_SET_REG16(RMotorPwm_COMPARE1_LSB_PTR, compare);	
		#endif /* (RMotorPwm_UsingFixedFunction) */
        
        #if (RMotorPwm_PWMMode == RMotorPwm__B_PWM__DITHER)
            #if(RMotorPwm_UsingFixedFunction)
    			CY_SET_REG16(RMotorPwm_COMPARE2_LSB_PTR, (uint16)(compare + 1u));
    		#else
    	        CY_SET_REG16(RMotorPwm_COMPARE2_LSB_PTR, (compare + 1u));	
    		#endif /* (RMotorPwm_UsingFixedFunction) */
        #endif /* (RMotorPwm_PWMMode == RMotorPwm__B_PWM__DITHER) */
    }


#else


    /*******************************************************************************
    * Function Name: RMotorPwm_WriteCompare1
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
    void RMotorPwm_WriteCompare1(uint16 compare) \
                                        
    {
        #if(RMotorPwm_UsingFixedFunction)
            CY_SET_REG16(RMotorPwm_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG16(RMotorPwm_COMPARE1_LSB_PTR, compare);
        #endif /* (RMotorPwm_UsingFixedFunction) */
    }


    /*******************************************************************************
    * Function Name: RMotorPwm_WriteCompare2
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
    void RMotorPwm_WriteCompare2(uint16 compare) \
                                        
    {
        #if(RMotorPwm_UsingFixedFunction)
            CY_SET_REG16(RMotorPwm_COMPARE2_LSB_PTR, compare);
        #else
            CY_SET_REG16(RMotorPwm_COMPARE2_LSB_PTR, compare);
        #endif /* (RMotorPwm_UsingFixedFunction) */
    }
#endif /* UseOneCompareMode */

#if (RMotorPwm_DeadBandUsed)


    /*******************************************************************************
    * Function Name: RMotorPwm_WriteDeadTime
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
    void RMotorPwm_WriteDeadTime(uint8 deadtime) 
    {
        /* If using the Dead Band 1-255 mode then just write the register */
        #if(!RMotorPwm_DeadBand2_4)
            CY_SET_REG8(RMotorPwm_DEADBAND_COUNT_PTR, deadtime);
        #else
            /* Otherwise the data has to be masked and offset */        
            /* Clear existing data */
            RMotorPwm_DEADBAND_COUNT &= ((uint8)(~RMotorPwm_DEADBAND_COUNT_MASK));
            
            /* Set new dead time */
            #if(RMotorPwm_DEADBAND_COUNT_SHIFT)        
                RMotorPwm_DEADBAND_COUNT |= ((uint8)((uint8)deadtime << RMotorPwm_DEADBAND_COUNT_SHIFT)) & 
                                                    RMotorPwm_DEADBAND_COUNT_MASK;
            #else
                RMotorPwm_DEADBAND_COUNT |= deadtime & RMotorPwm_DEADBAND_COUNT_MASK;        
            #endif /* (RMotorPwm_DEADBAND_COUNT_SHIFT) */
        
        #endif /* (!RMotorPwm_DeadBand2_4) */
    }


    /*******************************************************************************
    * Function Name: RMotorPwm_ReadDeadTime
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
    uint8 RMotorPwm_ReadDeadTime(void) 
    {
        /* If using the Dead Band 1-255 mode then just read the register */
        #if(!RMotorPwm_DeadBand2_4)
            return (CY_GET_REG8(RMotorPwm_DEADBAND_COUNT_PTR));
        #else
        
            /* Otherwise the data has to be masked and offset */
            #if(RMotorPwm_DEADBAND_COUNT_SHIFT)      
                return ((uint8)(((uint8)(RMotorPwm_DEADBAND_COUNT & RMotorPwm_DEADBAND_COUNT_MASK)) >> 
                                                                           RMotorPwm_DEADBAND_COUNT_SHIFT));
            #else
                return (RMotorPwm_DEADBAND_COUNT & RMotorPwm_DEADBAND_COUNT_MASK);
            #endif /* (RMotorPwm_DEADBAND_COUNT_SHIFT) */
        #endif /* (!RMotorPwm_DeadBand2_4) */
    }
#endif /* DeadBandUsed */

#if (RMotorPwm_UseStatus || RMotorPwm_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: RMotorPwm_SetInterruptMode
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
    void RMotorPwm_SetInterruptMode(uint8 interruptMode)  
    {
    	CY_SET_REG8(RMotorPwm_STATUS_MASK_PTR, interruptMode);
    }


    /*******************************************************************************
    * Function Name: RMotorPwm_ReadStatusRegister
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
    uint8 RMotorPwm_ReadStatusRegister(void)   
    {
    	uint8 result;
    	
    	result = CY_GET_REG8(RMotorPwm_STATUS_PTR);
    	return (result);
    }

#endif /* (RMotorPwm_UseStatus || RMotorPwm_UsingFixedFunction) */


#if (RMotorPwm_UseControl)


    /*******************************************************************************
    * Function Name: RMotorPwm_ReadControlRegister
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
    uint8 RMotorPwm_ReadControlRegister(void) 
    {
    	uint8 result;
    	
    	result = CY_GET_REG8(RMotorPwm_CONTROL_PTR);
    	return (result);
    }


    /*******************************************************************************
    * Function Name: RMotorPwm_WriteControlRegister
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
    void RMotorPwm_WriteControlRegister(uint8 control) 
    {
    	CY_SET_REG8(RMotorPwm_CONTROL_PTR, control);
    }
	
#endif /* (RMotorPwm_UseControl) */


#if (!RMotorPwm_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: RMotorPwm_ReadCapture
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
    uint16 RMotorPwm_ReadCapture(void)  
    {
    	return (CY_GET_REG16(RMotorPwm_CAPTURE_LSB_PTR));
    }
	
#endif /* (!RMotorPwm_UsingFixedFunction) */


#if (RMotorPwm_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: RMotorPwm_ReadCompare
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
    uint16 RMotorPwm_ReadCompare(void)  
    {
		#if(RMotorPwm_UsingFixedFunction)
            return ((uint16)CY_GET_REG16(RMotorPwm_COMPARE1_LSB_PTR));
        #else
            return (CY_GET_REG16(RMotorPwm_COMPARE1_LSB_PTR));
        #endif /* (RMotorPwm_UsingFixedFunction) */
    }

#else


    /*******************************************************************************
    * Function Name: RMotorPwm_ReadCompare1
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
    uint16 RMotorPwm_ReadCompare1(void) 
    {
		return (CY_GET_REG16(RMotorPwm_COMPARE1_LSB_PTR));
    }


    /*******************************************************************************
    * Function Name: RMotorPwm_ReadCompare2
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
    uint16 RMotorPwm_ReadCompare2(void)  
    {
		return (CY_GET_REG16(RMotorPwm_COMPARE2_LSB_PTR));
    }

#endif /* (RMotorPwm_UseOneCompareMode) */


/*******************************************************************************
* Function Name: RMotorPwm_ReadPeriod
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
uint16 RMotorPwm_ReadPeriod(void) 
{
	#if(RMotorPwm_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(RMotorPwm_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG16(RMotorPwm_PERIOD_LSB_PTR));
    #endif /* (RMotorPwm_UsingFixedFunction) */
}

#if ( RMotorPwm_KillModeMinTime)


    /*******************************************************************************
    * Function Name: RMotorPwm_WriteKillTime
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
    void RMotorPwm_WriteKillTime(uint8 killtime) 
    {
    	CY_SET_REG8(RMotorPwm_KILLMODEMINTIME_PTR, killtime);
    }


    /*******************************************************************************
    * Function Name: RMotorPwm_ReadKillTime
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
    uint8 RMotorPwm_ReadKillTime(void) 
    {
    	return (CY_GET_REG8(RMotorPwm_KILLMODEMINTIME_PTR));
    }

#endif /* ( RMotorPwm_KillModeMinTime) */

/* [] END OF FILE */
