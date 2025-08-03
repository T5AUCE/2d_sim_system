# CMakeList.txt : CMake project for 2d_sim_system, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("2d_sim_system")

# Add source to this project's executable.
add_executable (2d_sim_system "src/2d_sim_system.cpp" "src/2d_sim_system.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 2d_sim_system PROPERTY CXX_STANDARD 20)
endif()

# Add test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.17.0
)

