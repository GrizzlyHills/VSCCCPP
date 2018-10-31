#include <stdio.h>

#include "GPIO_Lib.h"



/**
  * @brief  Initializes the GPIOx peripheral according to the specified
  *         parameters in the GPIO_InitStruct.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @param  GPIO_InitStruct: pointer to a GPIO_InitTypeDef structure that
  *         contains the configuration information for the specified GPIO peripheral.
  * @retval None
  */
void GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_InitStruct)
{
    uint32_t currentmode = 0x00, currentpin = 0x00, pinpos = 0x00, pos = 0x00;
    uint32_t tmpreg = 0x00, pinmask = 0x00;
    GPIOx->CRH = 0x44444444;
    /* Check the parameters */
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GPIO_MODE(GPIO_InitStruct->GPIO_Mode));
    assert_param(IS_GPIO_PIN(GPIO_InitStruct->GPIO_Pin));

    /*---------------------------- GPIO Mode Configuration -----------------------*/
    currentmode = ((uint32_t)GPIO_InitStruct->GPIO_Mode) & ((uint32_t)0x0F);
    if ((((uint32_t)GPIO_InitStruct->GPIO_Mode) & ((uint32_t)0x10)) != 0x00)
    {
        /* Check the parameters */
        assert_param(IS_GPIO_SPEED(GPIO_InitStruct->GPIO_Speed));
        /* Output mode */
        currentmode |= (uint32_t)GPIO_InitStruct->GPIO_Speed;
    }
    /*---------------------------- GPIO CRL Configuration ------------------------*/
    /* Configure the eight low port pins */
    if (((uint32_t)GPIO_InitStruct->GPIO_Pin & ((uint32_t)0x00FF)) != 0x00)
    {
        tmpreg = GPIOx->CRL;
        for (pinpos = 0x00; pinpos < 0x08; pinpos++)
        {
            pos = ((uint32_t)0x01) << pinpos;
            /* Get the port pins position */
            currentpin = (GPIO_InitStruct->GPIO_Pin) & pos;
            if (currentpin == pos)
            {
                pos = pinpos << 2;
                /* Clear the corresponding low control register bits */
                pinmask = ((uint32_t)0x0F) << pos;
                tmpreg &= ~pinmask;
                /* Write the mode configuration in the corresponding bits */
                tmpreg |= (currentmode << pos);
                /* Reset the corresponding ODR bit */
                if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPD)
                {
                    GPIOx->BRR = (((uint32_t)0x01) << pinpos);
                }
                else
                {
                    /* Set the corresponding ODR bit */
                    if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPU)
                    {
                        GPIOx->BSRR = (((uint32_t)0x01) << pinpos);
                    }
                }
            }
        }
        GPIOx->CRL = tmpreg;
    }
    /*---------------------------- GPIO CRH Configuration ------------------------*/
    /* Configure the eight high port pins */
    if (GPIO_InitStruct->GPIO_Pin > 0x00FF)
    {
        tmpreg = GPIOx->CRH;
        for (pinpos = 0x00; pinpos < 0x08; pinpos++)
        {
            pos = (((uint32_t)0x01) << (pinpos + 0x08));
            /* Get the port pins position */
            currentpin = ((GPIO_InitStruct->GPIO_Pin) & pos);
            if (currentpin == pos)
            {
                pos = pinpos << 2;
                /* Clear the corresponding high control register bits */
                pinmask = ((uint32_t)0x0F) << pos;
                tmpreg &= ~pinmask;
                /* Write the mode configuration in the corresponding bits */
                tmpreg |= (currentmode << pos);
                /* Reset the corresponding ODR bit */
                if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPD)
                {
                    GPIOx->BRR = (((uint32_t)0x01) << (pinpos + 0x08));
                }
                /* Set the corresponding ODR bit */
                if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPU)
                {
                    GPIOx->BSRR = (((uint32_t)0x01) << (pinpos + 0x08));
                }
            }
        }
        GPIOx->CRH = tmpreg;
    }
}

void assert_failed(uint8_t* file, uint32_t line)
{
    printf("file: %s\tline: %d");
}

int main()
{
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;        //PA8
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //设置为推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;



    GPIO_Init(GPIOA, &GPIO_InitStructure);
    getchar();
    return 0;
}