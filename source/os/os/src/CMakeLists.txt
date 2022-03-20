target_sources(os
  PRIVATE
    Scheduler.cpp
    Task.cpp
    Mutex.cpp
)

target_include_directories(os
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(os
  PUBLIC
    freertos
)
