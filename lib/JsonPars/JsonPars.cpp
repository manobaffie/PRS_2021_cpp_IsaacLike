#include "JsonPars.hpp"

JsonPars::JsonPars(std::string p) : path(p), file(p)
{
    if (this->file) {
        this->map = this->parsingJson();
    }
}

JsonPars::~JsonPars()
{
    this->file.close();
}

std::map<std::string, type> JsonPars::parsingJson()
{
    bool inStr = false, inVal = false, inTab = false;
    std::string name = "", val = "", valType = "";

    std::map<std::string, type> Obj;
    char i;

    while (this->file.get(i)) {
        if (i == '\"') inStr = inStr ? false : true;
        if (i == ':') inVal = true;

        if (i == ',' || i == '}' || i == ']') {
            if (!inTab) {
                if (valType == "str") Obj[name].s = val;
                if (valType == "int") Obj[name].i = std::stoi(val);
                name = "";
                inVal = false;
            } else {
                if (valType == "str") Obj[name].ts.push_back(val);
                if (valType == "int") Obj[name].ti.push_back(std::stoi(val));
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
                if (i == '{') Obj[name].m = this->parsingJson();
            } else {
                if (i == '{') Obj[name].tm.push_back(this->parsingJson());
            }
        }

        if (i != '\"') {
            if (!inTab && inStr && !inVal) name += i;
            if (inVal && (valType == "str" || valType == "int")) val += i;
        }
    }
    return (Obj);
}
