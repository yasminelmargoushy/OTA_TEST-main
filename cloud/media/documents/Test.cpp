#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <string>
#include <boost/filesystem.hpp>
#include "jsoncpp/header/json.h"

using namespace std;

int main(void)
{
    // Read JSON File
    Json::Value event;
    ifstream f("com.json");
    Json::Reader R;
    R.parse(f, event);
    if (!event)
    {
        event["Cluster_name"] = "C_Name";
        event["json"]["Arr1"] = Json::arrayValue;
        event["json"]["Arr2"] = Json::arrayValue;
    }

    // Add To JSON FILE
    Json::Value Temp;
    Temp["Parm1"] = 1;
    Temp["Parm2"] = 2;
    Temp["Parm3"] = 3;

    event["json"]["Arr1"].append(Temp);

    event["json"]["Arr2"].append(Temp);

    
    std::cout << event << std::endl;
    std::ofstream json_file("Result.json");
    json_file << event;
    json_file.close();

    return 0;
}
