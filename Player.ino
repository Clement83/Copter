const byte HelicoFace[] PROGMEM = {
  24,11,0xFF,0xFF,0x80,0x0,0x80,0x0,0x3,0xE0,0x0,0xE,0x38,0x0,0x8,0x8,0x0,0xC,0x98,0x0,0xE,0xB8,0x0,0x7,0xF0,0x0,0x3,0xE0,0x0,0x4,0x10,0x0,0xC,0x18,0x0,};
const byte HelicoDroite[] PROGMEM = {32,10,0x7,0xFF,0xFF,0xC0,0x20,0x1,0x0,0x0,0x70,0x1F,0xE0,0x0,0xD8,0x78,0xF8,0x0,0xAF,0xFC,0x4C,0x0,0xD8,0xFF,0xE6,0x0,0x70,0xF,0xFF,0x0,0x20,0x7,0xFF,0x80,0x0,0x1,0x84,0x20,0x0,0xF,0xFF,0xC0,};
const byte HelicoGauche[] PROGMEM = {32,10,0x7F,0xFF,0xFC,0x0,0x0,0x10,0x0,0x80,0x0,0xFF,0x1,0xC0,0x3,0xE3,0xC3,0x60,0x6,0x47,0xFE,0xA0,0xC,0xFF,0xE3,0x60,0x1F,0xFE,0x1,0xC0,0x3F,0xFC,0x0,0x80,0x84,0x30,0x0,0x0,0x7F,0xFE,0x0,0x0,};

const byte HelicoCrache[] PROGMEM = {
  16,24,0x3F,0xFC,0x30,0xE,0xE0,0x6,0xC0,0x3,0x80,0x1,0x80,0x1,0x9E,0x79,0x72,0x4E,0x6,0x60,0xA,0x50,0x12,0x48,0x12,0x48,0xA,0x50,0x7,0xE0,0x2,0x40,0x2,0x40,0x2,0x40,0x2,0x40,0x2,0x40,0x1A,0x58,0x26,0x64,0x42,0x42,0x46,0x62,0x84,0x21,};
const byte HelicoExplode[] PROGMEM = {
  24,11,0x88,0x48,0x80,0x44,0x91,0x0,0x23,0xE2,0x0,0x1F,0x3C,0x0,0x88,0x8C,0x0,0x4C,0xDA,0x0,0x2E,0xB9,0x0,0x13,0xF0,0x80,0x23,0xE8,0x0,0x44,0x84,0x0,0x88,0x42,0x0,};

const byte Balles[] PROGMEM = {
  8,4,0x40,0xA0,0xA0,0xE0,};


#define ANGLE_ROT 0.05
#define MAX_VELOCITY 4

void updatePlayer()
{
  if(player.hp>0)
  {
    if(gb.buttons.repeat(BTN_RIGHT, 1))
    {
      player.angleSprite = min(player.angleSprite+ANGLE_ROT, 0.6);
      player.vx = min(player.vx + 0.18, MAX_VELOCITY);
      player.vy = max(player.vy - 0.05, -MAX_VELOCITY);
      ;
    }
    if(gb.buttons.repeat(BTN_LEFT, 1))
    {
      player.angleSprite = max( player.angleSprite - ANGLE_ROT, -0.60);
      player.vx = max(player.vx - 0.18, -MAX_VELOCITY);
      player.vy = max(player.vy - 0.05, -MAX_VELOCITY);
    }
    if(gb.buttons.repeat(BTN_UP, 1))
    {
      player.vy = max(player.vy - 0.15, -MAX_VELOCITY);
    }
    if(gb.buttons.repeat(BTN_DOWN, 1))
    {
      player.vy = min(player.vy + 0.2, MAX_VELOCITY);
    }
    if(gb.buttons.repeat(BTN_A, 1))
    {
      player.mitraille = true;
    }
    else
    {
      player.mitraille = false;
    }

    if(gb.buttons.repeat(BTN_B, 1))
    {
      player.hp = 0;
    }

    if(player.vx > 0.5 && player.etat<3)
    {
      player.etat += 0.05;
    }
    else if(player.vx < -0.5 && player.etat>0)
    {
      player.etat -= 0.05;
    }

    //frottement inertie
    player.angleSprite *= 0.9;
    player.vx *= 0.95;
    player.vy = min(player.vy + 0.05, MAX_VELOCITY);

    player.x = player.x + player.vx;
    player.y = player.y + player.vy;

    if(player.y >42)
    {
      if(abs(player.vy) > 0.5)
      {
        player.y = player.y - player.vy;
        // si on vas trop vite on se crache
        player.vy = -0.2 * player.vy;//on inverse et on ralentie
      }
      else
      {
        //sinon on se pose
        player.y = 42;
        player.vy = 0;
      }
    }
    if(player.y <10)
    {
      player.y = 10;
      player.vy = 0;
    }
  }
  else
  {
    if(player.nbClient>0)
    {
      for(byte j=0;j<NB_RESC;j++)
      {
        if(lesRescape[j].etat == 2)
        {
          lesRescape[j].etat=0;
          player.nbClient--;
          cptDeath++;
        }
      }
    }
    if(player.y<42)
    {
      player.angleSprite += ANGLE_ROT*4;
      player.vy = min(player.vy + 0.3, MAX_VELOCITY);
      player.vx *= 0.96;
      player.x = player.x + player.vx;
      player.y = player.y + player.vy;
    }
    else 
    {
       if(gb.buttons.pressed(BTN_B))
        {
          player.angleSprite = 0;
          player.hp = 10;
        }
    }
  }
  
}

void drawPlayer()
{
  //gb.display.print((0.90 + player.angleSprite));
  
  //gb.display.drawBitmap(0,0,Balles);
  //gb.display.drawRect(5,0,20,4);
  
  if(player.hp>0)
  {
    if(player.etat<0.5)
    {
      drawBitmapAngle(42,player.y, HelicoGauche,  player.angleSprite);
      drawMitraille((0.90 + player.angleSprite),-1);
    }
    else if(player.etat>2.5)
    {
      drawBitmapAngle(42,player.y, HelicoDroite,player.angleSprite);
      drawMitraille(0.90 - player.angleSprite,1);
    }
    else
    {
      drawBitmapAngle(42,player.y, HelicoFace,player.angleSprite);
      drawMitraille(0,1);
    }
  }
  else if(player.y<42)
  {
    drawBitmapAngle(42,player.y, HelicoExplode,player.angleSprite);
  }
  else
  {
    drawBitmapAngle(42,34, HelicoCrache,0);
  }
}

void drawMitraille(float angle,int8_t mult)
{
  if(player.mitraille)
  {
    int hauteur = (48 - player.y);
    int hypo = hauteur / cos(angle);
    int dist = 38 + (sqrt(pow(hypo,2)-pow(hauteur,2))*mult);

    for(int8_t i=-1;i<2;i++)
    {
      int8_t taille = random(1,6);
      gb.display.drawLine(dist + (i*2), 46, dist + (i*2), 46 - taille);
    }
  }
}


void drawBitmapAngle(int8_t x, int8_t y, const uint8_t *bitmap,float angle) {
  int8_t w = pgm_read_byte(bitmap);
  int8_t h = pgm_read_byte(bitmap + 1);
  int8_t centerX = w/2;
  int8_t centerY = h/2;
  bitmap = bitmap + 2; //add an offset to the pointer to start after the width and height
  int8_t i, j, byteWidth = (w + 7) / 8;
  for (j = 0; j < h; j++) {
    for (i = 0; i < w; i++) {
      if (pgm_read_byte(bitmap + j * byteWidth + i / 8) & (B10000000 >> (i % 8))) {

        int8_t desX =   (i - centerX) * cos(angle) - (j-centerY) * sin(angle);
        int8_t desY = (i-centerX) * sin(angle) + (j-centerY) * cos(angle);
        gb.display.drawPixel(x + desX, y + desY);
      }
    }
  }
}






