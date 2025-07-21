message(STATUS "Sub Project/Target Name : ${EAGLE_GAME_TARGET_NAME} --> CMAKE_CURRENT_SOURCE_DIR : ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "            Target Name : ${EAGLE_GAME_TARGET_NAME} --> Step 1 : Create excutable target named : [${EAGLE_GAME_TARGET_NAME}]")
add_executable(${EAGLE_GAME_TARGET_NAME} 
	${CMAKE_CURRENT_SOURCE_DIR}/include/game_framework/GameApplication.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/game_framework/GameApplication.cpp
)

message(STATUS "            Target Name : ${EAGLE_GAME_TARGET_NAME} --> Step 2 : Add  ${CMAKE_CURRENT_SOURCE_DIR}/include folder for include directory")
target_include_directories(${EAGLE_GAME_TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

#2. For the application, it not need to link the sfml libraries file again, it only linking the engine.lib is ok
message(STATUS "            Target Name : ${EAGLE_GAME_TARGET_NAME} --> Step 3 : Add all ${EAGLE_ENGINE_TARGET_NAME} libs for linking")
target_link_libraries(${EAGLE_GAME_TARGET_NAME} PUBLIC ${EAGLE_ENGINE_TARGET_NAME})

function(CopyLibDirToTarget LIB_NAME TARGET_NAME)
	add_custom_command(TARGET ${TARGET_NAME} 
	POST_BUILD
	COMMAND
	${CMAKE_COMMAND} -E copy_directory
	$<TARGET_FILE_DIR:${LIB_NAME}>
	$<TARGET_FILE_DIR:${TARGET_NAME}>)
endfunction()

message(STATUS "            Target Name : ${EAGLE_GAME_TARGET_NAME} --> Step 4 : Copy ${EAGLE_ENGINE_TARGET_NAME}.lib file for executable")
CopyLibDirToTarget(${EAGLE_ENGINE_TARGET_NAME} ${EAGLE_GAME_TARGET_NAME})



