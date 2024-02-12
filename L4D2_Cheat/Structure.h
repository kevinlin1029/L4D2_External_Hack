#pragma once
#include <Windows.h>
#include <string>
using namespace std;

struct Vec2 {
	float x;
	float y;
};

struct Vec3 {
	float x;
	float y;
	float z;
};

struct Vec4 {
	float x;
	float y;
	float z;
	float w;
};

struct Entity {
	char ID[20];
};


//¹Ç÷ÀÊý¾Ý
#define BONE_HEAD_Ellis 61
#define BONE_HEAD_Coach 71
#define BONE_HEAD_Rochelle 78

#define BONE_HEAD_smoker 30
#define BONE_HEAD_Hunter 14
#define BONE_HEAD_Charger 16

