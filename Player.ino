const byte HelicoDroite[] PROGMEM = {
  32,10,0x7,0xFF,0xFF,0xC0,0x70,0x1,0x0,0x0,0x88,0x1F,0xE0,0x0,0xA8,0x78,0xF8,0x0,0xFF,0xFC,0x4C,0x0,0xA8,0xFF,0xE6,0x0,0x88,0xF,0xFF,0x0,0x70,0x7,0xFF,0x80,0x0,0x1,0x84,0x20,0x0,0xF,0xFF,0xC0,};
const byte HelicoFace[] PROGMEM = {
  24,11,0xFF,0xFF,0x80,0x0,0x80,0x0,0x3,0xE0,0x0,0xE,0x38,0x0,0x8,0x8,0x0,0xC,0x98,0x0,0xE,0xB8,0x0,0x7,0xF0,0x0,0x3,0xE0,0x0,0x4,0x10,0x0,0xC,0x18,0x0,};
const byte HelicoGauche[] PROGMEM = {
  32,10,0x7F,0xFF,0xFC,0x0,0x0,0x10,0x1,0xC0,0x0,0xFF,0x2,0x20,0x3,0xE3,0xC2,0xA0,0x6,0x47,0xFF,0xE0,0xC,0xFF,0xE2,0xA0,0x1F,0xFE,0x2,0x20,0x3F,0xFC,0x1,0xC0,0x84,0x30,0x0,0x0,0x7F,0xFE,0x0,0x0,};

#define ANGLE_ROT 0.05
#define MAX_VELOCITY 2

void updatePlayer()
{
  if(gb.buttons.repeat(BTN_RIGHT, 1))
  {
    player.angleSprite = min(player.angleSprite+ANGLE_ROT, 0.6);
    player.vx = min(player.vx + 0.18, MAX_VELOCITY);
  }
  if(gb.buttons.repeat(BTN_LEFT, 1))
  {
    player.angleSprite = max( player.angleSprite - ANGLE_ROT, -0.60);
    player.vx = max(player.vx - 0.18, -MAX_VELOCITY);
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
  player.vy *= 0.97;

  player.x = player.x + player.vx;
  player.y = player.y + player.vy;

  if(player.y >43)
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
      player.y = 43;
      player.vy = 0;
    }
  }
  if(player.y <10)
  {
    player.y = 10;
    player.vy = 0;
  }
}

void drawPlayer()
{
  gb.display.print(player.vx);
  if(player.etat<0.5)
  {
    drawBitmapAngle(42,player.y, HelicoGauche,player.angleSprite);
    //drawMitraille(player.angleSprite);
  }
  else if(player.etat>2.5)
  {
    drawBitmapAngle(42,player.y, HelicoDroite,player.angleSprite);
   // drawMitraille(player.angleSprite);
  }
  else
  {
    drawBitmapAngle(42,player.y, HelicoFace,player.angleSprite);
    //drawMitraille(90);
  }
}

void drawMitraille(float angle)
{
  if(player.mitraille)
  {
    int8_t taille = random(2,10);
    int8_t newx = player.x + cos(angle)*taille;
    int8_t newy = player.y + sin(angle)*taille;
    gb.display.drawLine(player.x, player.y, newx, newy);
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


