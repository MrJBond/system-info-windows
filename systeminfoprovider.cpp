#include "systeminfoprovider.h"

SystemInfoProvider::SystemInfoProvider() {}

ULONGLONG SystemInfoProvider::printMemoryStatus() {
    MEMORYSTATUSEX memoryStatus;
    memoryStatus.dwLength = sizeof(MEMORYSTATUSEX);

    if (GlobalMemoryStatusEx(&memoryStatus)) {
        DWORDLONG totalPhys = memoryStatus.ullTotalPhys;  // Total physical memory
        DWORDLONG availPhys = memoryStatus.ullAvailPhys;  // Available physical memory
        DWORDLONG usedPhys = totalPhys - availPhys;       // Used physical memory

        qDebug() << "Total Physical Memory: " << totalPhys / (1024 * 1024) << " MB\n";
        qDebug() << "Available Physical Memory: " << availPhys / (1024 * 1024) << " MB\n";
        qDebug() << "Used Physical Memory: " << usedPhys / (1024 * 1024) << " MB\n";
        return usedPhys;
    } else {
        throw std::runtime_error("Failed to get memory status. Error: " + std::to_string(GetLastError()));
    }
}
void SystemInfoProvider::getDesktopResolution(int& horizontal, int& vertical){
    RECT desktop;
    const HWND wDesktop = GetDesktopWindow();
    GetWindowRect(wDesktop, &desktop);
    // The top left corner will have coordinates (0,0)
    // and the bottom right corner will have coordinates
    // (horizontal, vertical)
    horizontal = desktop.right;
    vertical = desktop.bottom;
}
