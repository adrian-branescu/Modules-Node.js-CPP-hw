cmd_Release/obj.target/hw2.node := g++ -o Release/obj.target/hw2.node -shared -pthread -rdynamic -m64  -Wl,-soname=hw2.node -Wl,--start-group Release/obj.target/hw2/src/mysqrt.o Release/obj.target/hw2/src/main.o -Wl,--end-group 
