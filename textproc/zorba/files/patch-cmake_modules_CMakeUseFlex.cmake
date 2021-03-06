--- cmake_modules/CMakeUseFlex.cmake.orig	2012-06-28 14:13:33.000000000 +0200
+++ cmake_modules/CMakeUseFlex.cmake	2012-06-28 14:15:36.000000000 +0200
@@ -30,7 +30,9 @@
 IF(NOT FLEX_EXECUTABLE)
   MESSAGE(STATUS "Looking for flex")
   FIND_PROGRAM(FLEX_EXECUTABLE flex)
-  IF(FLEX_EXECUTABLE)
+ENDIF(NOT FLEX_EXECUTABLE)
+
+IF(FLEX_EXECUTABLE)
     EXEC_PROGRAM(
             ${FLEX_EXECUTABLE}
             ARGS --version
@@ -44,13 +46,12 @@
     SET (FLEX_MAJOR_VERSION ${FLEX_MAJOR_VERSION_TMP} CACHE STRING "The flex major version" FORCE)
     SET (FLEX_MINOR_VERSION ${FLEX_MINOR_VERSION_TMP} CACHE STRING "The flex minor version" FORCE)
 	SET (FLEX_REVISION_VERSION ${FLEX_REVISION_VERSION_TMP} CACHE STRING "The flex revision version" FORCE)
-  ELSE (FLEX_EXECUTABLE)
+ELSE (FLEX_EXECUTABLE)
     SET (FLEX_MAJOR_VERSION "0")
     SET (FLEX_MINOR_VERSION "0")
 	  SET (FLEX_REVISION_VERSION "0")
-  ENDIF(FLEX_EXECUTABLE)
-  SET (FLEX_VERSION_FULL ${FLEX_MAJOR_VERSION}.${FLEX_MINOR_VERSION}.${FLEX_REVISION_VERSION} CACHE STRING "The Flex version" FORCE)
-ENDIF(NOT FLEX_EXECUTABLE)
+ENDIF(FLEX_EXECUTABLE)
+SET (FLEX_VERSION_FULL ${FLEX_MAJOR_VERSION}.${FLEX_MINOR_VERSION}.${FLEX_REVISION_VERSION} CACHE STRING "The Flex version" FORCE)
 
 IF(FLEX_EXECUTABLE)
   MACRO(FLEX_FILE FILENAME)
