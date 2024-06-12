#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/kam/stuff/gamedev/axolotls/xcode/_deps
  /opt/homebrew/Cellar/cmake/3.27.4/bin/cmake -P /Users/kam/stuff/gamedev/axolotls/xcode/_deps/imgui-sfml-subbuild/imgui-sfml-populate-prefix/tmp/imgui-sfml-populate-gitclone.cmake
  /opt/homebrew/Cellar/cmake/3.27.4/bin/cmake -E touch /Users/kam/stuff/gamedev/axolotls/xcode/_deps/imgui-sfml-subbuild/imgui-sfml-populate-prefix/src/imgui-sfml-populate-stamp/Debug/imgui-sfml-populate-download
fi

