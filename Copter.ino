#include <SPI.h>
#include <Gamebuino.h>
Gamebuino gb;


const byte Bunker1[] PROGMEM = {16,4,0x19,0x80,0x39,0xC0,0x79,0xE0,0xFF,0xF0,};
const byte Bunker2[] PROGMEM = {16,8,0x3,0xC0,0xF,0xF0,0x1F,0xF8,0x39,0xFC,0x61,0xFE,0x7F,0xEE,0xFF,0xEF,0xFF,0xEF,};
const byte Cabane1[] PROGMEM = {24,20,0x0,0xC0,0x0,0x1,0xE0,0x0,0x3,0x30,0x0,0x6,0x18,0x0,0xC,0xC,0x0,0x18,0x6,0x0,0x30,0x3,0x0,0x60,0x1,0x80,0xC0,0x0,0xC0,0xFF,0xFF,0xC0,0x80,0x0,0x40,0x80,0x0,0x40,0x80,0x3C,0x40,0x9F,0x24,0x40,0x91,0x24,0x40,0x91,0x3C,0x40,0x91,0x0,0x40,0x91,0x0,0x40,0x91,0x0,0x40,0x91,0x0,0x40,};
const byte Cloud1[] PROGMEM = {16,8,0xC,0x3C,0x12,0x62,0x21,0x81,0x42,0x1,0x84,0x2,0x80,0x4,0x43,0x88,0x3C,0x70,};
const byte HeliPort[] PROGMEM = {24,27,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xA0,0x0,0x5,0xA0,0x0,0x5,0x40,0x0,0x2,0x40,0x0,0x2,0xE0,0x0,0x7,0xA0,0x0,0x5,0xA0,0x0,0x5,0xA0,0x0,0x5,0xA0,0x0,0x5,0xA0,0x0,0x5,0xA0,0x0,0x5,0xA0,0x0,0x5,0xA0,0x0,0x5,0xA0,0x0,0x5,0xA0,0x0,0x5,0xA0,0x0,0x5,0xA0,0x0,0x5,0xA0,0x0,0x5,0xA0,0x0,0x5,0xA0,0x0,0x5,0xA0,0x0,0x5,0xA0,0x0,0x5,0xA0,0x0,0x5,};
const byte Man1[] PROGMEM = {8,5,0x40,0xA0,0x40,0x40,0xA0,};
const byte Man2[] PROGMEM = {8,5,0x40,0x0,0xE0,0x40,0xA0,};
const byte Sun[] PROGMEM = {16,16,0x80,0x1,0x4F,0xF2,0x30,0xC,0x27,0xE4,0x48,0x12,0x53,0xCA,0x54,0x2A,0x55,0xAA,0x55,0xAA,0x54,0x2A,0x53,0xCA,0x48,0x12,0x27,0xE4,0x30,0xC,0x4F,0xF2,0x80,0x1,};


typedef struct {
  int8_t hp;
  float vx,vy,x, y,angle,angleSprite,etat; //etat < 1 : vise a droite; etat >1   vise au centre ; etat > 2 vise a gauche
  bool dir, dirSprite,mitraille;
  
}
Copter;


typedef struct {
  uint8_t type;//permet de savoir sur quel sprite on est 0 : heliport,   1 -> 49 bat deco , >49 bat attaque
  int posX;
  uint8_t height;
  const byte * sprite;
  int8_t life;
}
Batiment;

#define NB_BAT_LVL 20
const Batiment lesBat[NB_BAT_LVL] = {
           {0,10,27,HeliPort,10},
           {1,80,20,Cabane1,10},
           {50,110,4,Bunker1,10},
           {51,150,8,Bunker2,10},
           {1,200,20,Cabane1,10},
           {1,300,20,Cabane1,10},
           {50,350,4,Bunker1,10},
           {51,410,8,Bunker2,10},
           {1,430,20,Cabane1,10},
           {1,500,20,Cabane1,10},
           {1,600,20,Cabane1,10},
           {50,620,4,Bunker1,10},
           {51,700,8,Bunker2,10},
           {1,750,20,Cabane1,10},
           {1,870,20,Cabane1,10},
           {1,900,20,Cabane1,10},
           {50,950,4,Bunker1,10},
           {51,1200,8,Bunker2,10},
           {1,1230,20,Cabane1,10},
           {1,1250,27,HeliPort,10},
         };

Copter player;

void setup()
{
  gb.begin();
  goTitleScreen();
  gb.battery.show = false;
}


void loop(){

 if(gb.update())
 {
    updatePlayer();
    drawPlayer();
    drawWorld();
 }
 // gameOverScreen();
}

void initGame()
{
  
}

const byte title[] PROGMEM = {64,36,0x0,0xB,0x29,0xD1,0xDD,0xD9,0xD0,0xF,0xFF,0xFB,0x91,0x11,0x1D,0x14,0x9F,0xFF,0x0,0xB,0x11,0xDD,0xD5,0xD4,0x90,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xFF,0xFF,0xF8,0x0,0x0,0x0,0x0,0xE,0x0,0x20,0x0,0x0,0x0,0x0,0x0,0x11,0x3,0xFC,0x0,0x0,0x0,0x0,0x0,0x15,0xF,0x1F,0x0,0x0,0x0,0x0,0x0,0x1F,0xFF,0x89,0x80,0x0,0x0,0x0,0x0,0x15,0x1F,0xFC,0xC0,0x0,0x0,0x0,0x0,0x11,0x1,0xFF,0xE0,0x0,0x0,0x0,0x0,0xE,0x0,0xFF,0xF0,0x0,0x0,0x0,0x0,0x0,0x0,0x30,0x84,0x0,0x0,0x0,0x0,0x0,0x1,0xFF,0xF8,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x60,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x30,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xC,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x6,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3,0x0,0x60,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x30,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xE0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x38,0x0,0x0,0x1,0x82,0x0,0x20,0x0,0x1E,0x0,0x0,0x2,0x5,0x26,0x72,0x50,0x7,0xC0,0x0,0x1,0x34,0x55,0x25,0x60,0xF,0xF0,0x0,0x0,0x85,0x56,0x26,0x40,0x1F,0xF8,0x0,0x3,0x2,0x24,0x13,0x40,0x39,0xFC,0x0,0x0,0x0,0x4,0x0,0x0,0x61,0xFE,0x0,0x0,0x0,0x0,0x0,0x0,0x7F,0xEE,0x0,0x0,0x0,0x0,0x0,0x0,0xFF,0xEF,0x0,0x0,0x0,0x0,0x0,0x0,0xFF,0xEF,};
void goTitleScreen()
{
  gb.titleScreen(title);
  initGame();
}



void drawWorld()
{
  gb.display.drawLine(0,47,88,47);
  //gb.display.drawBitmap(5,0,Sun);
  for(int i= 0; i<88;i++)
   {
     if(((i) %2) == (((int)player.x)%2))
     {
       gb.display.drawPixel(i,46);
     }
   }
   
   for(byte i=0;i<NB_BAT_LVL;i++)
   {
     int dist  = lesBat[i].posX - player.x;
     if(dist>88 ||  dist < -80)
     {
       continue;
     }
     else 
     {
       gb.display.drawBitmap(dist,(48-lesBat[i].height),lesBat[i].sprite);
     }
   }
}
