

void updateBatiment()
{
  for(byte i=0;i<NB_BAT_LVL;i++)
  {
    if(lesBat[i].type==0)//sur un heliport
    {
      if(player.vx<0.2 &&  player.y >40 && abs((player.x+player.offsetCam) - (lesBat[i].posX+12))<20 && player.nbClient>0 && gb.frameCount%20==0)
      {
        for(byte j=0;j<NB_RESC;j++)
        {
          if(lesRescape[j].etat == 2)
          {
            lesRescape[j].etat=1;
            player.nbClient--;
            cptVictoire++;
            break;
          }
        }
      }
    }
    else if(lesBat[i].type>49 && lesBat[i].life>0 && abs(player.x -lesBat[i].posX)<88)//Batiment d'attaque
    {
      
      if(lesBat[i].posY>48 && (gb.frameCount%5) == 0)
      {
        lesBat[i].posY--;
      }
      /*if(abs(player.x - lesBat[i].posX)>20)
      {
        if(player.x > lesBat[i].posX)
        {
          lesBat[i].posX++;
        }
        else 
        {
          lesBat[i].posX--;
        }
      }*/
      
      if(player.mitraille)
      {
          uint8_t posXBat = lesBat[i].posX - player.x;
         if(player.impact>posXBat && player.impact<(posXBat+15))
         {
           lesBat[i].life--;
         }
         if(lesBat[i].life<=0)
         {
           exEnn.etat = 0;
           exEnn.posX = lesBat[i].posX;
         }
      }
      
      if(lesBat[i].posY<52 && (gb.frameCount%lesBat[i].cadance) == 0)
      {
        for(byte x=0;x<NB_MISSIBLE;x++)
        {
          if(!lesMissiles[x].isAlive)
          {
            lesMissiles[x].angle = ((float)random(30, 60)/10);
            lesMissiles[x].x = lesBat[i].posX+10 ;
            lesMissiles[x].y = (48-lesBat[i].height);
            lesMissiles[x].isAlive = true;
            lesMissiles[x].damage = lesBat[i].damage;
            break;
          }
        }
      }
    }
  }
}

void drawEnnemies()
{
   for(byte i=0;i<NB_BAT_LVL;i++)
   {
     int dist  = lesBat[i].posX - player.x;
     if(dist>88 ||  dist < -80)
     {
       continue;
     }
     else 
     {
       gb.display.drawBitmap(dist,(lesBat[i].posY-lesBat[i].height),lesBat[i].life>0 ? lesBat[i].sprite : lesBat[i].spriteDamage);
     }
   }
}

void updateExplosion()
{
  if(exEnn.etat < NB_EXPLOSION_ENNEMI)
  {
    if((gb.frameCount%exEnn.frequence) == 0)
    {
      exEnn.etat++;
    }
  }
}
void drawExplosion()
{
  if(exEnn.etat < NB_EXPLOSION_ENNEMI)
  {
     int dist  = exEnn.posX- player.x;
    if(exEnn.etat  == 0) gb.display.drawBitmap(dist ,24,exEnn.Ex1);
    if(exEnn.etat  == 1) gb.display.drawBitmap(dist ,24,exEnn.Ex2);
    if(exEnn.etat  == 2) gb.display.drawBitmap(dist ,24,exEnn.Ex3);
  }
}
