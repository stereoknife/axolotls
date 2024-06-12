#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/kam/stuff/gamedev/axolotls/xcode/_deps/imgui-sfml-build
  /opt/homebrew/Cellar/cmake/3.27.4/bin/cmake -E echo_append
  /opt/homebrew/Cellar/cmake/3.27.4/bin/cmake -E touch /Users/kam/stuff/gamedev/axolotls/xcode/_deps/imgui-sfml-subbuild/imgui-sfml-populate-prefix/src/imgui-sfml-populate-stamp/Debug/imgui-sfml-populate-test
fi

