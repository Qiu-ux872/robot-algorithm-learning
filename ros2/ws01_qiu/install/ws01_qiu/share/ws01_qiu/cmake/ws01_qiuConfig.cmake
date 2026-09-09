# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_ws01_qiu_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED ws01_qiu_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(ws01_qiu_FOUND FALSE)
  elseif(NOT ws01_qiu_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(ws01_qiu_FOUND FALSE)
  endif()
  return()
endif()
set(_ws01_qiu_CONFIG_INCLUDED TRUE)

# output package information
if(NOT ws01_qiu_FIND_QUIETLY)
  message(STATUS "Found ws01_qiu: 0.0.0 (${ws01_qiu_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'ws01_qiu' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${ws01_qiu_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(ws01_qiu_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${ws01_qiu_DIR}/${_extra}")
endforeach()
