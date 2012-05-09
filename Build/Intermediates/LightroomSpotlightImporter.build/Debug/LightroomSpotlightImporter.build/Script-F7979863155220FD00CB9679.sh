#!/bin/sh
install_name_tool \
-change \
"@executable_path/../Frameworks/OmniBase.framework/Versions/A/OmniBase" \
"@loader_path/../Frameworks/OmniBase.framework/Versions/A/OmniBase" \
-change \
"@executable_path/../Frameworks/OmniFoundation.framework/Versions/A/OmniFoundation" \
"@loader_path/../Frameworks/OmniFoundation.framework/Versions/A/OmniFoundation" \
-change \
"@executable_path/../Frameworks/OmniSQLite.framework/Versions/A/OmniSQLite" \
"@loader_path/../Frameworks/OmniSQLite.framework/Versions/A/OmniSQLite" \
\
"$TARGET_BUILD_DIR/$EXECUTABLE_PATH"

install_name_tool \
-change \
"@rpath/OmniBase.framework/Versions/A/OmniBase" \
"@loader_path/../../../../Frameworks/OmniBase.framework/Versions/A/OmniBase" \
-change \
"@rpath/OmniFoundation.framework/Versions/A/OmniFoundation" \
"@loader_path/../../../../Frameworks/OmniFoundation.framework/Versions/A/OmniFoundation" \
"$TARGET_BUILD_DIR/$FRAMEWORKS_FOLDER_PATH/OmniSQLite.framework/Versions/A/OmniSQLite"

install_name_tool \
-change \
"@rpath/OmniBase.framework/Versions/A/OmniBase" \
"@loader_path/../../../../Frameworks/OmniBase.framework/Versions/A/OmniBase" \
"$TARGET_BUILD_DIR/$FRAMEWORKS_FOLDER_PATH/OmniFoundation.framework/Versions/A/OmniFoundation"
