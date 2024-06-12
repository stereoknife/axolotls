#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/kam/stuff/gamedev/axolotls/xcode/_deps/imgui-subbuild
  /opt/homebrew/Cellar/cmake/3.27.4/bin/cmake -E make_directory /Users/kam/stuff/gamedev/axolotls/xcode/_deps/imgui-subbuild/CMakeFiles/Debug
  /opt/homebrew/Cellar/cmake/3.27.4/bin/cmake -E touch /Users/kam/stuff/gamedev/axolotls/xcode/_deps/imgui-subbuild/CMakeFiles/Debug/imgui-populate-complete
  /opt/homebrew/Cellar/cmake/3.27.4/bin/cmake -E touch /Users/kam/stuff/gamedev/axolotls/xcode/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp/Debug/imgui-populate-done
fi

