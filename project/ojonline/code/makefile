INCLUDE_PATH=-I /home/dev/third_part/include -I /usr/include/jsoncpp
LIB_PATH=-L /home/dev/third_part/lib -lctemplate -ljsoncpp -lpthread 

BIN = oj_svr 

$(BIN):oj_server.cpp
	g++ $^ -o $@ -g  $(INCLUDE_PATH) $(LIB_PATH)  -std=c++11 


.PHONY:clean
	clean:
	rm $(BIN)
