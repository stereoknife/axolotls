#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/kam/stuff/gamedev/axolotls/xcode/_deps/imgui-sfml-src
  /opt/homebrew/Cellar/cmake/3.27.4/bin/cmake -Dcan_fetch=YES -P /Users/kam/stuff/gamedev/axolotls/xcode/_deps/imgui-sfml-subbuild/imgui-sfml-populate-prefix/tmp/imgui-sfml-populate-gitupdate.cmake
fi

