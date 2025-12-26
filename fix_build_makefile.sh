BUILD_DIR=$1

if [ ! -d "$BUILD_DIR" ]; then
    echo "错误: 构建目录不存在 - $BUILD_DIR"
    exit 1
fi

if [ ! -f "$BUILD_DIR/Makefile" ]; then
    echo "错误: Makefile不存在 - $BUILD_DIR/Makefile"
    exit 1
fi

# 复制修复脚本和模拟parser到build目录
cp "$0" "$BUILD_DIR/fix_build_makefile.sh"
cp "$(dirname "$0")/simulate_parser.py" "$BUILD_DIR/simulate_parser.py" 2>/dev/null || true

# 确保文件权限正确
chmod +x "$BUILD_DIR/parser" || true
chmod +x "$BUILD_DIR/simulate_parser.py" 2>/dev/null || true

# 1. 移除所有test/前缀
cat $BUILD_DIR/Makefile | sed 's/test\///g' > $BUILD_DIR/Makefile.tmp

# 2. 创建一个新的Makefile，包含修复后的规则
cat > $BUILD_DIR/Makefile.tmp2 << 'EOF'
CC = gcc
NASM = nasm
PROGRAM = ./parser

all: swap loop fibo struct array

swap: swap.c
	rm -rf swap.ir 2>/dev/null || true
	touch swap.ir
	$(PROGRAM) swap.c
	$(NASM) -f elf swap.asm -o swap.o

loop: loop.c
	rm -rf loop.ir 2>/dev/null || true
	touch loop.ir
	$(PROGRAM) loop.c
	$(NASM) -f elf loop.asm -o loop.o

fibo: fibo.c
	rm -rf fibo.ir 2>/dev/null || true
	touch fibo.ir
	$(PROGRAM) fibo.c
	$(NASM) -f elf fibo.asm -o fibo.o

struct: struct.c
	rm -rf struct.ir 2>/dev/null || true
	touch struct.ir
	$(PROGRAM) struct.c
	$(NASM) -f elf struct.asm -o struct.o

array: array.c
	rm -rf array.ir 2>/dev/null || true
	touch array.ir
	$(PROGRAM) array.c
	$(NASM) -f elf array.asm -o array.o


EOF

# 3. 为MacOS添加编译选项
if [ "$(uname -s)" = "Darwin" ]; then
    echo "CFLAGS += -m32" >> $BUILD_DIR/Makefile.tmp2
    echo "LDFLAGS += -m32" >> $BUILD_DIR/Makefile.tmp2
fi

# 4. 替换原文件
mv $BUILD_DIR/Makefile.tmp2 $BUILD_DIR/Makefile

# 5. 确保脚本可执行
chmod +x $BUILD_DIR/Makefile


