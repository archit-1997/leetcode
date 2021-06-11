.DEFAULT_GOAL := cfmt

.PHONY: cfmt
cfmt:
	clang-format -i **/*.cpp

.PHONY : jfmt
jfmt:
	prettier --write **/*.java

.PHONY: install-formatter
install-formatter: 
	@echo : installing clang-format
	npm install -g clang-format

.PHONY: create-file
create-file:
	clang-format -style=llvm -dump-config > .clang-format
