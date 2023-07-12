#include <math.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
lcd.begin(16,2);

}

double tempreture(int read){

  double gradCel;
  gradCel = log(((10240000 / read) - 10000));
  gradCel = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * gradCel * gradCel )) * gradCel);
  gradCel = gradCel - 273.15;
  return gradCel;
}

void loop() {
  int value = analogRead(A0);
  double gradCel = tempreture(value);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Es ist ");
  lcd.setCursor(7,0);
  lcd.print(gradCel);
  lcd.setCursor(0,1);
  lcd.print("Grad Celsius ");
  delay(500);  


}
