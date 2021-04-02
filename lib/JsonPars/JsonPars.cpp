#include "JsonPars.hpp"

JsonPars::JsonPars(std::string p) : path(p), file(p), indx(0)
{
    if (this->file) {
        this->mapJ = this->parsingJson();
    }
}

JsonPars::~JsonPars()
{
    this->file.close();
}

Obj_s JsonPars::parsingJson()
{
    bool inStr = false, inVal = false, inTab = false;
    std::string name = "", val = "", valType = "";

    Obj_s Obj;
    char i;

    while (this->file.get(i)) {
        if (i == '\"') inStr = inStr ? false : true;
        if (i == ':') inVal = true;

        if (i == ',' || i == '}' || i == ']') {
            if (!inTab) {
                if (valType == "str") Obj.map<std::string>[name] = val;
                if (valType == "int") Obj.map<int>[name] = std::stoi(val);
                name = "";
                inVal = false;
            } else {
                if (valType == "str") Obj.map<std::vector<std::string>>[name].push_back(val);
                if (valType == "int") Obj.map<std::vector<int>>[name].push_back(std::stoi(val));
            }

            if (i == '}') return (Obj);
            if (i == ']') inTab = false;
            valType = val = "";
        }

        if (inVal && i != ' ' && valType.size() == 0) {
            if (std::isdigit(i)) valType = "int";
            if (inStr) valType = "str";
            if (i == '[') inTab = true;

            if (!inTab) {
                if (i == '{') Obj.map<Obj_s>[name] = this->parsingJson();
            } else {
                if (i == '{') Obj.map<std::vector<Obj_s>>[name].push_back(this->parsingJson());
            }
        }

        if (i != '\"') {
            if (!inTab && inStr && !inVal) name += i;
            if (inVal && (valType == "str" || valType == "int")) val += i;
        }
    }
    return (Obj);
}
