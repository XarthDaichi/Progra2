//
// Created by Xarthy on 0020 April 20, 2022.
//

#ifndef LAB04_V2_DATAFLOW_XARTHDAICHI_FILEMANAGER_H
#define LAB04_V2_DATAFLOW_XARTHDAICHI_FILEMANAGER_H
#include "PersonManager.h"
#include<fstream>

class FileManager {
public:
    FileManager();

    virtual ~FileManager();

    static PersonManager loadCSV(const std::string &filename);
    static PersonManager loadDAT(const std::string &filename);

    static void saveCSV(const std::string &filename, const PersonManager &PM);
    static void saveDAT(const std::string &filename, const PersonManager &PM);

    static std::ostream& write(std::ostream& out, const Person& person);

    static std::istream& read(std::istream& in, Person& person);
};


#endif //LAB04_V2_DATAFLOW_XARTHDAICHI_FILEMANAGER_H
