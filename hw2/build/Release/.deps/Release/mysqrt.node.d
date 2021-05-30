cmd_Release/mysqrt.node := ln -f "Release/obj.target/mysqrt.node" "Release/mysqrt.node" 2>/dev/null || (rm -rf "Release/mysqrt.node" && cp -af "Release/obj.target/mysqrt.node" "Release/mysqrt.node")
