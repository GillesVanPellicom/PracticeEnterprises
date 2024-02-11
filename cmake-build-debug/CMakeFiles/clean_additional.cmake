# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/PracticeEnterprises_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/PracticeEnterprises_autogen.dir/ParseCache.txt"
  "PracticeEnterprises_autogen"
  )
endif()
