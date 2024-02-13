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



//¹Ç÷ÀÊı¾İ
#define BONE_HEAD_Ellis 61 //Í·
#define BONE_NECK_Ellis 13 //²±×Ó
#define BONE_LEFT_SHOULDER_Ellis 6//×ó¼ç
#define BONE_RIGHT_SHOULDER_Ellis 9//ÓÒ¼ç
#define BONE_LEFT_ELBOW_Ellis 73//×óÖâ
#define BONE_RIGHT_ELBOW_Ellis 76//ÓÒÖâ
#define BONE_LEFT_HAND_Ellis 64//×óÊÖ
#define BONE_RIGHT_HAND_Ellis 11//ÓÒÊÖ
#define BONE_CROSS_Ellis 0 //¿è²¿
#define BONE_LEFT_KNEE_Ellis 69//×óÏ¥
#define BONE_RIGHT_KNEE_Ellis 70//ÓÒÏ¥
#define BONE_LEFT_FOOT_Ellis 33//×ó½Å
#define BONE_RIGHT_FOOT_Ellis 32//ÓÒ½Å

#define BONE_HEAD_Nick 61
#define BONE_NECK_Nick 13 //²±×Ó
#define BONE_LEFT_SHOULDER_Nick 16//×ó¼ç
#define BONE_RIGHT_SHOULDER_Nick 35//ÓÒ¼ç
#define BONE_LEFT_ELBOW_Nick 76//×óÖâ
#define BONE_RIGHT_ELBOW_Nick 83//ÓÒÖâ
#define BONE_LEFT_HAND_Nick 30//×óÊÖ
#define BONE_RIGHT_HAND_Nick 51//ÓÒÊÖ
#define BONE_CROSS_Nick 0 //¿è²¿
#define BONE_LEFT_KNEE_Nick 69//×óÏ¥
#define BONE_RIGHT_KNEE_Nick 72//ÓÒÏ¥
#define BONE_LEFT_FOOT_Nick 3//×ó½Å
#define BONE_RIGHT_FOOT_Nick 7//ÓÒ½Å

#define BONE_HEAD_Coach 71
#define BONE_NECK_Coach 16 //²±×Ó
#define BONE_LEFT_SHOULDER_Coach 9//×ó¼ç
#define BONE_RIGHT_SHOULDER_Coach 6//ÓÒ¼ç
#define BONE_LEFT_ELBOW_Coach 65//×óÖâ
#define BONE_RIGHT_ELBOW_Coach 66//ÓÒÖâ
#define BONE_LEFT_HAND_Coach 43//×óÊÖ
#define BONE_RIGHT_HAND_Coach 60//ÓÒÊÖ
#define BONE_CROSS_Coach 0 //¿è²¿
#define BONE_LEFT_KNEE_Coach 39//×óÏ¥
#define BONE_RIGHT_KNEE_Coach 18//ÓÒÏ¥
#define BONE_LEFT_FOOT_Coach 41//×ó½Å
#define BONE_RIGHT_FOOT_Coach 20//ÓÒ½Å


#define BONE_HEAD_Rochelle 69
#define BONE_NECK_Rochelle 15 //²±×Ó
#define BONE_LEFT_SHOULDER_Rochelle 9//×ó¼ç
#define BONE_RIGHT_SHOULDER_Rochelle 6//ÓÒ¼ç
#define BONE_LEFT_ELBOW_Rochelle 63//×óÖâ
#define BONE_RIGHT_ELBOW_Rochelle 64//ÓÒÖâ
#define BONE_LEFT_HAND_Rochelle 72//×óÊÖ
#define BONE_RIGHT_HAND_Rochelle 13//ÓÒÊÖ
#define BONE_CROSS_Rochelle 0 //¿è²¿
#define BONE_LEFT_KNEE_Rochelle 22//×óÏ¥
#define BONE_RIGHT_KNEE_Rochelle 17//ÓÒÏ¥
#define BONE_LEFT_FOOT_Rochelle 23//×ó½Å
#define BONE_RIGHT_FOOT_Rochelle 18//ÓÒ½Å

#define BONE_HEAD_Jockey 7
#define BONE_NECK_Jockey 5 //²±×Ó
#define BONE_LEFT_SHOULDER_Jockey 9//×ó¼ç
#define BONE_RIGHT_SHOULDER_Jockey 28//ÓÒ¼ç
#define BONE_LEFT_ELBOW_Jockey 10//×óÖâ
#define BONE_RIGHT_ELBOW_Jockey 29//ÓÒÖâ
#define BONE_LEFT_HAND_Jockey 12//×óÊÖ
#define BONE_RIGHT_HAND_Jockey 32//ÓÒÊÖ
#define BONE_CROSS_Jockey 0 //¿è²¿
#define BONE_LEFT_KNEE_Jockey 47//×óÏ¥
#define BONE_RIGHT_KNEE_Jockey 51//ÓÒÏ¥
#define BONE_LEFT_FOOT_Jockey 48//×ó½Å
#define BONE_RIGHT_FOOT_Jockey 52//ÓÒ½Å

#define BONE_HEAD_Smoker 30
#define BONE_NECK_Smoker 15 //²±×Ó
#define BONE_LEFT_SHOULDER_Smoker 16//×ó¼ç
#define BONE_RIGHT_SHOULDER_Smoker 20//ÓÒ¼ç
#define BONE_LEFT_ELBOW_Smoker 17//×óÖâ
#define BONE_RIGHT_ELBOW_Smoker 21//ÓÒÖâ
#define BONE_LEFT_HAND_Smoker 18//×óÊÖ
#define BONE_RIGHT_HAND_Smoker 22//ÓÒÊÖ
#define BONE_CROSS_Smoker 0 //¿è²¿
#define BONE_LEFT_KNEE_Smoker 2//×óÏ¥
#define BONE_RIGHT_KNEE_Smoker 6//ÓÒÏ¥
#define BONE_LEFT_FOOT_Smoker 3//×ó½Å
#define BONE_RIGHT_FOOT_Smoker 7//ÓÒ½Å


#define BONE_HEAD_Hunter 14
#define BONE_NECK_Hunter 12 //²±×Ó
#define BONE_LEFT_SHOULDER_Hunter 16//×ó¼ç
#define BONE_RIGHT_SHOULDER_Hunter 35//ÓÒ¼ç
#define BONE_LEFT_ELBOW_Hunter 17//×óÖâ
#define BONE_RIGHT_ELBOW_Hunter 36//ÓÒÖâ
#define BONE_LEFT_HAND_Hunter 18//×óÊÖ
#define BONE_RIGHT_HAND_Hunter 50//ÓÒÊÖ
#define BONE_CROSS_Hunter 0 //¿è²¿
#define BONE_LEFT_KNEE_Hunter 2//×óÏ¥
#define BONE_RIGHT_KNEE_Hunter 6//ÓÒÏ¥
#define BONE_LEFT_FOOT_Hunter 3//×ó½Å
#define BONE_RIGHT_FOOT_Hunter 7//ÓÒ½Å


#define BONE_HEAD_Charger 16
#define BONE_NECK_Charger 5 //²±×Ó
#define BONE_LEFT_SHOULDER_Charger 18//×ó¼ç
#define BONE_RIGHT_SHOULDER_Charger 6//ÓÒ¼ç
#define BONE_LEFT_ELBOW_Charger 19//×óÖâ
#define BONE_RIGHT_ELBOW_Charger 7//ÓÒÖâ
#define BONE_LEFT_HAND_Charger 20//×óÊÖ
#define BONE_RIGHT_HAND_Charger 24//ÓÒÊÖ
#define BONE_CROSS_Charger 0 //¿è²¿
#define BONE_LEFT_KNEE_Charger 10//×óÏ¥
#define BONE_RIGHT_KNEE_Charger 13//ÓÒÏ¥
#define BONE_LEFT_FOOT_Charger 11//×ó½Å
#define BONE_RIGHT_FOOT_Charger 14//ÓÒ½Å

#define BONE_HEAD_Tank 13
#define BONE_NECK_Tank 13 //²±×Ó
#define BONE_LEFT_SHOULDER_Tank 16//×ó¼ç
#define BONE_RIGHT_SHOULDER_Tank 35//ÓÒ¼ç
#define BONE_LEFT_ELBOW_Tank 17//×óÖâ
#define BONE_RIGHT_ELBOW_Tank 36//ÓÒÖâ
#define BONE_LEFT_HAND_Tank 31//×óÊÖ
#define BONE_RIGHT_HAND_Tank 51//ÓÒÊÖ
#define BONE_CROSS_Tank 0 //¿è²¿
#define BONE_LEFT_KNEE_Tank 2//×óÏ¥
#define BONE_RIGHT_KNEE_Tank 6//ÓÒÏ¥
#define BONE_LEFT_FOOT_Tank 4//×ó½Å
#define BONE_RIGHT_FOOT_Tank 8//ÓÒ½Å

#define BONE_HEAD_Spitter 7
#define BONE_NECK_Spitter 35 //²±×Ó
#define BONE_LEFT_SHOULDER_Spitter 17//×ó¼ç
#define BONE_RIGHT_SHOULDER_Spitter 36//ÓÒ¼ç
#define BONE_LEFT_ELBOW_Spitter 18//×óÖâ
#define BONE_RIGHT_ELBOW_Spitter 37//ÓÒÖâ
#define BONE_LEFT_HAND_Spitter 19//×óÊÖ
#define BONE_RIGHT_HAND_Spitter 38//ÓÒÊÖ
#define BONE_CROSS_Spitter 0 //¿è²¿
#define BONE_LEFT_KNEE_Spitter 58//×óÏ¥
#define BONE_RIGHT_KNEE_Spitter 63//ÓÒÏ¥
#define BONE_LEFT_FOOT_Spitter 59//×ó½Å
#define BONE_RIGHT_FOOT_Spitter 64//ÓÒ½Å

#define BONE_HEAD_Boomer 14
#define BONE_NECK_Boomer 12 //²±×Ó
#define BONE_LEFT_SHOULDER_Boomer 16//×ó¼ç
#define BONE_RIGHT_SHOULDER_Boomer 20//ÓÒ¼ç
#define BONE_LEFT_ELBOW_Boomer 17//×óÖâ
#define BONE_RIGHT_ELBOW_Boomer 21//ÓÒÖâ
#define BONE_LEFT_HAND_Boomer 18//×óÊÖ
#define BONE_RIGHT_HAND_Boomer 22//ÓÒÊÖ
#define BONE_CROSS_Boomer 0 //¿è²¿
#define BONE_LEFT_KNEE_Boomer 2//×óÏ¥
#define BONE_RIGHT_KNEE_Boomer 6//ÓÒÏ¥
#define BONE_LEFT_FOOT_Boomer 3//×ó½Å
#define BONE_RIGHT_FOOT_Boomer 7//ÓÒ½Å

#define BONE_HEAD_Witch 53
#define BONE_NECK_Witch 11 //²±×Ó
#define BONE_LEFT_SHOULDER_Witch 65//×ó¼ç
#define BONE_RIGHT_SHOULDER_Witch 35//ÓÒ¼ç
#define BONE_LEFT_ELBOW_Witch 17//×óÖâ
#define BONE_RIGHT_ELBOW_Witch 36//ÓÒÖâ
#define BONE_LEFT_HAND_Witch 33//×óÊÖ
#define BONE_RIGHT_HAND_Witch 47//ÓÒÊÖ
#define BONE_CROSS_Witch 0 //¿è²¿
#define BONE_LEFT_KNEE_Witch 2//×óÏ¥
#define BONE_RIGHT_KNEE_Witch 6//ÓÒÏ¥
#define BONE_LEFT_FOOT_Witch 3//×ó½Å
#define BONE_RIGHT_FOOT_Witch 7//ÓÒ½Å

#define BONE_HEAD_Louis 59
#define BONE_NECK_Louis 13 //²±×Ó
#define BONE_LEFT_SHOULDER_Louis 16//×ó¼ç
#define BONE_RIGHT_SHOULDER_Louis 35//ÓÒ¼ç
#define BONE_LEFT_ELBOW_Louis 80//×óÖâ
#define BONE_RIGHT_ELBOW_Louis 85//ÓÒÖâ
#define BONE_LEFT_HAND_Louis 64//×óÊÖ
#define BONE_RIGHT_HAND_Louis 37//ÓÒÊÖ
#define BONE_CROSS_Louis 0 //¿è²¿
#define BONE_LEFT_KNEE_Louis 73//×óÏ¥
#define BONE_RIGHT_KNEE_Louis 75//ÓÒÏ¥
#define BONE_LEFT_FOOT_Louis 3//×ó½Å
#define BONE_RIGHT_FOOT_Louis 7//ÓÒ½Å

#define BONE_HEAD_Francis 58
#define BONE_NECK_Francis 13 //²±×Ó
#define BONE_LEFT_SHOULDER_Francis 76//×ó¼ç
#define BONE_RIGHT_SHOULDER_Francis 83//ÓÒ¼ç
#define BONE_LEFT_ELBOW_Francis 73//×óÖâ
#define BONE_RIGHT_ELBOW_Francis 80//ÓÒÖâ
#define BONE_LEFT_HAND_Francis 64//×óÊÖ
#define BONE_RIGHT_HAND_Francis 37//ÓÒÊÖ
#define BONE_CROSS_Francis 0 //¿è²¿
#define BONE_LEFT_KNEE_Francis 69//×óÏ¥
#define BONE_RIGHT_KNEE_Francis 70//ÓÒÏ¥
#define BONE_LEFT_FOOT_Francis 3//×ó½Å
#define BONE_RIGHT_FOOT_Francis 7//ÓÒ½Å

#define BONE_HEAD_Zoey 68
#define BONE_NECK_Zoey 13 //²±×Ó
#define BONE_LEFT_SHOULDER_Zoey 16//×ó¼ç
#define BONE_RIGHT_SHOULDER_Zoey 35//ÓÒ¼ç
#define BONE_LEFT_ELBOW_Zoey 82//×óÖâ
#define BONE_RIGHT_ELBOW_Zoey 87//ÓÒÖâ
#define BONE_LEFT_HAND_Zoey 81//×óÊÖ
#define BONE_RIGHT_HAND_Zoey 84//ÓÒÊÖ
#define BONE_CROSS_Zoey 0 //¿è²¿
#define BONE_LEFT_KNEE_Zoey 77//×óÏ¥
#define BONE_RIGHT_KNEE_Zoey 79//ÓÒÏ¥
#define BONE_LEFT_FOOT_Zoey 3//×ó½Å
#define BONE_RIGHT_FOOT_Zoey 7//ÓÒ½Å

#define BONE_HEAD_Bill 61
#define BONE_NECK_Bill 13 //²±×Ó
#define BONE_LEFT_SHOULDER_Bill 16//×ó¼ç
#define BONE_RIGHT_SHOULDER_Bill 35//ÓÒ¼ç
#define BONE_LEFT_ELBOW_Bill 73//×óÖâ
#define BONE_RIGHT_ELBOW_Bill 79//ÓÒÖâ
#define BONE_LEFT_HAND_Bill 64//×óÊÖ
#define BONE_RIGHT_HAND_Bill 37//ÓÒÊÖ
#define BONE_CROSS_Bill 0 //¿è²¿
#define BONE_LEFT_KNEE_Bill 69//×óÏ¥
#define BONE_RIGHT_KNEE_Bill 70//ÓÒÏ¥
#define BONE_LEFT_FOOT_Bill 3//×ó½Å
#define BONE_RIGHT_FOOT_Bill 7//ÓÒ½Å

#define BONE_HEAD_Zombie 30
#define BONE_NECK_Zombie 22 //²±×Ó
#define BONE_LEFT_SHOULDER_Zombie 16//×ó¼ç
#define BONE_RIGHT_SHOULDER_Zombie 23//ÓÒ¼ç
#define BONE_LEFT_ELBOW_Zombie 17//×óÖâ
#define BONE_RIGHT_ELBOW_Zombie 24//ÓÒÖâ
#define BONE_LEFT_HAND_Zombie 21//×óÊÖ
#define BONE_RIGHT_HAND_Zombie 28//ÓÒÊÖ
#define BONE_CROSS_Zombie 0 //¿è²¿
#define BONE_LEFT_KNEE_Zombie 2//×óÏ¥
#define BONE_RIGHT_KNEE_Zombie 6//ÓÒÏ¥
#define BONE_LEFT_FOOT_Zombie 3//×ó½Å
#define BONE_RIGHT_FOOT_Zombie 7//ÓÒ½Å



struct BoneMatrix {//ÈËÎï¹Ç÷ÀĞÅÏ¢
	int Head;
	int Neck;
	int Left_Shoulder;
	int Right_Shoulder;
	int Left_Elbow;
	int Right_Elbow;
	int Left_Hand;
	int Right_Hand;
	int Cross;
	int Left_Knee;
	int Right_Knee;
	int Left_Foot;
	int Right_Foot;
};

