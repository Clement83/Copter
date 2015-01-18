const byte Man1[] PROGMEM = {
  8,5,0x40,0xA0,0x40,0x40,0xA0,};
const byte Man2[] PROGMEM = {
  8,5,0x40,0x0,0xE0,0x40,0xA0,};


void drawRescaper()
{
  for(uint8_t i =0;i<NB_RESC;i++)
  {
    if(lesRescape[i].etat>2 &&  abs(lesRescape[i].x - player.x) <100)
    {
      if(gb.frameCount % 6 >2)
      {
        gb.display.drawBitmap(lesRescape[i].x- (player.x-42),lesRescape[i].y,Man1);
      }
      else
      {
        gb.display.drawBitmap(lesRescape[i].x- (player.x-42),lesRescape[i].y-1,Man2);
      }
    }
  }
}

void updateRescaper()
{
  for(uint8_t i =0;i<NB_RESC;i++)
  {
    if(lesRescape[i].etat>2 &&  abs(lesRescape[i].x - (player.x-42)) <100)
    {
      if(player.vx<0.2 &&  player.y >40)
      {
        lesRescape[i].tx = random(player.x-5,player.x+5);
        
        if(player.nbClient<NB_MAX_RESC_IN_COPTER)
        {
          if(abs(lesRescape[i].x-player.x)<5)
          {
            player.nbClient++;
            lesRescape[i].etat = 2;
          }
        }
      }

      if(lesRescape[i].tx == lesRescape[i].x)
      {
        lesRescape[i].tx = random(lesRescape[i].x-10,lesRescape[i].x+10);
        if(lesRescape[i].tx<100)lesRescape[i].tx = random(110,120);
      }
      if(lesRescape[i].tx>lesRescape[i].x)
        lesRescape[i].x++;
      else
        lesRescape[i].x--;
    }
  }
}



