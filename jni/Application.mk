# The ARMv7 is significanly faster due to the use of the hardware FPU
APP_ABI := armeabi armeabi-v7a
#APP_ABI := all 
#APP_ABI := armeabi armeabi-v7a x86
#APP_PLATFORM := android-8
#APP_CPPFLAGS := 
APP_STL := stlport_static

#system -> Use the default minimal C++ runtime library.
#stlport_static -> Use STLport built as a static library.
#stlport_shared -> Use STLport built as a shared library.
#gnustl_static -> Use GNU libstdc++ as a static library.