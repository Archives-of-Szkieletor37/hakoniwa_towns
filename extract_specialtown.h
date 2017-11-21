// extract_specialtown.h
#ifndef _EXTRACT_SPECIALTOWN_H_
#define _EXTRACT_SPECIALTOWN_H_
#include "dictionary_specialtown.h"
#include "building.h"

#define MAX_SPECIALTOWN_PER_BUILDING 20 // これはここじゃないかもしれない

extern int cnt_specialtown_regards_mainb;

extern void extract_specialtown(SpecialTown dictionary_specialtown[], Building *target, SpecialTown DS_list_regards_target[]);

#endif // _EXTRACT_SPECIALTOWN_H_

