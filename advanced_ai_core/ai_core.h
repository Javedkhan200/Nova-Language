#ifndef AI_CORE_H
#define AI_CORE_H
#include <string>
#include <iostream>

class NeuraBrain {
public:
    static void initializeModel(const std::string& name);
    static void trainDataset(const std::string& data);
    static void runInference(const std::string& prompt);
    static void generateVisual(const std::string& description);
    static void renderVideo(const std::string& concept);
};
#endif
