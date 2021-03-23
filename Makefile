.PHONY: test clean

TEST_BUILD_DIR := test/build
SRC_BUILD_DIR := src/build

test: $(TEST_BUILD_DIR)
	set -x && cd $(TEST_BUILD_DIR) && cmake .. && make && ./m5stack-pixelart-test

$(TEST_BUILD_DIR):
	mkdir -p $(TEST_BUILD_DIR)

clean:
	rm -rf $(TEST_BUILD_DIR) && rm -rf $(SRC_BUILD_DIR)

src: $(SRC_BUILD_DIR)
	set -x && cd $(SRC_BUILD_DIR) && cmake .. && make

$(SRC_BUILD_DIR):
	mkdir -p $(SRC_BUILD_DIR)