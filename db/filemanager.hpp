//
// Created by SiriusNEO on 2021/5/13.
//

#ifndef TICKETSYSTEM_2021_MAIN_FILEMANAGER_HPP
#define TICKETSYSTEM_2021_MAIN_FILEMANAGER_HPP

#include "bpt.hpp"
#include <vector>
#include <fstream>

namespace Sirius {
    template <class keyType, class valueType> //均为定长类型
    class FileManager {
        public:
            int siz;
            Bptree<keyType, valueType> dataStructure;
            std::fstream sizeFile;
        public:
            FileManager(const char* sizeFileName) : dataStructure(("1"+std::string(sizeFileName)).c_str(), ("2"+std::string(sizeFileName)).c_str()) {
                sizeFile.open(sizeFileName, std::ios::ate | std::ios::in | std::ios::out | std::ios::binary);
                if (!sizeFile) {
                    std::ofstream outFile(sizeFileName);
                    outFile.close();
                    siz = 0;
                    sizeFile.open(sizeFileName, std::ios::ate | std::ios::in | std::ios::out | std::ios::binary);
                    sizeFile.write(reinterpret_cast<char *>(&siz), sizeof(int));
                }
                else {
                    sizeFile.seekg(0, std::ios::beg);
                    sizeFile.read(reinterpret_cast<char *>(&siz), sizeof(int));
                }
            }
            ~FileManager() {
                sizeFile.seekp(0, std::ios::beg);
                sizeFile.write(reinterpret_cast<char *>(&siz), sizeof(int));
                sizeFile.close();
            }

            int size() const {return siz;}

            void insert(const keyType& key, const valueType& val) {
                ++siz;
                dataStructure.insert(key, val);
            }

            bool del(const keyType& key) { //单点删除
                --siz;
                return dataStructure.erase(key);
            }

            bool modify(const keyType& key, const valueType& val) { //单点修改，返回是否修改成功
                return dataStructure.modify(key, val);
            }

            std::pair<valueType, bool> find(const keyType& key) {
                return dataStructure.find(key);
            }

            std::vector<valueType> rangeFind(const keyType& key1, const keyType& key2) {
                std::vector<valueType> ret;
                dataStructure.range_find(key1, key2, ret);
                return ret;
            }

            void clear() {
                siz = 0;
                dataStructure.clear();
            }
    };
}

#endif //TICKETSYSTEM_2021_MAIN_FILEMANAGER_HPP
