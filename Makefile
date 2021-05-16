.DEFAULT_GOAL := fmt

.PHONY: fmt
fmt:
	clang-format -i **/*.cpp

.PHONY: install-formatter
install-formatter: 
	@echo : installing clang-format
	npm install -g clang-format

.PHONY: create-file
create-file:
	clang-format -style=llvm -dump-config > .clang-format
