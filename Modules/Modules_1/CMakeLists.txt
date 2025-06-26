get_filename_component(PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
get_filename_component(NAMESPACE ${PARENT_DIR} NAME)
get_filename_component(TARGET_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# message( "PARENT DIR: ${PARENT_DIR}")
# message( "PARENT DIR: ${NAMESPACE}")
# message( "PARENT DIR: ${TARGET_NAME}")

option(${NAMESPACE}_${TARGET_NAME}_SHARED "target shared lib" ON)
configure_file(Export.h.in ${CMAKE_CURRENT_LIST_DIR}/Export.h @ONLY)

file(GLOB_RECURSE HEADER_FILES "*.h")
file(GLOB_RECURSE CPP_FILES "*.cpp")

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${HEADER_FILES} ${CPP_FILES})

if (${NAMESPACE}_${TARGET_NAME}_SHARED)
add_library(${TARGET_NAME} SHARED ${HEADER_FILES} ${CPP_FILES})
else()
add_library(${TARGET_NAME} STATIC ${HEADER_FILES} ${CPP_FILES})
endif()

add_library(${NAMESPACE}::${TARGET_NAME} ALIAS ${TARGET_NAME})#保证库内部可见
set_target_properties(${TARGET_NAME} PROPERTIES CXX_STANDARD 17)
set_targeT_properties(${TARGET_NAME} PROPERTIES FOLDER ${NAMESPACE}/${TARGET_NAME})


#find_package()

target_link_libraries(
    ${TARGET_NAME}
    PRIVATE
    # ""
)
target_include_directories(
    ${TARGET_NAME}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)


target_compile_definitions(
    ${TARGET_NAME}
    PRIVATE
    ${TARGET_NAME}_DLL_LIB_EXPORT
)
target_compile_definitions(
    ${TARGET_NAME}
    PUBLIC
    ${TARGET_NAME}_DLL_LIB
)

#TODO:??
install (TARGETS ${TARGET_NAME}
    EXPORT ${TARGET_NAME}
    INCLUDES DESTINATION include/${TARGET_NAME}
)

#如果有当前项目依赖的库，如glfw，可以使用这种方式：
#get_target_property(GLFW_DLL_FULLPATH glfw LOCATION)
#install(FILES "${GLFW_DLL_FULLPATH}" DESTINATION bin)

install(FILES ${HEADER_FILES} DESTINATION include/${NAMESPACE}/${TARGET_NAME})
#TODO: no need to copy cpp files
install(FILES ${CPP_FILES} DESTINATION include/${NAMESPACE}/${TARGET_NAME})

#todo: why?
install(EXPORT ${TARGET_NAME}
  DESTINATION cmake/${TARGET_NAME}
  FILE ${TARGET_NAME}-config.cmake
  NAMESPACE ${NAMESPACE}::
)