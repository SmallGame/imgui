#ifndef IMGUISTYLESERIALIZER_H_
#define IMGUISTYLESERIALIZER_H_

#ifndef IMGUI_API
#include <imgui.h>
#endif //IMGUI_API

enum ImGuiStyleEnum {
    ImGuiStyle_Default=0,
    ImGuiStyle_Gray,        // This is the default theme of my main.cpp demo.
    ImGuiStyle_Light,
    ImGuiStyle_OSX,         // Posted by @itamago here: https://github.com/ocornut/imgui/pull/511 (hope I can use it)
    ImGuiStyle_OSXOpaque,
    ImGuiStyle_DarkOpaque,

    ImGuiStyle_DefaultInverse,
    ImGuiStyle_OSXInverse,
    ImGuiStyle_OSXOpaqueInverse,
    ImGuiStyle_DarkOpaqueInverse,

    ImGuiStyle_Count
};

namespace ImGui	{
// Warning: this file does not depend on imguihelper (so it's easier to reuse it in stand alone projects).
// The drawback is that it's not possible to serialize/deserialize a style together with other stuff (for example 2 styles together) into/from a single file.
// And it's not possible to serialize/deserialize a style into/from a memory buffer too.
#ifndef NO_IMGUISTYLESERIALIZER_SAVESTYLE
bool SaveStyle(const char* filename,const ImGuiStyle& style=ImGui::GetStyle());
#endif //NO_IMGUISTYLESERIALIZER_SAVESTYLE
#ifndef NO_IMGUISTYLESERIALIZER_LOADSTYLE
bool LoadStyle(const char* filename,ImGuiStyle& style=ImGui::GetStyle());
#endif //NO_IMGUISTYLESERIALIZER_LOADSTYLE
bool ResetStyle(int styleEnum, ImGuiStyle& style=ImGui::GetStyle());
const char** GetDefaultStyleNames();   // ImGuiStyle_Count names re returned

// satThresholdForInvertingLuminance: in [0,1] if == 0.f luminance is not inverted at all
// shiftHue: in [0,1] if == 0.f hue is not changed at all
void ChangeStyleColors(ImGuiStyle& style,float satThresholdForInvertingLuminance=.1f,float shiftHue=0.f);
} // namespace ImGui

#endif //IMGUISTYLESERIALIZER_H_

