# Copyright (C) 2018 Istituto Italiano di Tecnologia (IIT). All rights reserved.
# This software may be modified and distributed under the terms of the
# GNU Lesser General Public License v2.1 or any later version.

yarp_prepare_plugin(xsens_mvn_remote TYPE yarp::dev::XsensMVNRemote
                                     INCLUDE XsensMVNRemote.h
                                     CATEGORY device
                                     ADVANCED
                                     DEFAULT ${XSENS_MVN_ENABLE_REMOTES})

if(ENABLE_xsens_mvn_remote)

  set(PLUGIN_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/XsensMVNRemote.cpp")
  set(PLUGIN_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/XsensMVNRemote.h")

  yarp_add_plugin(xsens_mvn_remote ${PLUGIN_SOURCES} ${PLUGIN_HEADERS})

  target_link_libraries(xsens_mvn_remote YARP::YARP_OS
                                         YARP::YARP_dev
                                         YARP::YARP_sig
                                         xsens_mvn_idl
                                         yarp_experimental)

  target_include_directories(xsens_mvn_remote SYSTEM PUBLIC ${YARP_INCLUDE_DIRS})
  target_include_directories(xsens_mvn_remote PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

  target_compile_features(xsens_mvn_remote PRIVATE cxx_lambdas)

  yarp_install(TARGETS xsens_mvn_remote
               COMPONENT runtime
               LIBRARY DESTINATION ${YARP_DYNAMIC_PLUGINS_INSTALL_DIR}
               ARCHIVE DESTINATION ${YARP_STATIC_PLUGINS_INSTALL_DIR})

  yarp_install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/conf/xsens_mvn_remote.ini"
               DESTINATION ${YARP_PLUGIN_MANIFESTS_INSTALL_DIR})

endif()
