//
// Created by Xarthy on 0006 May 06, 2022.
//

#ifndef PROGRA2_PROJECT_1_DELTA_ROUTEFILEMANAGER_H
#define PROGRA2_PROJECT_1_DELTA_ROUTEFILEMANAGER_H
#include "SingletonFileManager.h"
#include "Route.h"

class RouteFileManager final : public SingletonFileManager<RouteFileManager> {
private:
    Container<Route>* routes;
    char inputType;
public:
    RouteFileManager(const char c = 'b');
    virtual ~RouteFileManager();

    void setInputType(char inputType);

    Container<Route>* getRoutes();

    static ostream& write(ostream& out, const Route& route);
    static istream& read(istream& in, Route& route);
};


#endif //PROGRA2_PROJECT_1_DELTA_ROUTEFILEMANAGER_H
