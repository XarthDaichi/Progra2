//
// Created by Xarthy on 0021 June 21, 2022.
//

#ifndef PROGRA_PROJECT_2_DELTA_STOCKFILEMANAGER_H
#define PROGRA_PROJECT_2_DELTA_STOCKFILEMANAGER_H
#include "StockData.h"
#include "SingletonFileManager.h"


class StockFileManager final : public SingletonFileManager<StockFileManager> {
private:
    StockData * info;
    bool inputType;
public:
    StockFileManager(const char c = 'b');

    virtual ~StockFileManager();

    bool isInputType() const;

    void setInfo(StockData *info);

    StockData *getInfo();
};


#endif //PROGRA_PROJECT_2_DELTA_STOCKFILEMANAGER_H
