#include <LiquidCrystal.h>
LiquidCrystal lcd (5,6,7,8,9,10);

#include <DS3231.h>
DS3231  rtc(SDA, SCL);
Time t;
void setup() {
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(0,OUTPUT);
   pinMode(1,OUTPUT);
    pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
   pinMode(4,OUTPUT);
  digitalWrite(0,0);
  digitalWrite(1,0);
  digitalWrite(2,1);
  digitalWrite(3,1);
  digitalWrite(4,0);
  lcd.begin(16,2);
  rtc.begin();

  //rtc.setDOW(MONDAY);     // Set Day-of-Week to SUNDAY
  //rtc.setTime(10, 41, 10);     // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(17, 5, 2021);
}
void loop() {

  t = rtc.getTime();
 
  int a=t.hour;


  if(a>12)
  {
    a=a-12;
   
    if(a<10)
    {
      lcd.setCursor(2,0);
      lcd.print("0");
      lcd.print(a);
      lcd.print(":");
    }
      else{
           lcd.setCursor(2,0);
           lcd.print(a);
           lcd.print(":");
          }
    
   

  int b=t.min;
   if(b<10)
      {
      lcd.setCursor(5,0);
      lcd.print("0");
      lcd.print(b);
      lcd.print(":");
      }
      else{
          lcd.setCursor(5,0);
          lcd.print(b);
          lcd.print(":");
          }
  int c=t.sec;
     if(c<10)
       {
        lcd.setCursor(8,0);
        lcd.print("0");
        lcd.print(c);
   }
      else{
          lcd.setCursor(8,0);
          lcd.print(c);
          lcd.print(" PM        ");
          }
}
      else{
        if(a<10){
        if(a==0)
        {
          a=12;
          lcd.setCursor(2,0);
          lcd.print(a);
          lcd.print(":");
        }
              else{
              lcd.setCursor(2,0);
              lcd.print("0");
              lcd.print(a);
              lcd.print(":");
              }
      }
      else{
            lcd.setCursor(2,0);
            lcd.print(a);
            lcd.print(":");
          }
    
   

      int b=t.min;
        if(b<10)
            {
             lcd.setCursor(5,0);
             lcd.print("0");
             lcd.print(b);
             lcd.print(":");
      
            }
        else{
            lcd.setCursor(5,0);
            lcd.print(b);
            lcd.print(":");
           }
         int c=t.sec;
         if(c<10)
            {
            lcd.setCursor(8,0);
            lcd.print("0");
            lcd.print(c);
            lcd.print(":");
             }
            else{
                lcd.setCursor(8,0);
                lcd.print(c);   
                lcd.print(" AM        ");
                }
      }


  // Send time
 
  
  // Wait one second before repeating :)
  delay (1000);
  







 lcd.setCursor(0,1);
 lcd.print("Temp: ");
 lcd.print(rtc.getTemp());
 lcd.println(" C     ");
  

}
