#pragma once

#if defined(_WIN32) // 检查是否是 Windows 平台
    #if defined(MOLDWING_FVT_EXPORTS) // 这个宏由 CMake 在构建DLL时定义
        #define MOLDWING_FVT_API __declspec(dllexport)
    #else
        #define MOLDWING_FVT_API __declspec(dllimport)
    #endif
#else // 非 Windows 平台，例如 Linux/macOS，共享库默认导出
    #define MOLDWING_FVT_API
#endif
namespace MoldWing{
    class MOLDWING_FVT_API FVT{
    public:
        FVT(){}

        int Double(int x);
    
    };
}