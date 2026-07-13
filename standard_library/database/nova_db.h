#ifndef NOVA_DB_H
#define NOVA_DB_H
#include <string>
#include <iostream>

class NovaDB {
public:
    static void connect(const std::string& dbName);
    static void createTable(const std::string& tableName);
    static void insertRecord(const std::string& data);
    static void queryData(const std::string& query);
    static void backup(const std::string& target);
    static void close();
};
#endif
