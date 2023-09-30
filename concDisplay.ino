void concDisplay()
{
  u8g2.clearBuffer();
  
  u8g2.setFont(u8g2_font_ncenB10_tr);
  methVal = analogRead(methSen);
  methConc = float((methVal/1023.0)*100);
  u8g2.setCursor(2, 20);
  u8g2.print("Methane : ");
  u8g2.setCursor(82, 20);
  u8g2.print(String(methConc));
  u8g2.print(" %");
  
  u8g2.setCursor(2, 38);
  u8g2.print("-------------------------");

  u8g2.setFont(u8g2_font_ncenB10_tr);
  ammoVal = analogRead(ammoSen);
  ammoConc = float((ammoVal/1023.0)*100);
  u8g2.setCursor(2, 55);
  u8g2.print("Ammonia:");
  u8g2.setCursor(82, 55);
  u8g2.print(String(ammoConc));
  u8g2.print(" %");

  u8g2.sendBuffer();
}
