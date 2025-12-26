PROGRAM = parser
GRAMMARFOLDER = ./output/
BUILDFOLDER = build/
BUILDIO = build/io
NASM = nasm
BUILDIOEXIST = $(shell if [ -d $(BUILDIO) ]; then echo "exist"; else echo "notexist"; fi;)
GRAMMAREXIST = $(shell if [ -d $(GRAMMARFOLDER) ]; then echo "exist"; else echo "notexist"; fi;)
BUILDEXIST = $(shell if [ -d $(BUILDFOLDER) ]; then echo "exist"; else echo "notexist"; fi;)
DEPS = $(shell find ./ -name "*.h")
SRC = $(shell find ./common -name "*.cpp") ./output/grammar.tab.cpp ./output/lexer.flex.cpp
OBJ = $(SRC:%.cpp=%.o)
CXX = g++
FLEX = flex
BISON = bison
CXXVER = c++11
LEX_TOOL = generate_lexical_analysis
LEX_GEN = *.lex

$(PROGRAM): $(OBJ)
	$(CXX) -o $(PROGRAM) $(OBJ) -std=$(CXXVER) -g

# 词法分析工具构建规则
$(LEX_TOOL): generate_lexical_analysis.c
	$(CC) -o $(LEX_TOOL) generate_lexical_analysis.c

# 词法分析目标
lexical: $(LEX_TOOL) test_input.c
	./$(LEX_TOOL) test_input.c

# 为每个测试文件创建词法分析目标
%.lex: $(LEX_TOOL) $(BUILDFOLDER)%
	@echo "生成词法分析文件 $@..."
	./$(LEX_TOOL) $(BUILDFOLDER)$* $(BUILDFOLDER)$@

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
	rm -rf $(GRAMMARFOLDER)grammar.tab.cpp $(GRAMMARFOLDER)grammar.tab.h $(GRAMMARFOLDER)lexer.flex.cpp $(OBJ) $(PROGRAM) $(BUILDFOLDER) common/util/io/asm_io.o $(LEX_TOOL) $(LEX_GEN)

build: $(PROGRAM)
ifeq ($(BUILDEXIST),notexist)
	mkdir -p $(BUILDFOLDER)
endif
ifeq ($(BUILDIOEXIST),notexist)
	mkdir -p $(BUILDIO)
endif
	$(NASM) -f elf -d ELF_TYPE common/util/io/asm_io.asm -o common/util/io/asm_io.o
	cp $(PROGRAM) $(BUILDFOLDER)
	cp common/util/io/asm_io.o $(BUILDIO)
	cp common/util/io/asm_io.inc $(BUILDIO)
	cp -f test/*.c $(BUILDFOLDER)
	cp example/Makefile $(BUILDFOLDER)
	./fix_build_makefile.sh $(BUILDFOLDER)

# 目标规则引用，允许在根目录直接执行build目录中的目标
# 同时生成对应的词法分析文件
swap loop fibo struct array error: $(LEX_TOOL) build
	@echo "在build目录中执行 $@ 目标..."
	@cd $(BUILDFOLDER) && make $@
	@echo "生成 $@ 的词法分析文件..."
	./$(LEX_TOOL) $(BUILDFOLDER)$@.c $(BUILDFOLDER)$@.lex
