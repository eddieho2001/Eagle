message(STATUS "game --> CMAKE_CURRENT_SOURCE_DIR : ${CMAKE_CURRENT_SOURCE_DIR}")
add_executable(${EAGLE_GAME_EXE_NAME} 
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/game.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/game.cpp
	
)

target_include_directories(${EAGLE_GAME_EXE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${EAGLE_GAME_EXE_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/${QUILL_LIB_NAME}/include)

#2. After fetch lib we also  need to setup the linking
target_link_libraries(${EAGLE_GAME_EXE_NAME} PUBLIC sfml-graphics)
target_link_libraries(${EAGLE_GAME_EXE_NAME} PUBLIC sfml-audio)
target_link_libraries(${EAGLE_GAME_EXE_NAME} PUBLIC sfml-main)
target_link_libraries(${EAGLE_GAME_EXE_NAME} PUBLIC sfml-network)
target_link_libraries(${EAGLE_GAME_EXE_NAME} PUBLIC sfml-system)
target_link_libraries(${EAGLE_GAME_EXE_NAME} PUBLIC sfml-window)
target_link_libraries(${EAGLE_GAME_EXE_NAME} PUBLIC quill::quill)

function(CopyLibToTarget LIB_NAME TARGET_NAME)
	add_custom_command(TARGET ${TARGET_NAME} 
	POST_BUILD
	COMMAND
	${CMAKE_COMMAND} -E copy_if_different
	$<TARGET_FILE:${LIB_NAME}>
	$<TARGET_FILE_DIR:${TARGET_NAME}>)
endfunction()

CopyLibToTarget(sfml-graphics ${EAGLE_GAME_EXE_NAME})
CopyLibToTarget(sfml-audio ${EAGLE_GAME_EXE_NAME})
CopyLibToTarget(sfml-main ${EAGLE_GAME_EXE_NAME})
CopyLibToTarget(sfml-network ${EAGLE_GAME_EXE_NAME})
CopyLibToTarget(sfml-system ${EAGLE_GAME_EXE_NAME})
CopyLibToTarget(sfml-window ${EAGLE_GAME_EXE_NAME})


