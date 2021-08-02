cmake_minimum_required (VERSION 3.10.2)

##### PLUGIN NAME #####
set(pluginname gipDropDownList)


##### PLUGIN PATHS #####
set(PLUGIN_DIR ${PLUGINS_DIR}/${pluginname})
set(PREBUILT_DIR ${PLUGIN_DIR}/prebuilts)


##### PLUGIN SOURCES #####
list(APPEND PLUGIN_SRCS
			${PLUGIN_DIR}/src/gipDropDownList.cpp
)


##### PLUGIN HEADERS #####
list(APPEND PLUGIN_INCLUDES
			${PLUGIN_DIR}/src
)


##### PLUGIN DEPENDENCY LOCATIONS (IF ANY) #####
if(WIN32)
	#Windows libs here
elseif(LINUX)
	#Linux libs here
elseif(APPLE)
	#Macos libs here
endif(WIN32)


##### PLUGIN DEPENDENCY LINKING (IF ANY) #####					
if(WIN32)
	list(APPEND PLUGIN_LINKLIBS
	)
elseif(LINUX)
	list(APPEND PLUGIN_LINKLIBS
	)
elseif(APPLE)
	list(APPEND PLUGIN_LINKLIBS
	)
endif(WIN32)