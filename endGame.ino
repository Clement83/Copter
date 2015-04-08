
void winScreen()
{
  uint8_t nbKill = 0;
  uint8_t nbTot = 0;
  for(byte i=0; i< NB_BAT_LVL ;i++)
   {
     if(lesBat[i].type>49)
     {
       nbTot++;
       if(lesBat[i].life<=0)
       {
         nbKill++;
       }
     }
   }
  
  gb.display.print(F("Save : "));
  gb.display.println(cptVictoire);
  gb.display.print(F("Death : "));
  gb.display.println(cptDeath);
  gb.display.print(F("Ennemie kill : "));
  gb.display.print(nbKill);
  gb.display.print(F("/"));
  gb.display.println(nbTot);
  gb.display.print(F("press c button")); 
 
}

void gameOverScreen()
{
   winScreen();
}
