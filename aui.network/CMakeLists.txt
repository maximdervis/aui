cmake_minimum_required(VERSION 3.10)

aui_module(aui.network EXPORT aui)

aui_link(aui.network PRIVATE aui.core)
if(WIN32)
  aui_link(aui.network PRIVATE wsock32 ws2_32)
endif()
