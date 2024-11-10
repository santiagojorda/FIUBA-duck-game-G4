.PHONY: all test clean editor client common server build

compile-debug:
	mkdir -p build/
	cmake -S . -B ./build -DCMAKE_BUILD_TYPE=Debug $(EXTRA_GENERATE)
	cmake --build  build/ $(EXTRA_COMPILE)

run-tests: compile-debug
	./build/taller_tests

all: clean run-tests

clean:
	rm -Rf build-*/


format: .clang-format
	find server -name "*.cpp" -o -name "*.h" -exec clang-format -i {} +
	find common -name "*.cpp" -o -name "*.h" -exec clang-format -i {} +
	find client -name "*.cpp" -o -name "*.h" -exec clang-format -i {} +
	echo fin
