#include <SPI.h>
#include <Gamebuino.h>
Gamebuino gb;



extern const byte font3x3[]; //a really tiny font
extern const byte font3x5[]; //a small but efficient font (default)


const byte Bunker1[] PROGMEM = {16,4,0x19,0x80,0x39,0xC0,0x79,0xE0,0xFF,0xF0,};
const byte Bunker2[] PROGMEM = {16,8,0x3,0xC0,0xF,0xF0,0x1F,0xF8,0x39,0xFC,0x61,0xFE,0x7F,0xEE,0xFF,0xEF,0xFF,0xEF,};
//const byte Cabane1[] PROGMEM = {24,20,0x0,0xC0,0x0,0x1,0xE0,0x0,0x3,0x30,0x0,0x6,0x18,0x0,0xC,0xC,0x0,0x18,0x6,0x0,0x30,0x3,0x0,0x60,0x1,0x80,0xC0,0x0,0xC0,0xFF,0xFF,0xC0,0x80,0x0,0x40,0x80,0x0,0x40,0x80,0x3C,0x40,0x9F,0x24,0x40,0x91,0x24,0x40,0x91,0x3C,0x40,0x91,0x0,0x40,0x91,0x0,0x40,0x91,0x0,0x40,0x91,0x0,0x40,};
//const byte Cloud1[] PROGMEM = {16,8,0xC,0x3C,0x12,0x62,0x21,0x81,0x42,0x1,0x84,0x2,0x80,0x4,0x43,0x88,0x3C,0x70,};
const byte HeliPort[] PROGMEM = {24,8,0x80,0x10,0x80,0x40,0x8,0x40,0x20,0x4,0x20,0x10,0x8A,0x10,0x8,0x51,0x8,0x4,0x20,0x4,0x2,0x10,0x2,0x1,0x8,0x1,};

//const byte Sun[] PROGMEM = {16,16,0x80,0x1,0x4F,0xF2,0x30,0xC,0x27,0xE4,0x48,0x12,0x53,0xCA,0x54,0x2A,0x55,0xAA,0x55,0xAA,0x54,0x2A,0x53,0xCA,0x48,0x12,0x27,0xE4,0x30,0xC,0x4F,0xF2,0x80,0x1,};

const byte Ville1[] PROGMEM = {48,40,0x0,0x0,0x0,0x3,0x0,0x0,0x0,0x0,0x0,0x5,0x80,0x0,0x6,0x0,0x0,0x9,0x40,0x0,0xB,0x0,0x3,0x11,0x20,0x0,0x12,0x80,0x5,0xA1,0x20,0x0,0x22,0x40,0x9,0x41,0x20,0x0,0x42,0x40,0x11,0x25,0x68,0x0,0x42,0x40,0x21,0x19,0x3C,0x0,0x4A,0xC0,0x41,0x11,0x2A,0x0,0x52,0x40,0x45,0x51,0x29,0x0,0x42,0x40,0x49,0x31,0x29,0x0,0x42,0x40,0x51,0x15,0x69,0x0,0x4A,0xC0,0x41,0x19,0x29,0x0,0x52,0x40,0x45,0x51,0x2B,0x0,0x42,0x40,0x49,0x31,0x29,0x0,0x42,0x43,0x51,0x11,0x29,0x0,0x4A,0xC5,0xC1,0x15,0x69,0x0,0x52,0x49,0x45,0x59,0x2B,0x0,0x42,0x51,0x29,0x31,0x29,0x0,0x42,0x61,0x11,0x11,0x29,0x0,0x4A,0xC5,0x51,0x11,0x29,0x0,0x52,0x4D,0x75,0x55,0x6B,0x0,0x42,0x59,0x19,0x39,0x29,0x0,0x42,0x41,0x11,0x11,0x29,0x0,0x4A,0xC1,0x11,0x11,0x29,0x0,0x52,0x45,0x55,0x51,0x2B,0x0,0x42,0x4D,0x79,0x35,0x69,0x0,0x42,0x59,0x11,0x19,0x29,0x0,0x4A,0xC1,0x11,0x11,0x29,0x0,0x52,0x41,0x15,0x51,0x2B,0x0,0x42,0x45,0x59,0x31,0x29,0x0,0x42,0x4D,0x71,0x15,0x69,0x0,0x4A,0xD9,0x11,0x19,0x29,0x0,0x52,0x41,0x15,0x51,0x2B,0x0,0x42,0x41,0x19,0x31,0x29,0x0,0x42,0x5D,0x51,0x15,0x69,0x0,0x42,0x5D,0x71,0x19,0x2B,0x0,0x5A,0x5D,0x15,0x51,0x2B,0x0,0x5A,0x5D,0x15,0x51,0x2B,0x0,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,};
const byte Ville2[] PROGMEM = {48,40,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x60,0x0,0x0,0x0,0x0,0x0,0xB0,0x0,0x0,0x0,0x0,0x1,0x28,0x0,0x1,0x80,0x0,0x2,0x24,0x0,0x2,0xC0,0x0,0x4,0x24,0x0,0x4,0xA0,0x0,0x8,0xAC,0x0,0x8,0x90,0x0,0x9,0xA4,0x0,0x10,0x90,0x0,0xB,0x24,0x0,0x22,0x90,0x0,0x8,0x24,0x0,0x44,0x9C,0x0,0x8,0xAC,0x0,0x40,0x96,0x0,0x9,0xA4,0x0,0x48,0x95,0x0,0xB,0x24,0x0,0x50,0x94,0x80,0x8,0x24,0x0,0x42,0x96,0x80,0x8,0xAC,0x0,0x44,0x95,0x80,0x9,0xA4,0x0,0x40,0x94,0x80,0xB,0x24,0xC0,0x48,0x94,0x80,0x8,0x25,0x60,0x50,0x96,0x80,0x8,0xAE,0x53,0x42,0x95,0x80,0x9,0xA4,0x4D,0xC4,0x94,0x80,0xA,0xE8,0x49,0x40,0x94,0x80,0xC,0xB1,0x51,0x28,0x96,0x80,0x8,0x92,0x55,0x70,0x95,0x80,0x10,0x88,0x59,0x22,0x94,0x80,0x22,0xA8,0x51,0x24,0x94,0x80,0x26,0xB9,0x51,0x20,0x96,0x80,0x2C,0x8A,0x55,0x68,0x95,0x80,0x20,0x88,0x59,0x30,0x94,0x80,0x20,0x88,0x51,0x22,0x94,0x80,0x22,0xA9,0x51,0x24,0x96,0x80,0x26,0xBA,0x55,0x60,0x95,0x80,0x2C,0x88,0x59,0x28,0x94,0x80,0x20,0x88,0x51,0x30,0x94,0x80,0x20,0x89,0x51,0x22,0x96,0x80,0x22,0xAA,0x55,0x64,0x95,0x80,0x26,0xB8,0x59,0x20,0x94,0x80,0x2C,0x88,0x51,0x28,0x94,0x80,0x20,0x8B,0x51,0x30,0x94,0x80,0x20,0x8B,0x51,0x20,0x94,0x80,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,};
const byte Ville3[] PROGMEM = {48,40,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x80,0x0,0x0,0x0,0x0,0x3,0x40,0x0,0x0,0x60,0x0,0x5,0x20,0x0,0x0,0xD0,0x0,0x9,0x10,0x0,0x1,0x48,0x0,0x9,0x8,0x0,0x2,0x44,0x0,0xD,0x44,0x0,0x2,0x42,0x0,0x9,0x64,0x0,0x2,0x51,0x0,0x9,0x34,0x0,0xE,0x48,0x80,0x9,0x4,0x0,0x1A,0x40,0x80,0xD,0x44,0x0,0x2A,0x44,0x80,0x9,0x64,0x0,0x4A,0x42,0x80,0x9,0x34,0x0,0x5A,0x50,0x80,0x9,0x4,0x0,0x6A,0x48,0x80,0xD,0x44,0x0,0x4A,0x40,0x80,0x9,0x64,0x0,0x4A,0x44,0x80,0xC9,0x34,0x0,0x5A,0x42,0x81,0xA9,0x4,0x0,0x6A,0x50,0xB2,0x9D,0x44,0x0,0x4A,0x48,0xEC,0x89,0x64,0x0,0x4A,0x40,0xA4,0x85,0xD4,0x0,0x5A,0x45,0x22,0xA3,0x4C,0x0,0x6A,0x43,0xAA,0x92,0x44,0x0,0x4A,0x51,0x26,0x84,0x42,0x0,0x4A,0x49,0x22,0x85,0x51,0x0,0x5A,0x41,0x22,0xA7,0x59,0x0,0x6A,0x45,0xAA,0x94,0x4D,0x0,0x4A,0x43,0x26,0x84,0x41,0x0,0x4A,0x51,0x22,0x84,0x41,0x0,0x5A,0x49,0x22,0xA5,0x51,0x0,0x6A,0x41,0xAA,0x97,0x59,0x0,0x4A,0x45,0x26,0x84,0x4D,0x0,0x4A,0x43,0x22,0x84,0x41,0x0,0x5A,0x51,0x22,0xA4,0x41,0x0,0x6A,0x49,0xAA,0x95,0x51,0x0,0x4A,0x41,0x26,0x87,0x59,0x0,0x4A,0x45,0x22,0x84,0x4D,0x0,0x4A,0x43,0x22,0xB4,0x41,0x0,0x4A,0x41,0x22,0xB4,0x41,0x0,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,};
const byte Ville4[] PROGMEM = {48,40,0x0,0x30,0x0,0x0,0x0,0x0,0x0,0x68,0x0,0x0,0x0,0x0,0x0,0xA4,0x0,0x0,0x18,0x0,0x1,0x22,0x30,0x0,0x34,0x0,0x1,0x21,0x68,0x0,0x52,0x0,0x1,0x20,0xA4,0x0,0x91,0x0,0x5,0xA9,0x22,0x0,0x90,0x80,0xF,0x26,0x21,0x0,0x90,0x80,0x15,0x22,0x20,0x80,0xD4,0x80,0x25,0x22,0xA8,0x80,0x92,0x80,0x25,0x23,0x24,0x80,0x90,0x80,0x25,0xAA,0x22,0x80,0x90,0x80,0x25,0x26,0x20,0x80,0xD4,0x80,0x35,0x22,0xA8,0x80,0x92,0x80,0x25,0x23,0x24,0x80,0x90,0x80,0x25,0x22,0x22,0xB0,0x90,0x80,0x25,0xAA,0x20,0xE8,0xD4,0x80,0x35,0x26,0xA8,0xA4,0x92,0x80,0x25,0x23,0x25,0x22,0x90,0x80,0x25,0x22,0x22,0x21,0x90,0x80,0x25,0x22,0x22,0xA8,0xD4,0x80,0x35,0xAA,0xAB,0xAC,0x92,0x80,0x25,0x27,0x26,0x26,0x90,0x80,0x25,0x22,0x22,0x20,0x90,0x80,0x25,0x22,0x22,0x20,0xD4,0x80,0x35,0x22,0xAA,0xA8,0x92,0x80,0x25,0xAB,0x27,0xAC,0x90,0x80,0x25,0x26,0x22,0x26,0x90,0x80,0x25,0x22,0x22,0x20,0xD4,0x80,0x35,0x22,0xAA,0x20,0x92,0x80,0x25,0x23,0x26,0xA8,0x90,0x80,0x25,0xAA,0x23,0xAC,0x90,0x80,0x25,0x26,0x22,0x26,0xD4,0x80,0x35,0x22,0xAA,0x20,0x92,0x80,0x25,0x23,0x26,0x20,0x90,0x80,0x25,0xAA,0x22,0xAE,0x90,0x80,0x35,0x26,0x23,0xAE,0x90,0x80,0x35,0x22,0xAA,0x2E,0x96,0x80,0x35,0x22,0xAA,0x2E,0x96,0x80,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,};
const byte Ville5[] PROGMEM = {48,40,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x80,0x0,0x0,0xC,0x0,0x2,0xC0,0x0,0x0,0x14,0x0,0x4,0xA0,0x0,0xE,0x14,0x0,0x8,0x90,0x0,0xB,0x24,0x0,0x10,0x90,0x0,0xB,0xE4,0x0,0x22,0x90,0x0,0x8,0x24,0x0,0x44,0x9C,0x0,0x8,0xAC,0x0,0x40,0x96,0x0,0x9,0xA4,0x0,0x48,0x95,0x0,0xB,0x24,0x0,0x78,0x94,0x80,0x8,0x24,0x0,0xA,0x96,0x80,0x8,0xAC,0x0,0x4,0x95,0x80,0x9,0xA4,0x0,0x2,0x94,0x80,0xB,0x24,0xC0,0x2,0x94,0x80,0x8,0x25,0x60,0x1E,0x96,0x80,0x8,0xAE,0x50,0x32,0x95,0x80,0x9,0xA4,0x58,0x24,0x94,0x80,0xA,0xE8,0x5C,0x20,0x94,0x80,0xC,0xB1,0x52,0x68,0x96,0x80,0x8,0x92,0x56,0xB0,0x95,0x80,0x10,0x88,0x59,0xA2,0x94,0x80,0x22,0xA8,0x50,0xA4,0x94,0x80,0x26,0xB9,0x51,0x20,0x96,0x80,0x2C,0x8A,0x55,0x68,0x95,0x80,0x20,0x88,0x59,0x30,0x94,0x80,0x20,0x88,0x51,0x22,0x94,0x80,0x22,0xA9,0x51,0x24,0x96,0x80,0x26,0xBA,0x55,0x60,0x95,0x80,0x2C,0x88,0x59,0x28,0x94,0x80,0x20,0x88,0x51,0x30,0x94,0x80,0x20,0x89,0x51,0x22,0x96,0x80,0x22,0xAA,0x55,0x64,0x95,0x80,0x26,0xB8,0x59,0x20,0x94,0x80,0x2C,0x88,0x51,0x28,0x94,0x80,0x20,0x8B,0x51,0x30,0x94,0x80,0x20,0x8B,0x51,0x20,0x94,0x80,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,};
const byte Ville6[] PROGMEM = {48,40,0x0,0x0,0x0,0x3,0x0,0x0,0x0,0x0,0x0,0x5,0x80,0x0,0x6,0x0,0x0,0x9,0x40,0x0,0xB,0x0,0x3,0x11,0x20,0x0,0x12,0x80,0x5,0xA1,0x20,0x0,0x22,0x40,0x9,0x41,0x60,0x0,0x42,0x40,0x9,0x23,0x80,0x0,0x42,0xC0,0x9,0x1A,0x0,0x0,0x4B,0x80,0x5,0x12,0x0,0x0,0x52,0x0,0x5,0x53,0xC0,0x0,0x42,0x0,0x65,0x31,0x60,0x0,0x42,0x0,0x55,0x15,0x20,0x0,0x4B,0x80,0x59,0x19,0x20,0x0,0x52,0xC0,0x45,0x51,0x20,0x0,0x42,0x40,0x49,0x31,0x30,0x0,0x42,0x40,0x51,0x11,0x28,0x0,0x4A,0xC0,0x41,0x15,0x64,0x0,0x52,0x40,0x45,0x59,0x22,0x0,0x42,0x58,0x69,0x31,0x21,0x0,0x42,0x64,0x51,0x11,0x29,0x0,0x4A,0xC6,0x91,0x11,0x25,0x0,0x52,0x41,0x15,0x55,0x63,0x0,0x42,0x59,0x19,0x39,0x21,0x0,0x42,0x41,0x11,0x11,0x29,0x0,0x4A,0xC1,0x11,0x11,0x25,0x0,0x52,0x45,0x55,0x51,0x23,0x0,0x42,0x4D,0x79,0x35,0x61,0x0,0x42,0x59,0x11,0x19,0x29,0x0,0x4A,0xC1,0x11,0x11,0x25,0x0,0x52,0x41,0x15,0x51,0x23,0x0,0x42,0x45,0x59,0x31,0x21,0x0,0x42,0x4D,0x71,0x15,0x69,0x0,0x4A,0xD9,0x11,0x19,0x25,0x0,0x52,0x41,0x15,0x51,0x23,0x0,0x42,0x41,0x19,0x31,0x21,0x0,0x42,0x5D,0x51,0x15,0x61,0x0,0x42,0x5D,0x71,0x19,0x23,0x0,0x5A,0x5D,0x15,0x51,0x23,0x0,0x5A,0x5D,0x15,0x51,0x23,0x0,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,};
const byte Ville7[] PROGMEM = {48,40,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x80,0x0,0x0,0x0,0x0,0x3,0x40,0x0,0x0,0x60,0x0,0x5,0x20,0x0,0x0,0xD0,0x0,0x9,0x10,0x0,0x1,0x48,0x0,0x9,0x8,0x0,0x2,0x48,0x0,0xD,0x44,0x0,0x2,0x50,0x0,0x9,0x64,0x0,0x2,0x51,0x0,0x9,0x34,0x0,0x2,0x4A,0x0,0x9,0x4,0x0,0x2,0x44,0x0,0xD,0x44,0x0,0x2,0x44,0x0,0x9,0x64,0x0,0x2,0x42,0x0,0x9,0x34,0x0,0x2,0x51,0x80,0x9,0x4,0x0,0x2,0x48,0x80,0xD,0x44,0x0,0x2,0x40,0x80,0x9,0x64,0x0,0x2,0x44,0x80,0x9,0x34,0x0,0x2,0x42,0x80,0x9,0x4,0x0,0x2,0x50,0xBE,0xD,0x4,0x0,0x2,0x48,0xE4,0x9,0x24,0x0,0x2,0x40,0xA9,0x9,0x15,0x0,0x2,0x45,0x2A,0xD,0x4F,0x0,0x2,0x43,0xAC,0x1F,0x2D,0x0,0x2,0x51,0x24,0x25,0x11,0x0,0x2,0x49,0x23,0x44,0xA1,0x0,0x2,0x41,0x22,0xA4,0x61,0x0,0x2,0x45,0xAA,0x94,0x41,0x0,0x2,0x43,0x26,0x84,0x41,0x0,0x2,0x51,0x22,0x84,0x41,0x0,0x2,0x49,0x22,0xA5,0x51,0x0,0x12,0x41,0xAA,0x97,0x59,0x0,0x4A,0x45,0x26,0x84,0x4D,0x0,0x66,0x43,0x22,0x84,0x41,0x0,0x5E,0x51,0x22,0xA4,0x41,0x0,0x4A,0x49,0xAA,0x95,0x51,0x0,0x4A,0x41,0x26,0x87,0x59,0x0,0x4A,0x45,0x22,0x84,0x4D,0x0,0x4A,0x43,0x22,0xB4,0x41,0x0,0x4A,0x41,0x22,0xB4,0x41,0x0,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,};

const byte jeep[] PROGMEM = {16,10,0x20,0x0,0x50,0x0,0xA0,0x0,0x40,0x40,0x44,0x40,0xFC,0x78,0xFF,0xF8,0xAF,0x78,0x50,0xA0,0x20,0x40,};
const byte Go[] PROGMEM = {24,17,0x0,0x1,0x0,0x0,0x1,0x80,0x0,0x1,0xC0,0x0,0x1,0xE0,0x0,0x1,0xF0,0xFF,0xFF,0xF8,0xFF,0xFF,0xFC,0xFF,0xFF,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFF,0xFF,0xFC,0xFF,0xFF,0xF8,0x0,0x1,0xF0,0x0,0x1,0xE0,0x0,0x1,0xC0,0x0,0x1,0x80,0x0,0x1,0x0,};


typedef struct {
  int8_t hp,nbClient;
  float vx,vy,x, y,angle,angleSprite,etat; //etat < 1 : vise a droite; etat >1   vise au centre ; etat > 2 vise a gauche
  bool dir, dirSprite,mitraille;
  
}
Copter;


typedef struct {
  int8_t etat;//0 mort, 1 safe , 2 in copter , 3 alive
  int x,tx,y; 
}
Rescape;

#define NB_RESC 50
#define NB_MAX_RESC_IN_COPTER 8
Rescape lesRescape[NB_RESC];
uint8_t cptVictoire;
uint8_t cptDeath;

typedef struct {
  uint8_t type;//permet de savoir sur quel sprite on est 0 : heliport,   1 -> 49 bat deco , >49 bat attaque
  unsigned int posX;
  uint8_t height;
  byte const * sprite;
  int8_t life;
}
Batiment;


typedef struct {
  bool isAlive;
  int x,y;
  float angle; 
}
Missile;
#define V_MISSILE 2
#define NB_MISSIBLE 20
Missile lesMissiles[NB_MISSIBLE];

#define NB_BAT_LVL 13
Batiment lesBat[NB_BAT_LVL] = {
           {0,1010,8,HeliPort,10},
           {52,1200,10,jeep,10},
           {50,1110,4,Bunker1,10},
           {51,1150,8,Bunker2,10},
           {50,1350,4,Bunker1,10},
           {51,1410,8,Bunker2,10},
           {52,1500,10,jeep,10},
           {50,1620,4,Bunker1,10},
           {51,1700,8,Bunker2,10},
           {52,1800,10,jeep,10},
           {50,1950,4,Bunker1,10},
           {51,2200,8,Bunker2,10},
           {1,2250,8,HeliPort,10},
         };
         
         


Copter player;

//le fond 
#define NB_FOND 8
byte const * leFond[8] = {Ville1,Ville5,Ville3,Ville7,Ville2,Ville3,Ville6,Ville4};

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
    updateRescaper();
    updateBatiment();
    updateMissile();
    drawPlayer();
    drawMissile();
    drawWorld();
     drawRescaper();
 }
 // gameOverScreen();
}

void initGame()
{
  player.hp = 10;
  player.x=1000;
  cptVictoire= 0;
  player.etat=3;
  
  //TODO aleatoire pour le moment
  for(uint8_t i =0;i<NB_RESC;i++)
  {
     lesRescape[i].etat = 3;
     lesRescape[i].x = random(1100,2250);
     lesRescape[i].y = random(39,44);
     lesRescape[i].tx = lesRescape[i].x;
  }
  for(byte i=0;i<NB_MISSIBLE;i++)
  {
    lesMissiles[i].isAlive = false;
  }
}

const byte title[] PROGMEM = {64,36,0x0,0xB,0x29,0xD1,0xDD,0xD9,0xD0,0xF,0xFF,0xFB,0x91,0x11,0x1D,0x14,0x9F,0xFF,0x0,0xB,0x11,0xDD,0xD5,0xD4,0x90,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xFF,0xFF,0xF8,0x0,0x0,0x0,0x0,0xE,0x0,0x20,0x0,0x0,0x0,0x0,0x0,0x11,0x3,0xFC,0x0,0x0,0x0,0x0,0x0,0x15,0xF,0x1F,0x0,0x0,0x0,0x0,0x0,0x1F,0xFF,0x89,0x80,0x0,0x0,0x0,0x0,0x15,0x1F,0xFC,0xC0,0x0,0x0,0x0,0x0,0x11,0x1,0xFF,0xE0,0x0,0x0,0x0,0x0,0xE,0x0,0xFF,0xF0,0x0,0x0,0x0,0x0,0x0,0x0,0x30,0x84,0x0,0x0,0x0,0x0,0x0,0x1,0xFF,0xF8,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x60,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x30,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xC,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x6,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3,0x0,0x60,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x30,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xE0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x38,0x0,0x0,0x1,0x82,0x0,0x20,0x0,0x1E,0x0,0x0,0x2,0x5,0x26,0x72,0x50,0x7,0xC0,0x0,0x1,0x34,0x55,0x25,0x60,0xF,0xF0,0x0,0x0,0x85,0x56,0x26,0x40,0x1F,0xF8,0x0,0x3,0x2,0x24,0x13,0x40,0x39,0xFC,0x0,0x0,0x0,0x4,0x0,0x0,0x61,0xFE,0x0,0x0,0x0,0x0,0x0,0x0,0x7F,0xEE,0x0,0x0,0x0,0x0,0x0,0x0,0xFF,0xEF,0x0,0x0,0x0,0x0,0x0,0x0,0xFF,0xEF,};
void goTitleScreen()
{
  gb.titleScreen(title);
  initGame();
}

void updateMissile()
{
  for(byte i=0;i<NB_MISSIBLE;i++)
  {
    if(lesMissiles[i].isAlive)
    {
      lesMissiles[i].x += cos(lesMissiles[i].angle)*V_MISSILE;
      lesMissiles[i].y += sin(lesMissiles[i].angle)*V_MISSILE;
      
      if(lesMissiles[i].y<-10)
      {
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
      int x = lesMissiles[i].x + cos(lesMissiles[i].angle)*V_MISSILE;
      int y = lesMissiles[i].y + sin(lesMissiles[i].angle)*V_MISSILE;
      gb.display.drawLine(lesMissiles[i].x,lesMissiles[i].y,x,y);
    }
  }
}
void updateBatiment()
{
  for(byte i=0;i<NB_BAT_LVL;i++)
  {
    if(lesBat[i].type==0)//sur un heliport
    {
      if(player.vx<0.2 &&  player.y >40 && abs(player.x -lesBat[i].posX)<40 && player.nbClient>0 && gb.frameCount%20==0)
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
    else if(lesBat[i].type>49 && abs((player.x+50) -lesBat[i].posX)<60)//Batiment d'attaque
    {
      for(byte i=0;i<NB_MISSIBLE;i++)
      {
        if(!lesMissiles[i].isAlive)
        {
          lesMissiles[i].angle = 4;//((float)random(40, 60))/10;
          lesMissiles[i].x = lesBat[i].posX +50;
          lesMissiles[i].y = (48-lesBat[i].height);
          lesMissiles[i].isAlive = true;
          //Serial.print(lesMissiles[i].angle);
          break;
        }
      }
      
    }
  }
}


void drawWorld()
{
   for(int i=0;i<3;i++)
   {
     uint8_t index = ((((int)player.x/42)%8)+i)%8;
     int indexImageX = (42*i)-((int)player.x%42);
     gb.display.drawBitmap( indexImageX,0,leFond[index]);
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
       gb.display.setColor(BLACK, WHITE);
       gb.display.drawBitmap(dist,(48-lesBat[i].height),lesBat[i].sprite);
       gb.display.setColor(BLACK);
     }
   }
   if(player.x<800)
   {
     if(gb.frameCount%20<15)
     {
       gb.display.drawBitmap(10,20,Go);
     }
   }
   
   gb.display.setFont(font3x3);
   gb.display.print("in:");
   gb.display.print(player.nbClient);
   gb.display.print(" Safe:");
   gb.display.print(cptVictoire);
   gb.display.print(" Death:");
   gb.display.print(cptDeath);
   gb.display.setFont(font3x5);
}


