
void updateMissile()
{
  for(byte i=0;i<NB_MISSIBLE;i++)
  {
    if(lesMissiles[i].isAlive)
    {
      lesMissiles[i].x += cos(lesMissiles[i].angle)*V_MISSILE;
      lesMissiles[i].y += sin(lesMissiles[i].angle)*V_MISSILE;
      
      if(lesMissiles[i].y<-10 || ( abs(lesMissiles[i].x-(player.x+player.offsetCam))>100))
      {
        lesMissiles[i].isAlive = false;
      }
      else if(gb.collidePointRect(lesMissiles[i].x,lesMissiles[i].y,player.x+(player.offsetCam - 11),player.y,22,8))
      {
        if(player.hp>0)
        {
          player.hp -= lesMissiles[i].damage;
          player.timeRegenere = TIME_TO_REGENERE;
          if(player.angleSprite<0) player.angleSprite += 0.2;
          else player.angleSprite -= 0.2; 
        }
        lesMissiles[i].isAlive = false;
      }
    }
  }
}

void drawMissile()
{
  for(byte i=0;i<NB_MISSIBLE;i++)
  {
    if(lesMissiles[i].isAlive)
    {

      int dist  = lesMissiles[i].x - player.x;
      if(abs(dist)>88)
      {
        continue;
      }
      gb.display.fillCircle(dist,lesMissiles[i].y,1);
    }
  }
}
