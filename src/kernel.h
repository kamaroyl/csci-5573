#ifndef _kernel_h
#define _kernel_h

#include <circle/fs/fat/fatfs.h>

class CKernel
{
public:
    CKernel (void);
    ~CKernel (void);

    boolean Initialize (void);

private:
    CMemorySystem    m_Memory;
    CActLED          m_ActLED;
    CKernelOptions    m_Options;
    CDeviceNameService    m_DeviceNameService;
    CScreenDevice        

    CFATFileSystem    m_FileSystem;
};

#endif
