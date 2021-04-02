#include "ILog.hpp"

void ILog::setLog(ILog *l) { 
    ILog::load = l;
}

void ILog::log() {
    load->write();
};
