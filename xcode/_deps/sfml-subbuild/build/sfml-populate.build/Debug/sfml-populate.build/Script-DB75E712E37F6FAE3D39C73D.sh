#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/kam/stuff/gamedev/axolotls/xcode/_deps
  /opt/homebrew/Cellar/cmake/3.27.4/bin/cmake -P /Users/kam/stuff/gamedev/axolotls/xcode/_deps/sfml-subbuild/sfml-populate-prefix/tmp/sfml-populate-gitclone.cmake
  /opt/homebrew/Cellar/cmake/3.27.4/bin/cmake -E touch /Users/kam/stuff/gamedev/axolotls/xcode/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp/Debug/sfml-populate-download
fi

