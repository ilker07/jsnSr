#include <18F67K22.h>
#use delay (clock=8000000)

#pragma use rs232(baud=9600, xmit=PIN_G1, rcv=PIN_G2, stream=diger, errors)  //Nextion Ekran Haberlesmesi icin.



#define trigger pin_c4
#define echo    pin_c3
#define BZ      pin_g4

unsigned long int c=0;             
unsigned int16 a=0;    


void main()
{

  
  
   setup_timer_1(T1_INTERNAL | T1_DIV_BY_1);    //Bolucu 1.
  
   set_tris_b(0x02);
   set_tris_g(0x00);
  
   output_high(trigger); 
   delay_ms(100);
  
   
   
   while(TRUE)                
   {
      output_high(trigger); 
      delay_us(20);        
      output_low(trigger);  
      
      
      
      while(!(input(echo)));
      
      
      
      set_timer1(0);  
     
      while((input(echo)));
      output_low(BZ);
      
      c=get_timer1();       
      
     
      a=c/116; //58
    
     
      fprintf(diger,"page4.mesafe.val=%lu%c%c%c",a,0xFF,0xFF,0xFF);  
     
      delay_ms(1000);
   }
}
