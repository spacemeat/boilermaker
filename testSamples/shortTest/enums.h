#pragma once

typedef enum eAnimals {
    E_CAT,
    E_DOG,
    E_PIG,
    E_BUG
} eAnimals;


typedef enum eBugs {
    E_ANT,
    E_BEE,
    E_FLY
} eBugs;


typedef enum eFoodFlagBits {
    EFOODFLAGBITS_CAT_FOOD_FLAG = 0x0001,
    EFOODFLAGBITS_DOG_FOOD_FLAG = 0x0002,
    EFOODFLAGBITS_PIG_FOOD_FLAG = 0x0004
} eFoods;
