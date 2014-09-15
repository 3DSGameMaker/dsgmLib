#pragma once

#define DSGM_SOUND_STREAM_COUNT 0
#define DSGM_SOUND_EFFECT_COUNT 0
#define DSGM_SOUND_COUNT (DSGM_SOUND_STREAM_COUNT + DSGM_SOUND_EFFECT_COUNT)
#define DSGM_BACKGROUND_COUNT 0
#define DSGM_PALETTE_COUNT 1
#define DSGM_SPRITE_COUNT 2
#define DSGM_OBJECT_COUNT 2
#define DSGM_ROOM_COUNT 1

// Include backgrounds, palettes and sprites to be loaded from RAM

// No sounds, no enum
//typedef enum {
//} DSGM_SoundNames;

// No backgrounds, no enum
//typedef enum {
//} DSGM_BackgroundNames;

typedef enum {
	DSGMPal0,
} DSGM_PaletteNames;

typedef enum {
	playerSprite,
	bulletSprite,
} DSGM_SpriteNames;

typedef enum {
	player,
	bullet,
} DSGM_ObjectNames;

typedef struct {
	DSGM_ObjectInstanceBase;
	struct {
		int xb, yb;
	} *variables;
} playerObjectInstance;

typedef struct {
	DSGM_ObjectInstanceBase;
	struct {
		int xb, yb;
	} *variables;
} bulletObjectInstance;

typedef enum {
	Room_1,
} DSGM_RoomNames;

extern DSGM_Sound DSGM_Sounds[DSGM_SOUND_COUNT];
extern DSGM_Background DSGM_Backgrounds[DSGM_BACKGROUND_COUNT];
extern DSGM_Palette DSGM_Palettes[DSGM_PALETTE_COUNT];
extern DSGM_Sprite DSGM_Sprites[DSGM_SPRITE_COUNT];
extern DSGM_Object DSGM_Objects[DSGM_OBJECT_COUNT];
extern DSGM_Room DSGM_Rooms[DSGM_ROOM_COUNT];

extern int DSGM_currentRoom;

void DSGM_SetupRooms(int room);

void player_create(playerObjectInstance *me);
void player_loop(playerObjectInstance *me);

void bullet_create(bulletObjectInstance *me);
void bullet_loop(bulletObjectInstance *me);
void bullet_destroy(bulletObjectInstance *me);
