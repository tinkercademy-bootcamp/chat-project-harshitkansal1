
BUILD_DIR = build
SRC_DIR = src

all: $(BUILD_DIR) $(BUILD_DIR)/server $(BUILD_DIR)/client

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

build/server: $(SRC_DIR)/tcp_echo_server.cc
	g++ $(SRC_DIR)/tcp_echo_server.cc -o $(BUILD_DIR)/server

build/client: $(SRC_DIR)/tcp_echo_client.cc
	g++ $(SRC_DIR)/tcp_echo_client.cc -o $(BUILD_DIR)/client

clean:
	rm -rf $(BUILD_DIR)	