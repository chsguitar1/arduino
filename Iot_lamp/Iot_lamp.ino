
#include <EtherCard.h>
//Programa : Modulo ethernet ENC28J60 com LM35 e potenciometro
//Autor : FILIPEFLOP

 
static byte myip[] = {10,1,1,51};
static byte gwip[] = { 10,1,1,1 };
static byte mymac[] = {0x74,0x69,0x69,0x2D,0x30,0x31};
byte Ethernet::buffer[1300];
void setup()
{ 
  Serial.begin(9600);
 if (ether.begin(sizeof Ethernet::buffer, mymac,10) == 0);
 ether.staticSetup(myip, gwip);
}
 
void loop()
{
  //Calcula o valor da temperatura
 // tempc = ( 5.0 * analogRead(pin) * 100.0) / 1024.0;
 
  //Armazena a temperatura máxima na variavel maxtemp
  //if(tempc > maxtemp) {maxtemp = tempc;} 
  //Armazena a temperatura máxima na variavel mintemp
  //if(tempc < mintemp) {mintemp = tempc;} 
 
  
    ether.printIp("<H1>FILIPEFLOP - Teste ENC28J60</H1><br/>");
    ether.printIp("<b>Valor potenciometro porta analogica 5 : ");
  //  e.print(analogRead(A5));
    ether.printIp("<br/><br/>");
    ether.printIp("Valor temperatura : ");
   // e.print(tempc);
    ether.printIp("&deg<br/><br/>");
    ether.printIp("Temperatura minima : ");
    //e.print(mintemp);
    ether.printIp("&deg<br/>");
    ether.printIp("Temperatura maxima : ");
    //e.print(maxtemp);
    ether.printIp("&deg<b/>");
    //e.respond();
  
  //delay(100);
}
