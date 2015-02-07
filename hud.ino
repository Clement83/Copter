

const byte Go[] PROGMEM = {24,17,0x0,0x1,0x0,0x0,0x1,0x80,0x0,0x1,0xC0,0x0,0x1,0xE0,0x0,0x1,0xF0,0xFF,0xFF,0xF8,0xFF,0xFF,0xFC,0xFF,0xFF,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFF,0xFF,0xFC,0xFF,0xFF,0xF8,0x0,0x1,0xF0,0x0,0x1,0xE0,0x0,0x1,0xC0,0x0,0x1,0x80,0x0,0x1,0x0,};


void drawHud()
{
   if(player.x<800)
   {
     if(gb.frameCount%20<15)
     {
       gb.display.drawBitmap(10,20,Go);
     }
   }
   gb.display.setFont(font3x3);
   gb.display.print("\37");
   gb.display.print(player.nbClient);
   gb.display.print(" \2");
   gb.display.print(cptVictoire);
   gb.display.print(" \41");
   gb.display.print(cptDeath);
   gb.display.setFont(font3x5);
   
   gb.display.drawRect(36,0,12,3);
   gb.display.drawFastHLine(37,1,getLifeHud());
   
   gb.display.drawRect(50,0,12,3);
   gb.display.drawFastHLine(51,1,getLifeMittraille());
}

uint8_t getLifeHud()
{
  float add = (player.hp * 10) / MAX_LIFE; 
  return add;
}
uint8_t getLifeMittraille()
{
  float add = (player.timeMitraille * 10) / TIME_TO_ENRAYE; 
  return add;
}
