#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/kam/stuff/gamedev/axolotls/xcode/_deps/imgui-src
  /opt/homebrew/Cellar/cmake/3.27.4/bin/cmake -Dcan_fetch=YES -P /Users/kam/stuff/gamedev/axolotls/xcode/_deps/imgui-subbuild/imgui-populate-prefix/tmp/imgui-populate-gitupdate.cmake
fi

