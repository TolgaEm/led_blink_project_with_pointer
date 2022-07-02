
// HSE CLOCK ENABLE = 0X4002 3800 , OFFSET = 0X00, HSE ON AND CSS ON= 0X80001U
// PLL CONFIGURATON = 0X4002 3800 , OFFSET 0X04. PLLP=2,PLLN=168,PLLM=4 --> 0X0A81
// APB2,APB1,AHB CONFIGURATION = 0X4002 3800 , OFFSET = 0X08, APB2=4,APB1=4,AHB=1 ----> 0XB400
// CLEAR CSS AND HSE FLAG = 0X4002 3800 , OFFSET = 0X0C ,  = 0X880000
/*------------------------------------------------------------------*/
// AHB1 CLOCK ADRESS = 0X4002 3800, OFSETT = 0X30 , D PORT=0X08U
// D PORT ADRESS = 0X4002 0C00, MODER OFFSET = 0X00, PD12,PD13,PD14,PD15 = OUTPUT(0X55000000U)
// D PORT ADRESS = 0X4002 0C00, OTYPER OFFSET = 0X04, PUSH-PULL = 0X00U
// D PORT ADRESS = 0X4002 0C00, OSPEED OFFSET = 0X08, LOW SPEED = 0X00U
// D PORT ADRESS = 0X4002 0C00, PUPDR OFFSET = 0X0C, NO PULL UP/DOWN = 0X00U
// D PORT ADRESS = 0X4002 0C00, ODR OFFSET = 0X14, SET = 0XF000

int main() {
	
	unsigned int *pointer;
	
	pointer = (unsigned int *)  0x40023800;
	*pointer = 0X80001U; // HSE AND CSS CLOCK ENABLE
	
	pointer = (unsigned int *)  0x40023804;
	*pointer = 0X0A81U; // CONFIGURATION PLLP,PLLN,PLLM

	pointer = (unsigned int *)  0x40023808;
	*pointer = 0XB400; // CONFIGURE APB2,APB1,AHB CLOCK 
	
	pointer = (unsigned int *) 0x4002380C;
	*pointer = 0X880000; // CLEAR CSS AND HSE FLAG
	
	pointer = (unsigned int *) 0x40023830;
	*pointer = 0X08U; // D PORT CLOCK ENABLE 
	
	pointer = (unsigned int *) 0x40020C00;
	*pointer = 0X55000000U; // d15,d14,d13,d12 set output
	
	pointer = (unsigned int *) 0x40020C04;
	*pointer = 0X00U; // SET PUSH-PULL
	
	pointer = (unsigned int *) 0x40020C08;
	*pointer =  0X00U; // SET LOW SPEED
	
	pointer = (unsigned int *) 0x40020C0C;
	*pointer = 0x00U; // set no pull up-pull down
	
	pointer = (unsigned int *) 0x40020C14;
	*pointer = 0xF000U; //SET OUTPUT 
}
