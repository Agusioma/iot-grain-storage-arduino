#include <LiquidCrystal.h> // includes the LiquidCrystal Library
#include <dht.h>
#define dataPin 8

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
dht DHT;
bool showcelciusorfarenheit = false;

void setup() 
{
  lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
}

void loop() 
{
  int readData = DHT.read22(dataPin);
  float t = DHT.temperature;
  float h = DHT.humidity;
  lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
  lcd.print("Temp.: "); // Prints string "Temp." on the LCD
  //Print temperature value in Celcius and Fahrenheit every alternate cycle
  if(showcelciusorfarenheit)
  {
    lcd.print(t); // Prints the temperature value from the sensor
    lcd.print(" ");
    lcd.print((char)223);//shows degrees character
    lcd.print("C");
    showcelciusorfarenheit = false;
  }
  else
  {
    lcd.print((t * 9.0) / 5.0 + 32.0); // print the temperature in Fahrenheit
    lcd.print(" ");
    lcd.print((char)223);//shows degrees character
    lcd.print("F");
    showcelciusorfarenheit = true;
  }
  
  lcd.setCursor(0,1);
  lcd.print("Humi.: ");
  lcd.print(h);
  lcd.print(" %");
  delay(5000);
}
