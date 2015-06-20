const byte charEx1[] PROGMEM = {8,8,0x0,0x0,0x24,0x18,0x18,0x24,0x0,0x0,};
const byte charEx2[] PROGMEM = {8,8,0x91,0x42,0x18,0x25,0xA4,0x18,0x42,0x91,};


void updateMissile()
{
  for(byte i=0;i<NB_MISSIBLE;i++)
  {
    if(lesMissiles[i].timerAlive>0)
    { 
      if(lesMissiles[i].isGravity == 1){
        lesMissiles[i].vy += GRAVITE;
        if(lesMissiles[i].y>40 && lesMissiles[i].timerAlive>10){
          lesMissiles[i].timerAlive = 10;
        }
      }
      
      lesMissiles[i].x += lesMissiles[i].vx;
      lesMissiles[i].y += lesMissiles[i].vy;
      
      if(lesMissiles[i].y<-10 || ( abs(lesMissiles[i].x-(player.x+player.offsetCam))>100))
      {
        lesMissiles[i].timerAlive = 0;
      }
      else if(gb.collidePointRect(lesMissiles[i].x,lesMissiles[i].y,player.x+(player.offsetCam - 11),player.y,22,8))
      {
        if(player.hp>0)
        {
          player.hp -= lesMissiles[i].damage;
          player.timeRegenere = TIME_TO_REGENERE;
          if(player.angleSprite<0) player.angleSprite += 0.2;
          else player.angleSprite -= 0.2; 
          
          if(player.hp<0)
            player.hp = 0;
        }
        lesMissiles[i].timerAlive = 0;
      }
     lesMissiles[i].timerAlive--;
     
     if(lesMissiles[i].timerAlive<0){
      lesMissiles[i].timerAlive = 0;
     }
      
    }
  }
}

void drawMissile()
{
  for(byte i=0;i<NB_MISSIBLE;i++)
  {
    if(lesMissiles[i].timerAlive>0)
    {

      int dist  = lesMissiles[i].x - player.x;
      if(abs(dist)>88)
      {
        continue;
      }
      if(lesMissiles[i].isGravity == 1 && lesMissiles[i].timerAlive <10){
        if(lesMissiles[i].timerAlive >5){
          gb.display.drawBitmap((dist-4),(lesMissiles[i].y - 4), charEx1);
        }
        else {
          gb.display.drawBitmap((dist-4),(lesMissiles[i].y - 4), charEx2);
        }
      }
      else {
        gb.display.fillCircle(dist,lesMissiles[i].y,1);
      }
    }
  }
}
