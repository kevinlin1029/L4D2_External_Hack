#include "FeatureExtension.h"

std::unordered_map<std::string, int> boneMapping = { //boneMapping是一个哈希表，它映射字符串到相应的骨骼数据。
    {"coach", BONE_HEAD_Coach},
    {"producer", BONE_HEAD_Rochelle},
    {"mechanic", BONE_HEAD_Ellis},
    {"gambler", BONE_HEAD_Rochelle},
    {"smoker", BONE_HEAD_smoker},
    {"hunter", BONE_HEAD_Hunter},
    {"charger", BONE_HEAD_Charger}
};

int GetEntityHead(const Entity& ModelID) {
    std::string Name(ModelID.ID); // 从Entity的ID字段创建一个string对象
    for (const auto& pair : boneMapping) {
        if (Name.find(pair.first) != std::string::npos) {
            return pair.second;
        }
    }
    return 0; // 默认值，如果没有匹配
}