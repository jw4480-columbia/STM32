/**
  ******************************************************************************
  * File Name          : USART.c
  * Description        : This file provides code for the configuration
  *                      of the USART instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "usart.h"

/* USER CODE BEGIN 0 */
#include "stdio.h"
#include "string.h"	//�����ַ���������,strcat()����ƴ�������ַ������Լ�strlen()����ͳ���ַ����ĳ���


//�ض��� fputc ����������HAL�⺯������
int fputc(int ch,FILE *f)
{
	uint8_t temp = ch;
	HAL_UART_Transmit(&huart1,&temp,1,1000);
	while(__HAL_UART_GET_FLAG(&huart1,UART_FLAG_TXE)!=SET);
	return ch;
}
/* USER CODE END 0 */
//����2�����ڷ��͵��ָ��
//���һ��дһ�����ͺ���������HAL�⺯������
void UART2_Send(uint8_t *Data, uint16_t Size)
{
	uint16_t i = 0;
	for(i = 0;i<Size; i++){
		HAL_UART_Transmit(&huart2, &Data[i], 1, 1000);
		while(__HAL_UART_GET_FLAG(&huart2,UART_FLAG_TXE)!=SET);
	}
}




UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;

/* USART1 init function */

void MX_USART1_UART_Init(void)
{

  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }

}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspInit 0 */

  /* USER CODE END USART1_MspInit 0 */
    /* USART1 clock enable */
    __HAL_RCC_USART1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USER CODE BEGIN USART1_MspInit 1 */

  /* USER CODE END USART1_MspInit 1 */
  }
	else if(uartHandle->Instance==USART2)
  {
  /* USER CODE BEGIN USART2_MspInit 0 */

  /* USER CODE END USART2_MspInit 0 */
    /* USART2 clock enable */
    __HAL_RCC_USART2_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART2 GPIO Configuration
    PA2     ------> USART2_TX
    PA3     ------> USART2_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USER CODE BEGIN USART2_MspInit 1 */

  /* USER CODE END USART2_MspInit 1 */
  }
}


\



/* USART2 init function */

void MX_USART2_UART_Init(void)
{

  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }

}


void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
	if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspDeInit 0 */

  /* USER CODE END USART1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART1_CLK_DISABLE();
		
		__HAL_RCC_GPIOA_CLK_ENABLE();

    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_9|GPIO_PIN_10);

  /* USER CODE BEGIN USART1_MspDeInit 1 */
    GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  /* USER CODE END USART1_MspDeInit 1 */
  }
	else if(uartHandle->Instance==USART2)
  {
  /* USER CODE BEGIN USART2_MspInit 0 */

  /* USER CODE END USART2_MspInit 0 */
    /* USART2 clock enable */
    __HAL_RCC_USART2_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART2 GPIO Configuration
    PA2     ------> USART2_TX
    PA3     ------> USART2_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USER CODE BEGIN USART2_MspInit 1 */

  /* USER CODE END USART2_MspInit 1 */
  }
	
}



/* USER CODE BEGIN 1 */
//����������ٶȿ��ƣ������ٶȺ�PWM�����Ӧ��ϵ�������е��Ի�궨��
//			input�����ID��(1-999)�������������İ��������֣������ڲ����Զ���'0'���ַ���
//			input��PWM����500-2500�������������İ��������֣������ڲ����Զ���'0'���ַ���
//			input��ת��ʱ�䣬1-9999�������������İ��������֣������ڲ����Զ���'0'���ַ���
//			output: NULL

 void Motor_Rotate(int id, int pwm, int time)
{
		char ID_str[10] = {};
		char PWM_str[10] = {};
		char TIME_str[10] = {};
			
		char data[50] = {"#"};		//data���飬���ڷ��Ϳ���ָ��,����Э�飬��ͷ��"#"
		
		//����������ID��ת��Ϊ�ַ���
		myitoa(id, ID_str, 10);	
		
		//��ID�ŵ��ַ�����ǰ�����㣬����б�Ҫ�Ļ�
		if( (3 - strlen(ID_str)) == 2) {
			strcat(data,"00");
		}
		else if( (3 - strlen(ID_str)) == 1) {
			strcat(data,"0");
		}
		//�ַ���ƴ��
		strcat(data, ID_str);
		//����������PWM����ֵת��Ϊ�ַ���
		myitoa(pwm,PWM_str,10);
		
		//��PWM������ַ�����ǰ�����㣬����б�Ҫ�Ļ�
		if( (4 - strlen(PWM_str)) == 1) {
			strcat(data,"P0");
		}
		else if( (4 - strlen(PWM_str)) == 0) {
			strcat(data,"P");
		}
		//�ַ���ƴ��
		strcat(data, PWM_str);
		//����������ת��ʱ��ת��Ϊ�ַ���
		myitoa(time, TIME_str, 10);

		//��ת��ʱ����ַ�����ǰ�����㣬����б�Ҫ�Ļ�
		if( (4 - strlen(TIME_str)) == 2) {
			strcat(data,"T00");
		}
		else if( (4 - strlen(TIME_str)) == 1) {
			strcat(data,"T0");
		}
		else if( (4 - strlen(TIME_str)) == 0) {
			strcat(data,"T");
		}
		
		//�ַ���ƴ��
		strcat(data, TIME_str);
		strcat(data,"!\r\n");		//ĩ�����"\r\n"��ʹ��ָ�������PC��ʱ��ÿһ��ָ���ռ1�У�����Ϊ�˷���۲�͵��ԡ�
		
		
		//����2���͵������ָ��
		UART2_Send((uint8_t *)data, sizeof(data));
		//��ͬ���Ŀ���ָ��ͨ������1�������PC�ˣ��Ա����
		printf("%s", data); 
	
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);

}	 



//�������ܣ�������ת�ַ���
//stm32��֧�ֱ�׼��itoa,�����Լ�ʵ��
//�����ָ�����Ϥ�������Լ��ж�����һ�δ��롣

//direction control

typedef uint8_t u8;

// left 
u8 mess2_ne[] = "#002P0960T0000!";
u8 mess3_ne[] = "#003P1130T0000!";
u8 mess1_po[] = "#001P1180T0000!"; 
u8 mess4_po[] = "#004P1820T0000!";

// right
u8 mess1_ne_r[] = "#001P1790T0000!"; 
u8 mess4_ne_r[] = "#004P1050T0000!";
u8 mess2_po_r[] = "#002P1740T0000!";
u8 mess3_po_r[] = "#003P1740T0000!";

// straight
u8 mess1_po_s[] = "#001P1170T0000!"; 
u8 mess4_po_s[] = "#004P1780T0000!";
u8 mess2_po_s[] = "#002P1780T0000!";
u8 mess3_po_s[] = "#003P1780T0000!";

//stop
u8 mess1_0[] = "#001P1500T0000!";
u8 mess2_0[] = "#002P1500T0000!";
u8 mess3_0[] = "#003P1500T0000!";
u8 mess4_0[] = "#004P1500T0000!";


void forward(void) //quan bu zheng zhuan
{
	  HAL_UART_Transmit(&huart2,mess1_po_s,sizeof(mess1_po_s),400);
		HAL_UART_Transmit(&huart2,mess2_po_s,sizeof(mess2_po_s),400);
		HAL_UART_Transmit(&huart2,mess3_po_s,sizeof(mess3_po_s),400);
		HAL_UART_Transmit(&huart2,mess4_po_s,sizeof(mess4_po_s),400);

}


void stop(void)
{
	HAL_UART_Transmit(&huart2,mess1_0,sizeof(mess1_0),400);
	HAL_UART_Transmit(&huart2,mess2_0,sizeof(mess2_0),400);
	HAL_UART_Transmit(&huart2,mess3_0,sizeof(mess3_0),400);
	HAL_UART_Transmit(&huart2,mess4_0,sizeof(mess4_0),400);
}






void left_rotate(void)
{
	HAL_UART_Transmit(&huart2,mess1_po,sizeof(mess1_po),400);
	HAL_UART_Transmit(&huart2,mess2_ne,sizeof(mess2_ne),400);
	HAL_UART_Transmit(&huart2,mess3_ne,sizeof(mess3_ne),400);
	HAL_UART_Transmit(&huart2,mess4_po,sizeof(mess4_po),400);
}


void right_rotate(void)
{
	HAL_UART_Transmit(&huart2,mess1_ne_r,sizeof(mess1_ne_r),400);
	HAL_UART_Transmit(&huart2,mess2_po_r,sizeof(mess2_po_r),400);
	HAL_UART_Transmit(&huart2,mess3_po_r,sizeof(mess3_po_r),400);
	HAL_UART_Transmit(&huart2,mess4_ne_r,sizeof(mess4_ne_r),400);
}


char *myitoa(int value, char *string, int radix)
{
    int     i, d;
    int     flag = 0;
    char    *ptr = string;

    /* This implementation only works for decimal numbers. */
    if (radix != 10)
    {
        *ptr = 0;
        return string;
    }

    if (!value)
    {
        *ptr++ = 0x30;
        *ptr = 0;
        return string;
    }

    /* if this is a negative value insert the minus sign. */
    if (value < 0)
    {
        *ptr++ = '-';

        /* Make the value positive. */
        value *= -1;
    }

    for (i = 10000; i > 0; i /= 10)
    {
        d = value / i;

        if (d || flag)
        {
            *ptr++ = (char)(d + 0x30);
            value -= (d * i);
            flag = 1;
        }
    }

    /* Null terminate the string. */
    *ptr = 0;

    return string;

} /* NCL_Itoa */


/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
