include(FetchContent)
FetchContent_Declare(
        gtest
        URL ${CMAKE_SOURCE_DIR}/3rdparty/gtest
)
# configure build of googletest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(gtest)

add_executable(unit_tests sub_test.cpp)

target_link_libraries(unit_tests sub sub2 gtest_main)

# automatic discovery of unit tests
include(GoogleTest)
gtest_discover_tests(unit_tests
  PROPERTIES
    LABELS "unit"
  DISCOVERY_TIMEOUT  # how long to wait (in seconds) before crashing
    240
  )
