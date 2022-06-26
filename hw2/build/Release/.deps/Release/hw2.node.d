cmd_Release/hw2.node := ln -f "Release/obj.target/hw2.node" "Release/hw2.node" 2>/dev/null || (rm -rf "Release/hw2.node" && cp -af "Release/obj.target/hw2.node" "Release/hw2.node")
