FILE(REMOVE_RECURSE
  "CMakeFiles/hello.dir/main.o"
  "../bin/hello.pdb"
  "../bin/hello.exe"
  "../bin/libhello.dll.a"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang C)
  INCLUDE(CMakeFiles/hello.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
