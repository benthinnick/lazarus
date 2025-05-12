# Add test executable
set(TESTSOURCES
  test_main.cpp
  services/test_boardService.cpp
)
add_executable(test_main ${TESTSOURCES})

target_include_directories(test_main PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(test_main PRIVATE ${GTEST_LIBRARIES})

# Link your application libraries
target_link_libraries(test_main PRIVATE lazaruslib)

# Enable tests
include(GoogleTest)
gtest_discover_tests(test_main)
