
#include "../include/Resource.h"
#include "../include/WaitingList.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<Resource> Resource::resources;

Resource::Resource() : resourceId(0), resourceName(""), resourceType(""), available(false) {}

Resource::Resource(int id, const string& name, const string& type, bool avail)
    : resourceId(id), resourceName(name), resourceType(type), available(avail) {}

int Resource::getResourceId() const { return resourceId; }
string Resource::getResourceName() const { return resourceName; }
string Resource::getResourceType() const { return resourceType; }
bool Resource::isAvailable() const { return available; }
void Resource::setAvailable(bool avail) { available = avail; }

bool Resource::loadResources(const string& path) {
    ifstream file(path);
    if (!file.is_open()) {
        cerr << "Could not open resource file: " << path << endl;
        return false;
    }

    resources.clear();

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string token;
        vector<string> parts;

        while (getline(ss, token, '|')) {
            parts.push_back(token);
        }

        if (parts.size() < 4) continue;

        string idStr = parts[0];
        if (!idStr.empty() && idStr[0] == 'R') {
            idStr.erase(idStr.begin());
        }

        int id = stoi(idStr);
        string name = parts[1];
        string type = parts[2];
        string status = parts[3];

        bool avail = (status == "Available" || status == "available" || status == "1" || status == "true");

        resources.push_back(Resource(id, name, type, avail));
    }

    return true;
}

void Resource::displayResources() {
    cout << "Resource List\n";
    cout << "ID\tName\t\tType\t\tStatus\n";
    for (const auto& r : resources) {
        cout << r.resourceId << "\t"
             << r.resourceName << "\t"
             << r.resourceType << "\t"
             << (r.available ? "Available" : "Unavailable") << "\n";
    }
}

bool Resource::findById(int id) {
    for (const auto& r : resources) {
        if (r.resourceId == id) {
            cout << "Found: " << r.resourceName << " (" << (r.available ? "Available" : "Unavailable") << ")\n";
            return true;
        }
    }
    return false;
}

bool Resource::isResourceAvailable(int id) {
    for (const auto& r : resources) {
        if (r.resourceId == id) {
            return r.available;
        }
    }
    return false;
}

//Added function to display waiting list statistics for each resource
void Resource::displayWaitingListStatistics(const WaitingList& waitingList) {
    if (resources.empty()) { //If statement for if there are no resources available
        cout << "No resources available." << endl;
        return;
    }

    for (int i = 0; i < resources.size(); i++) { //This loop iterates through all resources to display their waiting list statistics
        int resourceId = resources[i].getResourceId(); //Gets the resource ID for the current resource
        int count = waitingList.getWaitingListSize(resourceId); //Gets the number of students waiting for the current resource

        cout << "Resource ID: " <<resourceId << endl;
        cout << "Resource Name: " << resources[i].getResourceName() << endl;
        cout << "Waiting Students: " << count << endl;
        cout << endl;
    }
}