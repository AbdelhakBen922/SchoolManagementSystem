# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/tt_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/tt_autogen.dir/ParseCache.txt"
  "tt_autogen"
  )
endif()
