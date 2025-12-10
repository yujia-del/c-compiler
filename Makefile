PROGRAM = parser
GRAMMARFOLDER = ./output/yufa/
BUILDFOLDER = build/
BUILDIO = build/io
NASM = nasm
BUILDIOEXIST = $(shell if [ -d $(BUILDIO) ]; then echo "exist"; else echo "notexist"; fi;)
GRAMMAREXIST = $(shell if [ -d $(GRAMMARFOLDER) ]; then echo "exist"; else echo "notexist"; fi;)
BUILDEXIST = $(shell if [ -d $(BUILDFOLDER) ]; then echo "exist"; else echo "notexist"; fi;)
DEPS = $(shell find ./ -name "*.h")
SRC = $(shell find ./common -name "*.cpp") ./output/yufa/grammar.tab.cpp ./output/yufa/lexer.flex.cpp
OBJ = $(SRC:%.cpp=%.o)
CXX = g++
FLEX = flex
BISON = bison
CXXVER = c++11

$(PROGRAM): $(OBJ)
	$(CXX) -o $(PROGRAM) $(OBJ) -std=$(CXXVER) -g

grammar: lexer.l grammar.y
ifeq ($(GRAMMAREXIST),notexist)
	mkdir -p $(GRAMMARFOLDER)
endif
	$(BISON) --output="$(GRAMMARFOLDER)grammar.tab.cpp" --defines="$(GRAMMARFOLDER)grammar.tab.h" grammar.y
	$(FLEX) --outfile="$(GRAMMARFOLDER)lexer.flex.cpp" lexer.l
	echo '#include "common/trees.h"' > $(GRAMMARFOLDER)grammar.tab.h.tmp
	cat $(GRAMMARFOLDER)grammar.tab.h >> $(GRAMMARFOLDER)grammar.tab.h.tmp
	mv $(GRAMMARFOLDER)grammar.tab.h.tmp $(GRAMMARFOLDER)grammar.tab.h

%.o: %.cpp $(DEPS)
	$(CXX) -c $< -o $@ -std=$(CXXVER) -g -I.

clean:
	rm -rf $(GRAMMARFOLDER) $(OBJ) $(PROGRAM) $(BUILDFOLDER) common/util/io/asm_io.o

build:
ifeq ($(BUILDEXIST),notexist)
	mkdir -p $(BUILDFOLDER)
endif
ifeq ($(BUILDIOEXIST),notexist)
	mkdir -p $(BUILDIO)
endif
	# 使用32位ELF格式，确保汇编代码兼容
	$(NASM) -f elf -d ELF_TYPE common/util/io/asm_io.asm -o common/util/io/asm_io.o
	# 复制必要文件到build目录
	cp $(PROGRAM) $(BUILDFOLDER)
	cp common/util/io/asm_io.o $(BUILDIO)
	cp common/util/io/asm_io.inc $(BUILDIO)
	# 复制测试文件并确保正确复制到build目录根目录
	cp -f test/*.c $(BUILDFOLDER)
	# 复制Makefile到build目录
	cp example/Makefile $(BUILDFOLDER)
	# 使用专用脚本修复build目录的Makefile，处理路径引用和MacOS适配
	./fix_build_makefile.sh $(BUILDFOLDER)

# 目标规则引用，允许在根目录直接执行build目录中的目标
swap loop fibo struct array larra:
	@echo "在build目录中执行 $@ 目标..."
	@cd $(BUILDFOLDER) && make $@
