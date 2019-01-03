#include <VirtualWire.h>
#define fw 2 
#define r 3 
#define bw 4 
#define l 5 
void setup(void)
{
  vw_set_ptt_inverted(true); // Необходимо для DR3100
  vw_setup(2000); // Устанавливаем скорость передачи (бит/с)
  pinMode(fw,INPUT_PULLUP);
  pinMode(bw,INPUT_PULLUP);
  pinMode(r,INPUT_PULLUP);
  pinMode(l,INPUT_PULLUP);
  Serial.begin(115200);
}

void loop(void)
{
 int buttonfw=digitalRead(fw);
  int buttonbw=digitalRead(bw);
  int buttonr=digitalRead(r);
  int buttonl=digitalRead(l);
  //int number = 123;
 // char symbol = 'c';

  String strMsg = "z ";
  if (buttonfw==false)
  {
    if(buttonr==false)
    {
    strMsg += 2;//"fwr"
    }
     if (buttonl==false)
    {
    strMsg += 3;//"fwl"
    }
    else 
    strMsg += 1;//"fw"
  }
   if (buttonbw==false) //bw
  {
    if(buttonr==false)
    {
    strMsg += 5;//"bwr"
    }
   if (buttonl==false)
    {
    strMsg += 6;//"bwl"
    }
    else 
    strMsg += 4;//"bw"
  }
  else strMsg +=0;
//   if (buttonr)
//  {
//    strMsg += 7;//"r"
//  }
//   if (buttonl)
//  {
//    strMsg += 8;//"l"
//  }
  //else  strMsg += 0;
  
  //strMsg += symbol;
  //strMsg += " ";
  //strMsg += number;
  //strMsg += " ";

  char msg[255];

  strMsg.toCharArray(msg, 255);
//strMsg = " ";
  Serial.println(msg);
//strMsg = "";
  vw_send((uint8_t *)msg, strlen(msg));
  vw_wait_tx(); // Ждем пока передача будет окончена
  delay(200);
}
