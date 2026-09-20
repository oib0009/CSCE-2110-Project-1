
#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <vector>

class Resource {
public:
    Resource();
    Resource(int id, const std::string& name, const std::string& type, bool available);

    int getResourceId() const;
    std::string getResourceName() const;
    std::string getResourceType() const;
    bool isAvailable() const;
    void setAvailable(bool available);

    static bool loadResources(const std::string& path = "data/resources.txt");
    static void displayResources();
    static bool findById(int id);
    static bool isResourceAvailable(int id);

private:
    int resourceId;
    std::string resourceName;
    std::string resourceType;
    bool available;

    static std::vector<Resource> resources;
};

#endif
