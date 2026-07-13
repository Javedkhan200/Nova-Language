#ifndef NOVA_DEPLOY_H
#define NOVA_DEPLOY_H
#include <string>
#include <iostream>
class NovaDeploy {
public:
    static void containerize(const std::string& name);
    static void pushToCloud(const std::string& provider);
};
#endif
