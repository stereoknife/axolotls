# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/kam/stuff/gamedev/axolotls/xcode/_deps/imgui-src"
  "/Users/kam/stuff/gamedev/axolotls/xcode/_deps/imgui-build"
  "/Users/kam/stuff/gamedev/axolotls/xcode/_deps/imgui-subbuild/imgui-populate-prefix"
  "/Users/kam/stuff/gamedev/axolotls/xcode/_deps/imgui-subbuild/imgui-populate-prefix/tmp"
  "/Users/kam/stuff/gamedev/axolotls/xcode/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp"
  "/Users/kam/stuff/gamedev/axolotls/xcode/_deps/imgui-subbuild/imgui-populate-prefix/src"
  "/Users/kam/stuff/gamedev/axolotls/xcode/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/kam/stuff/gamedev/axolotls/xcode/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/kam/stuff/gamedev/axolotls/xcode/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
