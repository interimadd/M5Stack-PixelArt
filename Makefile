.PHONY: test clean

TEST_BUILD_DIR := test/build

test: $(TEST_BUILD_DIR)
	set -x && cd $(TEST_BUILD_DIR) && cmake .. && make && ./m5stack-pixelart-test

$(TEST_BUILD_DIR):
	mkdir -p $(TEST_BUILD_DIR)

clean:
	rm -rf $(TEST_BUILD_DIR)