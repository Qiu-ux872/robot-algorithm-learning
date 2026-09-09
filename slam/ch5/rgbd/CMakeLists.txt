find_package(Sophus REQUIRED)

find_package(Pangolin REQUIRED)

add_executable(joinMap joinMap.cpp)
target_link_libraries(joinMap ${OpenCV_LIBS} ${Pangolin_LIBRARIES} Sophus::Sophus)