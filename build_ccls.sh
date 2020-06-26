#!/bin/bash
 
echo 'clang' > .ccls; cat .build/obj_gboards_gergoplex_default/cflags.txt | sed 's/ -/\n-/g' | sed 's/ //' | sed 's/ *$//' >> .ccls
