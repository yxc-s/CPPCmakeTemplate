get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(TARGET_NAME ${PROJECT_NAME})
message("project name: ${TARGET_NAME}")

file(GLOB_RECURSE CPP_HEAD_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE CPP_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

message("source dir: ${CMAKE_SOURCE_DIR}")
source_group(
    TREE ${CMAKE_CURRENT_LIST_DIR} 
    FILES ${CPP_HEAD_FILES} ${CPP_SOURCE_FILES}
)

add_executable(${TARGET_NAME} ${CPP_SOURCE_FILES} ${CPP_HEAD_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES FOLDER Apps)

find_package(OpenCV)
#OSG是模块化的库，默认find_package不找到所有子模块，需要自己指定
find_package(OpenSceneGraph COMPONENTS osgUtil osgDB osgText osgGA osgFX osgSim osgViewer osgManipulator)

#TODO:跟OSG一样模块化加载？
find_package(CGAL)
if (CGAL_FOUND) 
    message(STATUS "CAGL version: ${CGAL_VERSION}")
    message(STATUS "CGAL include dirs: ${CGAL_INCLUDE_DIRS}")
    message(STATUS "CGAL libraries: ${CGAL_LIBRARIES}")
endif()

#使用CGAL时obj文件过大无法编译，需要增加下面的指令
# if (MSVC)
#     target_compile_options(${TARGET_NAME} PRIVATE /bigobj)
# endif()


target_include_directories(
    ${TARGET_NAME} 
    PRIVATE 
    # ${OpenCV_INCLUDE_DIRS}
    # ${OPENSCENEGRAPH_INCLUDE_DIRS}
    # ${CGAL_INCLUDE_DIRS}
)

target_link_libraries(
    ${TARGET_NAME} 
    PRIVATE 
    # ${OpenCV_LIBS}
    # ${OPENSCENEGRAPH_LIBRARIES}
    # ${CGAL_LIBRARIES}
)