//include header files 
#include <ch32v00x.h>
#include <debug.h>

// define xor 
int xor(int bit1,int bit2)
{ int xor= bit1^bit2;
return xor
  }

//pin configuration 

void GPIO_Config(void)
{ GPIO_InitTypeDef GPIO_InitStructure = {0}; //structure variable used for the GPIO configuration
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE); // to Enable the clock for Port D
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 ; // Defines which Pin to configure
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // Defines Input Type
GPIO_Init(GPIOD, &GPIO_InitStructure);
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_2 | GPIO_Pin_3 ; // Defines which Pin to configure
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; // Defines Output Type
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // Defines speed
GPIO_Init(GPIOD, &GPIO_InitStructure);
}

// main function 
  int main(void)
{
uint8_t b0, b1, b2, g0 , g1, g2 = 0;
NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
SystemCoreClockUpdate();
Delay_Init();
GPIO_Config();
while(1)
{
  g0=GPIO_ReadInputDataBit(GPIOD,GIPO_Pin_4);
  g1=GPIO_ReadInputDataBit(GPIOD,GIPO_Pin_5);
  g2=GPIO_ReadInputDataBit(GPIOD,GIPO_Pin_6);

  b2=xor(0,g2);
  b1=xor(g1,b2);
  b0=xor(g0,b1);
  
 if(b0==0)
 {GPIO_WriteBit(GPIOD, GPIO_Pin_0, RESET);}
 else
 {{GPIO_WriteBit(GPIOD, GPIO_Pin_0, SET);}
if(b1==0)
  {GPIO_WriteBit(GPIOD, GPIO_Pin_2, RESET);}
  else
  {GPIO_WriteBit(GPIOD, GPIO_Pin_2, SET);}
  if(b2==0)
    {GPIO_WriteBit(GPIOD, GPIO_Pin_3, RESET);}
  else
    {GPIO_WriteBit(GPIOD, GPIO_Pin_3, SET);}
}
}

