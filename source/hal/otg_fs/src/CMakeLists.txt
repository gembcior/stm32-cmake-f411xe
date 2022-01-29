target_sources(otg_fs
  PRIVATE
    OtgFsCoreHal.cpp
    OtgFsDeviceHal.cpp
)

target_include_directories(otg_fs
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(otg_fs
  PRIVATE
    dral
)
