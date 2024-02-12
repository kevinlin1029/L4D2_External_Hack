#include "FeatureExtension.h"

std::unordered_map<std::string, int> boneMapping = { //boneMapping��һ����ϣ����ӳ���ַ�������Ӧ�Ĺ������ݡ�
    {"coach", BONE_HEAD_Coach},
    {"producer", BONE_HEAD_Rochelle},
    {"mechanic", BONE_HEAD_Ellis},
    {"gambler", BONE_HEAD_Rochelle},
    {"smoker", BONE_HEAD_smoker},
    {"hunter", BONE_HEAD_Hunter},
    {"charger", BONE_HEAD_Charger}
};

int GetEntityHead(const Entity& ModelID) {
    std::string Name(ModelID.ID); // ��Entity��ID�ֶδ���һ��string����
    for (const auto& pair : boneMapping) {
        if (Name.find(pair.first) != std::string::npos) {
            return pair.second;
        }
    }
    return 0; // Ĭ��ֵ�����û��ƥ��
}