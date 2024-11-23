#ifndef SYSTEMINFOPROVIDER_H
#define SYSTEMINFOPROVIDER_H
#include "wtypes.h"
#include <QDebug>
#include <windows.h>
#include <wbemidl.h>
#include "sysinfoapi.h"

class SystemInfoProvider
{
public:
    SystemInfoProvider();

    void getDesktopResolution(int& horizontal, int& vertical);
    ULONGLONG printMemoryStatus();
};

#endif // SYSTEMINFOPROVIDER_H
