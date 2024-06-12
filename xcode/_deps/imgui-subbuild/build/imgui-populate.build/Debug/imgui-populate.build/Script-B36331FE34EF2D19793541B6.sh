#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/kam/stuff/gamedev/axolotls/xcode/_deps/imgui-subbuild
  /opt/homebrew/Cellar/cmake/3.27.4/bin/cmake -Dcfgdir=/Debug -P /Users/kam/stuff/gamedev/axolotls/xcode/_deps/imgui-subbuild/imgui-populate-prefix/tmp/imgui-populate-mkdirs.cmake
  /opt/homebrew/Cellar/cmake/3.27.4/bin/cmake -E touch /Users/kam/stuff/gamedev/axolotls/xcode/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp/Debug/imgui-populate-mkdir
fi

