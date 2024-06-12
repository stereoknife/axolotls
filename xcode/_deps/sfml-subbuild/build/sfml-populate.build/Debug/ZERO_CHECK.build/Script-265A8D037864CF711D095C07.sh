#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/kam/stuff/gamedev/axolotls/xcode/_deps/sfml-subbuild
  make -f /Users/kam/stuff/gamedev/axolotls/xcode/_deps/sfml-subbuild/CMakeScripts/ReRunCMake.make
fi

